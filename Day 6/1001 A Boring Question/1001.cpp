#include <cstdio>

#define mod 1000000007
typedef long long ll;

ll egcd(ll a,ll b,ll & x,ll & y) {
	if (b==0) {
		x=1;
		y=0;
		return a;
	}
	ll r=egcd(b,a%b,y,x);
	y-=x*(a/b);
	return r;
}
ll pow(ll x,ll y) {
	if (y==1) return x;
	ll k=pow(x,y/2);
	k=k*k%mod;
	if (y%2==1) k=k*x%mod;
	return k;
}
int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		ll n,m,x,y;
		scanf("%lld%lld",&n,&m);
		ll k=pow(m,n+1)-1;
		egcd(m-1,mod,x,y);
		//if (x<0) x+=mod;
		k=((k*x) % mod + mod) %mod;
		printf("%lld\n",k);
	}
}
