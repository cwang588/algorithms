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
		int a=rand()*rand()%20000-10000;
		int b=rand()*rand()%20000-10000;
		int c=rand()*rand()%20000-10000;
		int d=rand()*rand()%20000-10000;
		printf("%d %d %d %d\n",a,b,c,d);
		freopen(s2,"w",stdout);
		printf("%d\n",a*b-c*d);
	}
	return 0;
}
