#include <bits/stdc++.h>
using namespace std;

void solve(){
  int n,m;
  cin>>n>>m;
  map<int,vector<int>>mp;
  set<int>s;
  for(int i=0;i<n;i++){
    int temp;
    cin>>temp;
    s.insert(temp);
    vector<int>v(m);
    v[0]=temp;
    for(int i=1;i<m;i++){
      cin>>v[i];
    }
    mp[temp]=v;
  }
  /// testing
  /*cout<<"set contains: ";
  for(int a:s){
    cout<<a<<" ";
  }                                // working correctly
  cout<<endl;
  // testing end*/
  int i;
  vector<vector<int>>cols(m,vector<int>(n));
  for(int j=0;j<m;j++){
    for(int k=0;k<n;k++){
      cin>>cols[j][k];
    }
  }

  for(i=0;i<m;i++){
    if(s.count(cols[i][0])) break;
  }
  for(int j=0;j<n;j++){
    for(int a:mp[cols[i][j]]){
      cout<<a<<" ";
    }
    cout<<endl;
  }
  /*for(int num:a){
    for(auto p:mp[a]){
      cout<<p<<" ";
    }
    cout<<endl;
  }*/

}

int main(){
  int t;
  cin>>t;
  while(t--){
    solve();
  }
}
