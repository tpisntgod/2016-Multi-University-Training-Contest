#include<cstdio>
#include<iostream>
#define ll long long

using namespace std;

ll gcd(ll x,ll y) {
	if (y==0) return x;
	return gcd(y,x%y);
}
int main() {
	ll n,m;
	ll a,b,c;
	while(scanf("%lld%lld",&n,&m)) {
		if (n==0 && m==0) break;
		if (m==1) {
			printf("0/1\n");
			continue;
		}
		a=n*(m-1);
		b=m*m;
		c=gcd(a,b);
		printf("%lld/%lld\n",a/c,b/c);
	}
}
