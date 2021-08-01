void ipgraph(int n, int m){
  int i, u, v;
  while(m--){
    cin>>u>>v;
    g[u].pb(v);
    g[v].pb(u);
  }
}

void dfs(int u, int par){
  for(int v:g[u]){
    if (v == par) continue;
    dfs(v, u);
  }
}