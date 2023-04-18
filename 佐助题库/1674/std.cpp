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
		int a=rand()%10+1,b=rand()%10+1,c=rand()%10+1;
		printf("%d %d %d\n",a,b,c);
		freopen(s2,"w",stdout);
		if(a+b>c && fabs(a-b)<c) printf("Perimetro = %.1lf",(double)(a+b+c));
    	else printf("Area = %.1lf",(double)(a+b)*c/2);
	}
	return 0;
}
