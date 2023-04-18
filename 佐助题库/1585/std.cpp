#include<bits/stdc++.h>
using namespace std;
char s1[]=" .in",s2[]=" .out";
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
int main(){
	srand((unsigned)time(0));
	for(int i=0;i<10;++i){
		s1[0]=s2[0]=(char)(i+'0');
		int x=rand()%1000+1,y=rand()%1000+1; 
		freopen(s1,"w",stdout);
		cout<<x<<' '<<y<<endl;
		freopen(s2,"w",stdout);
		cout<<gcd(x,y)<<endl;
	}
	return 0;
}
