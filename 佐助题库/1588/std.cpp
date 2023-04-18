#include<bits/stdc++.h>
using namespace std;
char s1[]=" .in",s2[]=" .out";
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
int a[1005][1005];
int main(){
	srand((unsigned)time(0));
	for(int i=0;i<10;++i){
		s1[0]=s2[0]=(char)(i+'0');
		int n=100,m=rand()%100+1; 
		freopen(s1,"w",stdout);
		cout<<n<<' '<<m<<endl;
		for(int j=1;j<=n;++j){
			for(int k=1;k<=m;++k){
				a[j][k]=rand();
				cout<<a[j][k]<<' ';
			}
			cout<<endl;
		}	
		cout<<endl;
		freopen(s2,"w",stdout);
		for(int j=1;j<=n;++j){
			for(int k=1;k<=m;++k){
				cout<<a[j][k]<<' ';
			}
			cout<<endl;
		}
	}
	return 0;
}
