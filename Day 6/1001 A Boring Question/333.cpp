#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <vector>
#define LL long long
#define mid(a,b) ((a+b)>>1)
#define eps 1e-8
#define maxn 2100
#define mod 1000000007
#define inf 0x3f3f3f3f
#define IN freopen("in.txt","r",stdin);
using namespace std;

LL x,y,gcd;
void ex_gcd(LL a,LL b)
{
    if(!b) {x=1;y=0;gcd=a;}
    else {ex_gcd(b,a%b);LL temp=x;x=y;y=temp-a/b*y;}
}

LL quickmod(LL a,LL b,LL m) {
    LL ans = 1;
    while(b){
        if(b&1){
            ans = (ans*a)%m;
            b--;
        }
        b/=2;
        a = a*a%m;
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    //IN;

    int t; cin >> t;
    LL n, m;
    while(scanf("%I64d %I64d", &n,&m) != EOF)
    {
        LL ans1 = quickmod(m, n+1, 1000000007LL) - 1;
        LL ans2 = m - 1;

        ex_gcd(ans2, 1000000007LL);
        while(x < 0) {
            x+=1000000007LL;
            y-=ans2;
        }

        LL ans = (ans1 * x) % mod;

        printf("%I64d\n", ans);
    }

    return 0;
}
