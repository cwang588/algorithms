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
		int n=rand()%1000000+1,b=rand()%10000+1,c=rand()%10000+1;
		printf("%d\n",n);
		freopen(s2,"w",stdout);
		printf("%d ano(s)\n",n/365);    //先除后余的贪心
	    printf("%d mes(es)\n",n%365/30); 
	    // cout << n % 365 % 30 << " dia(s)" << endl;
	    printf("%d dia(s)\n",n=n%365%30);
	}
	return 0;
}
