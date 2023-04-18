#include<bits/stdc++.h>
using namespace std;
char s1[]=" .in",s2[]=" .out";
int a[1005];
bool check(long long x){
	for(long long i=2;i*i<=x;++i)if(x%i==0)return false;
	return true;
}
int main(){
	srand((unsigned)time(0));
	for(int i=0;i<=0;++i){
		s1[0]=s2[0]=(char)(i+'0');
		freopen(s1,"w",stdout);
		for(int j=1;j<=1000;++j){
			a[j]=rand()%100+1;
			printf("%d\n",a[j]);
		}
		printf("0\n");
		freopen(s2,"w",stdout);
		for(int j=1;j<=1000;++j){
			for(int k=1;k<=a[j];++k)printf("%d ",k);
			printf("\n");
		}
	}
	return 0;
}
