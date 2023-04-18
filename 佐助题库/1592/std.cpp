#include<bits/stdc++.h>
using namespace std;
char s1[]=" .in",s2[]=" .out";
int main(){
	srand((unsigned)time(0));
	for(int i=0;i<10;++i){
		s1[0]=s2[0]=(char)(i+'0');
		double n=rand()%1000+(double)rand()/32768,m=rand()%1000+(double)rand()/32768;
		freopen(s1,"w",stdout);
		cout<<n<<' '<<m<<endl;
		freopen(s2,"w",stdout);
		printf("%.2f\n",n+m);
	}
	return 0;
}
