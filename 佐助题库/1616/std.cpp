#include<bits/stdc++.h>
using namespace std;
char s1[]=" .in",s2[]=" .out";
int a[105],b[105];
int main(){
	srand((unsigned)time(0));
	for(int i=0;i<=9;++i){
		s1[0]=s2[0]=(char)(i+'0');
		freopen(s1,"w",stdout);
		int n=rand()%20+1,m=rand()%20+1;
		printf("%d %d\n",n,m);
		freopen(s2,"w",stdout);
		for(int j=1;j<=n;++j){
			for(int k=1;k<m;++k)printf("%d ",(j-1)*m+k);
			printf("PUM\n");
		}
	}
	return 0;
}
