#include<bits/stdc++.h>
using namespace std;
char s1[]=" .in",s2[]=" .out";
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
long long a[1005];
int main(){
	a[1]=a[0]=1;
	for(int i=2;i<=30;++i)a[i]=a[i-1]+a[i-2];
	srand((unsigned)time(0));
	for(int i=0;i<15;++i){
		s1[0]=s2[0]=(char)(i+'0');
		int n=i+1;
		freopen(s1,"w",stdout);
		cout<<n<<endl;
		freopen(s2,"w",stdout);
		cout<<a[n]<<endl;
	}
	return 0;
}
