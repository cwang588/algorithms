#include<bits/stdc++.h>
using namespace std;
char s1[]=" .in",s2[]=" .out";
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
		int a=rand()%100+1,b=rand()%100+1;
		printf("%d %d\n",a,b);
		freopen(s2,"w",stdout);
		if(a%b==0||b%a==0)printf("Sao Multiplos\n");
		else printf("Nao sao Multiplos\n");
	}
	return 0;
}
