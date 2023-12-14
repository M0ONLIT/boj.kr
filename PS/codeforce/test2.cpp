#include<iostream>
#include<vector>

using namespace std;

bool visited[9]; //[9]
vector<int> v;
int n, m;
/*
bool check(int x)
{
    for(int i = 0; i<v.size(); i++)
        if(v[i] == x) return true;

    return false;
}
*/
void dfs(int x)
{
    v.push_back(x);

    if(m == v.size()){
        for(int i = 0; i<v.size(); i++) cout<<v[i]<<' ';
        cout<<'\n';
        v.pop_back();
        visited[x]=false; //fill(visited[x], visited[x]+9, false);
        return;
    }

    for(int i = 1; i<=n; i++)
    {
        if(!visited[i]) //if(!visited[x][i] && !check(i))
        {
            visited[i] = true;
            dfs(i);
            visited[i] = false; //추가
        }
    }
    //fill(visited[x], visited[x]+9, false);
    v.pop_back();
}

int main()
{
    cin>>n>>m;

    for(int i = 1; i<=n; i++)
    {
        visited[i] = true; //추가
        dfs(i);
        v.clear();
        visited[i] = false; //추가
        //for(int j = 1; j<=n; j++) fill(visited[j], visited[j]+9, false);
    }

    return 0;
}
