//nabajyoti majumdar
#include <bits/stdc++.h>
using namespace std;

int main(){
  int q;
  cin>>q;
  while(q--){
    int n;
    cin>>n;
    unordered_set<int> s;
    for(int i=2;i*i<=n;i++){
      if(n%i==0 && s.count(i)==0){
        s.insert(i);
        n/=i;
        break;
      }
    }

    for(int i=2;i*i<=n;i++){
      if(n%i==0 && s.count(i)==0){
        s.insert(i);
        n/=i;
        break;
      }
    }

    if(s.size()<2 || s.count(n)||n==1){
      cout<<"NO"<<endl;

    }else{
      cout<<"YES"<<endl;
      s.insert(n);
      for(auto i:s){
        cout<<i<<" ";
      }
      cout<<endl;
    }
  }
}
