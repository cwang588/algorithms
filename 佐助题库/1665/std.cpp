#include<bits/stdc++.h>
using namespace std;
char s1[]=" .in",s2[]=" .out";
int a[7] = {100, 50, 20, 10, 5, 2, 1};
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
		int a=rand()%10+1,b=rand()%10000+1,c=rand()%10000+1;
		printf("RANDOM\n%d.00\n%d.00\n",b,c);
		freopen(s2,"w",stdout);
		printf("TOTAL = R$ %.2lf", (double)b + (double)c * 0.15);
	}
	return 0;
}	
