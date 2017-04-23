#include<cstdio>
#include<iostream>

using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	char s[100007];
	while(t--) {
		int n,l=0,p=1,k=0,fr,ll;
		char c;
		scanf("%d",&n);
		scanf("%s",&s);
		if (n==2 && s[0]=='(' && s[1]==')') {
			printf("No\n");
			continue;
		}
		for (int i=0;i<n;i++)
			if (s[i]==')') {
				fr=i;
				break;
			}
		for (int j=n-1;j>=0;j--)
			if (s[j]=='(') {
				ll=j;
				break;
			}
		s[fr]='(';
		s[ll]=')';
		for (int i=0;i<n;i++) {
			if (s[i]=='(') l++; else l--;
			if (l<0) {
				p=0;
				break;
			}
		}
		if (p && l==0) printf("Yes\n");
			else printf("No\n");
	}
}
