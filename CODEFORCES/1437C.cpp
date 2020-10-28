#include <bits/stdc++.h>
using namespace std;
#define N 205
int dp[N][2*N];
vector<int>v;
int n;

int foo(int idx,int t){
  if(idx==n) return 0;
  if(t==2*n+1) return 1e7;
  if(dp[idx][t]!=-1) return dp[idx][t];
  int ans=INT_MAX;
  ans=min(ans,foo(idx,t+1));
  ans=min(ans, abs(t-v[idx]) + foo(idx+1,t+1) );
  dp[idx][t]=ans;
  return ans;
}

void solve(){

  cin>>n;
  v.resize(n);
  for(int i=0;i<n;i++){
    cin>>v[i];
  }

  for(int i=0;i<N;i++){
    for(int j=0;j<2*N;j++){
      dp[i][j]=-1;
    }
  }
  sort(v.begin(),v.end());
  cout<<foo(0,1)<<endl;

}

int main(){
  int q;
  cin>>q;
  while(q--){
    solve();
  }
}
