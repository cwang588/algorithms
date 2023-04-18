#include<bits/stdc++.h>
using namespace std;
char s1[]=" .in",s2[]=" .out";
int a[1005],b[1005];
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
		int n=rand()%100+3;
		printf("%d\n",n);
		int cnt=0;
		for(int j=1;j<=n;++j){
			a[j]=rand()*rand()%10000000+90000000;
			printf("%d\n",a[j]);
		}		
		freopen(s2,"w",stdout);
		for(int j=1;j<=n;++j){
			if(a[j]==33550336)printf("%d is perfect\n",a[j]);
			else printf("%d is not perfect\n",a[j]);
		}
	}
	return 0;
}
