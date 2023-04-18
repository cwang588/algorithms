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
		int n=rand()+1,m=rand(),x=rand(),y=rand();
		printf("%d.0 %d.0\n%d.0 %d.0\n",n,m,x,y);
		freopen(s2,"w",stdout);
		printf("%.4f\n",sqrt((n-x)*(n-x)+(m-y)*(m-y)));
	}
	return 0;
}	
