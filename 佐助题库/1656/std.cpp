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
	for(int i=0;i<=9;++i){
		s1[0]=s2[0]=(char)(i+'0');
		freopen(s1,"w",stdout);	
		int n=rand()%100+1,m=rand()%200,x=rand()%50+1;
		printf("%d\n%d\n%d.00\n",n,m,x);
		freopen(s2,"w",stdout);
		printf("NUMBER = %d\nSALARY = U$ %d.00\n",n,m*x);
	}
	return 0;
}	
