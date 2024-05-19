#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
#define ioset() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
typedef pair<int, int> pii;

int n, m;
struct person{
    int atk, def, idx;
};
vector<person> fri, enemy;
vector<pii> LOG;
int modok(){
    int i, j;
    vector<pii> v={{0, 0}}; //0:아군, 1:적군
    for(auto i: fri)
        if(i.def>0) v.push_back({i.def, 0});
    for(auto i: enemy)
        if(i.def>0) v.push_back({i.def, 1});
    sort(v.begin(), v.end());
    for(i=0; i<v.size()-1; i++){
        if(v[i+1].first-v[i].first>1) break;
    }
    for(j=i+1; j<v.size(); j++){
        if(v[j].second) return 0;
    }
    return 1;
}

int dfs(int idx){
    if(idx==n){
        return modok();
    }
    if(dfs(idx+1)) return 1;
    for(int i=0; i<m; i++){
        if(enemy[i].def>0){
            enemy[i].def-=fri[idx].atk;
            fri[idx].def-=enemy[i].atk;
            LOG.push_back({idx, i});
            if(dfs(idx+1)) return 1;
            enemy[i].def+=fri[idx].atk;
            fri[idx].def+=enemy[i].atk;
            LOG.pop_back();
        }
    }
    return 0;
}

bool comp(person x, person y){
    return x.atk<y.atk;
}

int main() {
    ioset();
    int i;
    cin>>n>>m;
    for(i=0; i<n; i++){
        person p;
        cin>>p.atk>>p.def;
        p.idx=i+1;
        fri.push_back(p);
    }
    sort(fri.begin(), fri.end(), comp);
    for(i=0; i<m; i++){
        person p;
        cin>>p.atk>>p.def;
        p.idx=i+1;
        enemy.push_back(p);
    }
    sort(enemy.begin(), enemy.end(), comp);
    if(dfs(0)){
        cout<<LOG.size()+1<<'\n';
        for(pii p: LOG){
            cout<<"attack "<<fri[p.first].idx<<' '<<enemy[p.second].idx<<'\n';
        }
        cout<<"use modok";
    }
    else cout<<-1;
}
