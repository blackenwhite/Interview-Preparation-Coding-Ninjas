#include <bits/stdc++.h>
using namespace std;

void solve(){
  int n;
  cin>>n;
  vector<int>a(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
  }

  vector<int>b(n);
  for(int i=0;i<n;i+=2){
    b[i+1]=a[i];
    b[i]=-a[i+1];
  }
  for(int i=0;i<n;i++){
    cout<<b[i]<<" ";
  }
  cout<<endl;
}

int main(){
  int t;
  cin>>t;
  while(t--){
    solve();
  }
}
