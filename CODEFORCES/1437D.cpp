#include <bits/stdc++.h>
using namespace std;

void solve(){
  int n;
  cin>>n;
  vector<int>v(n);
  for(int i=0;i<n;i++){
    cin>>v[i];
  }

  int lvl;
  queue<int>q;
  q.push(v[0]);
  int i=1;
  for(lvl=0;!q.empty() && i<n;lvl++){
    int sz=q.size();
    while(sz--){
        int cur=q.front();
        q.pop();
        q.push(v[i]);
        i++;

        while(v[i-1]<=v[i] && i<n){
          q.push(v[i]);
          i++;
        }

    }
  }
  cout<<lvl<<endl;
}

int main(){
  int t;
  cin>>t;
  while(t--){
    solve();
  }
}
