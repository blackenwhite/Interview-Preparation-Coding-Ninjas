#include <bits/stdc++.h>
#define LL long long

using namespace std;
int main(){
	int x,n,l=0,r=1000;
	cin>>n>>x;
	for (int a,b;cin>>a>>b;){
		if (a>b) swap(a,b);
		l=max(l,a);
		r=min(r,b);
	}
	cout<<(l>r?-1:l<=x && r>=x?0:l>x?l-x:x-r)<<endl;
}
