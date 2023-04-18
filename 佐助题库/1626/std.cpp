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
		int n=rand()%100+3;
		printf("%d\n",n);		
		freopen(s2,"w",stdout);
		for(int j=1;j<=10000;++j){
			if(j%n==2)printf("%d\n",j);
		}
	}
	return 0;
}
