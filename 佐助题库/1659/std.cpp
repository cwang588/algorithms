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
		int n=rand()*rand()%1000000+1;
		printf("%d\n",n);
		freopen(s2,"w",stdout);
		printf("%d\n", n);
	    for (int i = 0; i < 7; i ++ )
	    {
	        printf("%d nota(s) de R$ %d,00\n", n / a[i], a[i]);
	        n %= a[i];
	    }
	}
	return 0;
}	
