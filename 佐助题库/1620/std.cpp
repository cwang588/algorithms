#include<bits/stdc++.h>
using namespace std;
char s1[]=" .in",s2[]=" .out";
long long a[105],b[105];
bool check(long long x){
	for(long long i=2;i*i<=x;++i)if(x%i==0)return false;
	return true;
}
int main(){
	freopen("1.out","w",stdout);
	for(int i=2;i<=100;i+=2)printf("%d\n",i);
	return 0;
}
