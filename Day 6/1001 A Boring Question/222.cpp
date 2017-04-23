#include <cstdio>
#include <cmath>
#define MAX 100005
#define mod 1000000007

using namespace std;

long long multi(long long a, long long b)//������
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

long long exgcd(long long a, long long b, long long &x, long long &y)//��չŷ�����
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
        long long d =  exgcd(m - 1, mod, x, y);//������mod��λ����дmod * (m - 1),���ռ���ʱ��Ҫ��x��mod������d
        x *= mul;
        x /= d;//��Ϊm - 1��mod�ǻ��ʵģ�������ȥ����
        x = (x % mod + mod) % mod;//��ֹ���ս��Ϊ����
        printf("%lld\n", x);
    }
    return 0;
}
