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
	int n;
	cin>>n;
		for(int j=1;j<=n;++j){
			int now=min(2*j-1,2*(n+1-j)-1);
			for(int k=1;k<=n;++k){
				if(k>(n-now)/2&&k<=(n-now)/2+now)printf("*");
				else printf(" ");
			}
			printf("\n");
		}
	return 0;
}
