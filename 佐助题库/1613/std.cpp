#include<bits/stdc++.h>
using namespace std;
char s1[]=" .in",s2[]=" .out";
double a[105][105];
int main(){
	srand((unsigned)time(0));
	for(int i=0;i<=9;++i){
		s1[0]=s2[0]=(char)(i+'0');
		freopen(s1,"w",stdout);
		int A=rand()%100+1;
		printf("%d ",A);
		int N=rand()%201-100;
		printf("%d ",N);
		while(N<=0){
			N=rand()%201-100;
			printf("%d ",N);
		}
		printf("\n");
		freopen(s2,"w",stdout);
		int tot=0;
		for(int j=0;j<N;++j)tot+=j+A;
		printf("%d\n",tot);
	}
	return 0;
}
