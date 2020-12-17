#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void solve(){
  int n;
  cin>>n;
  vector<ll>a(n);
  ll sum=0;
  for(int i=0;i<n;i++){
    cin>>a[i];
    sum+=a[i];
  }

  for(int i=n;i>=1;i--){
    if(sum%i==0){
      ll needSum=sum/i;
      ll curSum=0;
      bool ok=true;
      for(int j=0;j<n;j++){
        curSum+=a[j];
        if(curSum>needSum){
          ok=false;
          break;
        }else if(curSum==needSum){
          curSum=0;
        }
      }
      if(ok){
        cout<<n-i<<endl;
        return;
      }
    }
  }
}

int main(){
  int t;
  cin>>t;
  while(t--){
    solve();
  }
}
