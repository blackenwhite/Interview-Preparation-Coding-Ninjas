#include <bits/stdc++.h>
using namespace std;
#define ll long long

void dfs(int i,vector<int>&v,int& mini,vector<int>& visited,vector<vector<int>>&adj){
  if(visited[i]) return;
  visited[i]=1;
  mini=min(mini,v[i]);
  for(int j=0;j<adj[i].size();j++){
    dfs(adj[i][j],v,mini,visited,adj);
  }
}


int main(){
  int n,m;
  cin>>n>>m;
  vector<int>v(n+1);
  for(int i=1;i<=n;i++){
    cin>>v[i];
  }

  vector<vector<int>> adj(n+1);
  int x,y;
  for(int i=0;i<m;i++){
    cin>>x>>y;
    adj[x].push_back(y);
    adj[y].push_back(x);

  }
  vector<int>visited(n+1,0);
  ll ans=0;
  for(int i=1;i<=n;i++){
    if(visited[i]) continue;
    int mini=v[i];
    dfs(i,v,mini,visited,adj);
    ans+=mini;
  }
  cout<<ans<<endl;
}
