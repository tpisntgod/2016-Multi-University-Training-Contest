#include <cstdio>
#include <cmath>
#define MAX 100005
#define mod 1000000007

using namespace std;

long long multi(long long a, long long b)//快速幂
{
    long long ret = 1;
    while(b > 0)
    {
        if(b & 1)
            ret = (ret * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ret;
}

long long exgcd(long long a, long long b, long long &x, long long &y)//扩展欧几里得
{
    if(!b)
    {
        x = 1;
        y = 0;
        return a;
    }
    long long d = exgcd(b, a % b, x, y);

    long long tmp = x;
    x = y;

    return d;
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        long long n, m, x, y;
        scanf("%lld %lld", &n, &m);
        long long mul = (multi(m, n + 1) - 1) % mod;
        long long d =  exgcd(m - 1, mod, x, y);//若这里mod的位置填写mod * (m - 1),最终计算时需要让x和mod都除以d
        x *= mul;
        x /= d;//因为m - 1和mod是互质的，这句可以去掉。
        x = (x % mod + mod) % mod;//防止最终结果为负数
        printf("%lld\n", x);
    }
    return 0;
}
