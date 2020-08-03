#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>

bool compare(pii a,pii b){
  if(a.first==b.first){
    return a.second<b.second;
  }
  return a.first<b.first;
}

int main(){
  int n;
  cin>>n;
  vector<pii> a(n);
  for(int i=0;i<n;i++){
    cin>>a[i].first>>a[i].second;
  }
  sort(a.begin(),a.end(),compare);
  int lastexam=-1;
  for(int i=0;i<n;i++){
    if(lastexam<=a[i].second){
      lastexam=a[i].second;
    }else{
      lastexam=a[i].first;
    }
    //cout<<lastexam<<endl;
  }
  cout<<lastexam<<endl;
}
