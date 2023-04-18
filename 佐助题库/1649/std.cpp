#include<bits/stdc++.h>
using namespace std;
char s1[]=" .in",s2[]=" .out";
int a[100][105],b[1005];
char db[]={'C','R','F'};
bool check(long long x){
	for(long long i=2;i*i<=x;++i)if(x%i==0)return false;
	return true;
}
int main(){
	srand((unsigned)time(0));
	for(int i=0;i<=0;++i){
		s1[0]=s2[0]=(char)(i+'0');
		freopen(s1,"w",stdout);	
		for(int j=1;j<=100;++j)printf("%d\n",j);
		printf("0\n");
		freopen(s2,"w",stdout);
		for(int n=1;n<=100;++n){
			for(int j=1;j<=n;++j){
				for(int k=1;k<=n;++k){
					printf("%d ",1+abs(j-k));
				}
				printf("\n");
			}
			printf("\n");
		}
	}
	return 0;
}
