#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

ll power(ll a,ll p){
	if(p==0)	return 1;
	ll x=a,res=1;
	while(p>0){
		if(p&1){
			res=(res*x)%mod;
		}
		x=(x*x)%mod;
		p>>=1;
	}
	return res%mod;
}

int main(){
	ios::sync_with_stdio(false) , cin.tie(0) , cout.tie(0) ;
	int n,k;
	cin>>n>>k;
	ll q=power(2,n-1);
	ll qi=power(q,mod-2);
	ll p=((q-n)+mod)%mod;
	ll ans=(p*qi)%mod;
	cout<<ans;
return 0;
}

