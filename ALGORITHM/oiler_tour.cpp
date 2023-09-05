int s[100005], e[100005];
vector<int> tree[100005];

void dfs(int node){
  s[node]=++ptr;
  for(int i: tree[node])
    dfs(i);
  e[node]=ptr;
}
