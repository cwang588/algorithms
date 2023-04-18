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
			a[j]=rand()%1000-500;
			b[j]=rand()%1000-500;
			printf("%d %d\n",a[j],b[j]);
		}		
		freopen(s2,"w",stdout);
		for(int j=1;j<=n;++j){
			int tot=0;
			for(int k=min(a[j],b[j])+1;k<=max(a[j],b[j])-1;++k)if(k%2)tot+=k;
			printf("%d\n",tot);
		}
	}
	return 0;
}
