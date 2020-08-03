#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define ll long long

int main(){
  int n,m;
  cin>>n>>m;
  vector<int> v(n+1);
  for(int i=1;i<=n;i++){
    cin>>v[i];
  }
  vector<vector<int>>mat(n+1,vector<int>(n+1,0));
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    mat[a][b]=v[a];
    mat[b][a]=v[b];

  }

  ll ans=0;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      if(i==j) continue;
      if(mat[i][j]!=0){
        ans+=min(mat[i][j],mat[j][i]);
        mat[i][j]=0;
        mat[j][i]=0;
      }
    }
  }
  cout<<ans<<endl;
}
