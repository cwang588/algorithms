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
		int n=rand()%50+1;
		printf("%d\n",n);
		freopen(s2,"w",stdout);
		a[0]=n;
		for(int j=0;j<10;++j){
			printf("N[%d] = %d\n",j,a[j]);
			a[j+1]=a[j]*2;
		}
	}
	return 0;
}
