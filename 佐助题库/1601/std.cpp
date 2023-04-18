#include<bits/stdc++.h>
using namespace std;
char s1[]=" .in",s2[]=" .out";
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
long long a[105][105];
int main(){
	a[1][1]=1;
	for(int i=1;i<=10;++i){
		for(int j=1;j<=10;++j){
			if(i!=1||j!=1){
				a[i][j]=a[i-1][j]+a[i][j-1];
			}
		}
	}
	srand((unsigned)time(0));
	for(int i=0;i<15;++i){
		s1[0]=s2[0]=(char)(i+'0');
		int n=rand()%5+1,m=rand()%5+1;
		freopen(s1,"w",stdout);
		cout<<n<<' '<<m<<endl;
		freopen(s2,"w",stdout);
		cout<<a[n][m]<<endl;
	}
	return 0;
}
