#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 998244353

int main(){
  int n,k;
  cin>>n>>k;
  vector<int>a(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  ll sum=0;
  vector<int>pos;
  for(int i=0;i<n;i++){
    if(a[i]<=n && a[i]>n-k){
      sum+=a[i];
      pos.push_back(i);
    }
  }
  cout<<sum<<" ";
  ll temp,p=1;
  for(int j=0;j<pos.size()-1;j++){
    temp=pos[j+1]-pos[j];
    p=(p*temp)%mod;
  }

  cout<<p<<endl;

}
