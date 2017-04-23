#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

struct data{
	int k;
	int i;
} a[1007];
int cmp(const data& x,const data& y) {
	return x.k<y.k;
}
int main() {
	int t,n,ca=0,s;
	scanf("%d",&t);
	while(t--) {
		int p=1;
		s=0;
		ca++;
		scanf("%d",&n);
		for (int i=0;i<n;i++) {
			scanf("%d",&a[i].k);
			s+=a[i].k;
			a[i].i=i+1;
		}
		sort(a,a+n,cmp);
		for (int i=0;i<n;i++)
			if (a[i].k>i) {
				printf("Case #%d: No\n",ca);
				p=0;
				break;
			}
		if (p) {
			printf("Case #%d: Yes\n",ca);
			printf("%d\n",s);
			for (int i=1;i<n;i++) {
				int k=0,l=0;
				if (a[i].k>0)
				for (int j=0;j<i;j++) {
					printf("%d %d\n",a[i].i,a[j].i);
					k++;
					if (k>=a[i].k) break;
				}
			}
		}
	}
}
