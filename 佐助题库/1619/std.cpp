#include<bits/stdc++.h>
using namespace std;
char s1[]=" .in",s2[]=" .out";
long long a[105],b[105];
bool check(long long x){
	for(long long i=2;i*i<=x;++i)if(x%i==0)return false;
	return true;
}
int main(){
	srand((unsigned)time(0));
	for(int i=0;i<=9;++i){
		s1[0]=s2[0]=(char)(i+'0');
		freopen(s1,"w",stdout);
		int n=100;
		printf("%d\n",n);
		for(int j=1;j<=n;++j){
			a[j]=rand()*rand()%99999999+2;
			cout<<a[j]<<"\n";
		}
		freopen(s2,"w",stdout);
		for(int j=1;j<=n;++j){
			cout<<a[j]<<" ";
			cout<<"is ";
			if(!check(a[j]))printf("not ");
			printf("prime\n");
		}
	}
	return 0;
}
