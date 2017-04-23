#include <cstdio>
#include <cstring>

void init() {
	int sg[107];
	int vis[107];
	sg[0]=0; sg[1]=1;
	for (int i=2;i<=100;i++) {
		memset(vis,0,sizeof(vis));
		for (int j=1;j<i;j++)
		    for (int k=1;j+k<i;k++)
		        vis[sg[j]^sg[k]^sg[i-j-k]]=1;
		for (int j=0;j<i;j++)
		    vis[sg[j]]=1;
		int j;
		for (j=0;j<=i;j++) if (vis[j]==0) break;
		sg[i]=j;
	}
	for (int i=1;i<=100;i++)
	    printf("%d %d\n",i,sg[i]);
}

int sg(int x) {
	if (x%8==0) return x-1;
	if (x%8==7) return x+1;
	return x;
}
int main() {
	int t,n;
	//init();
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		int j,k=0;
		for (int i=1;i<=n;i++) {
		    scanf("%d",&j);
		    k=k^sg(j);
		}
		if (k) printf("First player wins.\n");
		else printf("Second player wins.\n");
    }
	return 0;
}
