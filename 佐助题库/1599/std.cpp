#include<bits/stdc++.h>
using namespace std;
char s1[]=" .in",s2[]=" .out";
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
int a[1005];
bool usd[1005];
char tmp[10005];
int main(){
	srand((unsigned)time(0));
	for(int i=0;i<10;++i){
		s1[0]=s2[0]=(char)(i+'0');
		int n=1000,l=rand()%n+1,r=rand()%n+1;
		if(l>r)swap(l,r);
		freopen(s1,"w",stdout);
		cout<<n<<' '<<l<<' '<<r<<endl;
		for(int j=1;j<=n;++j){
			a[j]=rand();
			cout<<a[j]<<' ';
		}
		cout<<endl;
		freopen(s2,"w",stdout);
		sort(a+l,a+r+1);
		for(int i=1;i<=n;++i)cout<<a[i]<<' ';
		cout<<endl;
	}
	return 0;
}
