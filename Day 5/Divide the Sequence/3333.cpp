#include <bits/stdc++.h>
#define ALL(v) (v).begin(),(v).end()
#define showtime printf("time = %.15f\n",clock() / (double)CLOCKS_PER_SEC)

const int N = 1000000 + 5;
int n;
int A[N];

int work() {
    int ret = 0;
    for (int i = n - 1,j = i; i >= 0; i = j) {
        long long sum = A[i];
        for (j = i - 1; j >= 0 && sum < 0; sum += A[j--]);
        ret ++;
    }
    return ret;
}

int main() {
    while (scanf("%d",&n) == 1) {
        for (int i = 0; i < n; ++ i) {
            scanf("%d",A + i);
        }
        printf("%d\n",work());
    }
}
