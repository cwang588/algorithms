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
		int x=rand()%5+1,y=rand()%100+1;
		printf("%d %d\n",x,y);
		freopen(s2,"w",stdout);
		double price[6] = {0, 4, 4.5, 5, 2, 1.5};
	    printf("Total: R$ %.2f", price[x] * y);
	}
	return 0;
}
