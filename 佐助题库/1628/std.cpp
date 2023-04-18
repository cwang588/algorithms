#include<bits/stdc++.h>
using namespace std;
char s1[]=" .in",s2[]=" .out";
int a[1005];
bool check(long long x){
	for(long long i=2;i*i<=x;++i)if(x%i==0)return false;
	return true;
}
int main(){
	srand((unsigned)time(0));
	for(int i=0;i<=9;++i){
		s1[0]=s2[0]=(char)(i+'0');
		freopen(s1,"w",stdout);
		int n=rand()%1000+3;
		printf("%d\n",n);		
		freopen(s2,"w",stdout);
		int cnt=0;
		for(int j=1;j<=10;++j){
			printf("%d x %d = %d\n",j,n,j*n);
		}
	}
	return 0;
}
