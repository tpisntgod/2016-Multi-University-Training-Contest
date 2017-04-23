#include<iostream>
#include<algorithm>
#include<cstring>
typedef long long ll;
typedef long double ld;

using namespace std;
int n,m;
int a[50010],b[50010];
int num[50010];
int mn[50010],mx[50010];
int hmn[50010],hmx[50010];
ll sum[50010];
int lowbit(int x){
	return x&-x;
}
void Add(int x){
	while (x<=m){
		num[x]++;
		x+=lowbit(x);
	}
}
int query(int x){
	int s=0;
	while(x){
		s+=num[x];
		x-=lowbit(x);
	}
	return s;
}
int main(){
	while (scanf("%d",&n)!=EOF){
		for (int i=1;i<=n;i++) scanf("%d",&a[i]),b[i]=a[i];
		sort(b+1,b+1+n);
		m=unique(b+1,b+1+n)-(b+1);
		for (int i=1;i<=n;i++)
		    a[i]=lower_bound(b+1,b+m+1,a[i])-b;
		memset(num,0,sizeof(num));
		memset(sum,0,sizeof(sum));
		for (int i=1;i<=n;i++){
			mn[i]=query(a[i]-1);
			mx[i]=query(m)-query(a[i]);
			sum[i]=sum[i-1]+mn[i]*1LL;
			Add(a[i]);
		}
		memset(num,0,sizeof(num));
		for (int i=n;i>=1;i--){
			hmn[i]=query(a[i]-1);
			hmx[i]=query(m)-query(a[i]);
			Add(a[i]);			
		}
		ll ans=0;
		for (int i=1;i<=n;i++)
			ans+=(ll) sum[n]*(ll) mx[i];
		for (int i=1;i<=n;i++){
		    ans-=(ll)hmx[i]*(ll)hmn[i];
		    ans-=(ll)hmx[i]*(ll)mx[i];
		    ans-=(ll)mn[i]*(ll)hmn[i];
		    ans-=(ll)mn[i]*(ll)mx[i];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
