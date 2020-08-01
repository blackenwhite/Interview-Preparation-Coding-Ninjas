// author:nabajyoti majumdar
#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  string a,b;
  cin>>a;
  cin>>b;
  vector<int>to(n);
  for(int i=0;i<n;i++){
    to[i]=(b[i]-a[i])*2;
  }

  int ans=0;
  for(int i=0;i<n;i++){
    if(to[i]){
      if(to[i]+to[i+1]==0){
        to[i]=0;
        to[i+1]=0;
        ans++;
      }else{
        to[i]=0;
        ans++;
      }
    }

  }
  cout<<ans<<endl;
}
