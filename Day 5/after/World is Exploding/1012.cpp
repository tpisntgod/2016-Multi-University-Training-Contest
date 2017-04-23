#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<vector>
#include <ctime>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<iomanip>
#include<cmath>
#include<bitset>
#define mst(ss,b) memset((ss),(b),sizeof(ss))
///#pragma comment(linker, "/STACK:102400000,102400000")
typedef long long ll;
typedef long double ld;
#define INF (1ll<<60)-1
#define Max 1e9
using namespace std;
int n,m;
int a[50010],b[50010];
int num[50010];
int mn[50010],mx[50010];   /// 分别表示[1,i-1]有多少个数比ai小  大
int hmn[50010],hmx[50010]; /// 分别表示[i+1,n]有多少个数比ai小  大
int lowbit(int x){
    return x&-x;
}
void Add(int x){
    while(x<=m) {
        num[x]++;
        x+=lowbit(x);
    }
}
int query(int x){
    int ans=0;
    while(x>=1){
        ans+=num[x];
        x-=lowbit(x);
    }
    return ans;
}
ll sum[50010];
int main(){
    while(scanf("%d",&n)!=EOF){
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),b[i]=a[i];
        sort(b+1,b+n+1);
        m=unique(b+1,b+n+1)-(b+1);
        for(int i=1;i<=n;i++) 
		    a[i]=lower_bound(b+1,b+m+1,a[i])-b;
        mst(num,0);
        mst(sum,0);
        for(int i=1;i<=n;i++){
            mn[i]=query(a[i]-1);
            mx[i]=query(m)-query(a[i]);
            sum[i]=sum[i-1]+mn[i]*1LL;
            Add(a[i]);
            //printf("%d %d\n",mn[i],mx[i]);
        }
        mst(num,0);
        for(int i=n;i>=1;i--){
            hmn[i]=query(a[i]-1);
            hmx[i]=query(m)-query(a[i]);
            Add(a[i]);
            //printf("%d %d\n",hmn[i],hmx[i]);
        }
        ll ans=0;
        for(int i=1;i<=n;i++){
            ll num1=1LL*mx[i];
            ll num2=1LL*sum[n];
            ans+=num1*num2;
        }
        /// a=c b!=d
        for(int i=1;i<=n;i++){
            ll num1=hmn[i];
            ll num2=hmx[i];
            ans-=num1*num2;
        }
        /// a=d b!=c
        for(int i=1;i<=n;i++){
            ll num1=mx[i];
            ll num2=hmx[i];
            ans-=num1*num2;
        }
        /// b=c a!=d
        for(int i=1;i<=n;i++){
            ll num1=mn[i];
            ll num2=hmn[i];
            ans-=num1*num2;
        }
        /// b=d a!=c
        for(int i=1;i<=n;i++){
            ll num1=mx[i];
            ll num2=mn[i];
            ans-=num1*num2;
        }
        printf("%I64d\n",ans);
    }
    return 0;
}

