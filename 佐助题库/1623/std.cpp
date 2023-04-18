#include<bits/stdc++.h>
using namespace std;
char s1[]=" .in",s2[]=" .out";
long long a[105],b[105];
bool check(long long x){
	for(long long i=2;i*i<=x;++i)if(x%i==0)return false;
	return true;
}
int main(){
	srand((unsigned)time(0));
	for(int i=0;i<=9;++i){
		s1[0]=s2[0]=(char)(i+'0');
		freopen(s1,"w",stdout);
		int n=rand()%200-100,m=rand()%200-100;
		printf("%d\n%d\n",n,m);
		freopen(s2,"w",stdout);
		int cnt=0;
		for(int j=min(n,m)+1;j<=max(n,m)-1;++j)if(j%2)cnt+=j;
		printf("%d\n",cnt);
	}
	return 0;
}
