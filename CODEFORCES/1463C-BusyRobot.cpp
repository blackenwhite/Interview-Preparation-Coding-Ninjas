#include <bits/stdc++.h>
using namespace std;
#define ll long long

//const int N=100005;

bool inside(ll l,ll r,ll x){
    if(x>=min(l,r) && x<=max(l,r)) return true;
    return false;
}

ll sg(ll x){
    if(x<0) return -1;
    if(x==0) return 0;
    return 1;
}

void solve(){
    ll n;
    cin>>n;
    vector<ll>T(n+1,4e9),X(n+1,0);
    for(int i=0;i<n;i++){
        cin>>T[i]>>X[i];
    }

    // q[n][0]=INT_MAX-5;
    // q[n][1]=0;

    int ans=0;
    ll pos=0,dr=0,lft=0;

    for(int i=0;i<n;i++){
        ll t=T[i];
        ll x=X[i];
        ll tn=T[i+1];

        if(lft==0){
            lft=abs(pos-x);
            dr=sg(x-pos);
        }

        ll tmp=min(lft,tn-t);
        if(inside(pos,(pos+dr*tmp),x)){
            ans++;
        }
        pos+=(dr*tmp);
        lft-=tmp;
    }
    cout<<ans<<endl;
}

int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    //return 0;
}
