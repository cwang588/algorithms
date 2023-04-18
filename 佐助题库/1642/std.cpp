#include<bits/stdc++.h>
using namespace std;
char s1[]=" .in",s2[]=" .out";
long long a[100],b[1005];
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
		printf("61\n");
		for(int j=0;j<=60;++j)printf("%d\n",j);
		freopen(s2,"w",stdout);
		a[0]=0,a[1]=1;
		printf("Fib(0) = 0\nFib(1) = 1\n");
		for(int j=2;j<=60;++j){
			a[j]=a[j-1]+a[j-2];
			printf("Fib(%d) = %lld\n",j,a[j]);
		}
	}
	return 0;
}
