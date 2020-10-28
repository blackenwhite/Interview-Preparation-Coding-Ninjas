#include <bits/stdc++.h>
using namespace std;

void solve(){
  int n;
  cin>>n;
  string s;
  cin>>s;
  int c=0;
  for(int i=0;i<n-1;i++){
    if(s[i]==s[i+1]) c++;
  }
  cout<<ceil(c/2.0)<<endl;
}

int main(){
  int t;
  cin>>t;
  while(t--){
    solve();
  }
}
