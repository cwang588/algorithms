#include<bits/stdc++.h>
using namespace std;
char s1[]=" .in",s2[]=" .out";
int main(){
	srand((unsigned)time(0));
	for(int i=0;i<10;++i){
		s1[0]=s2[0]=(char)(i+'0');
		int n=rand()%201-100;
		freopen(s1,"w",stdout);
		cout<<n<<endl;
		freopen(s2,"w",stdout);
		cout<<abs(n)<<endl;
	}
	return 0;
}
