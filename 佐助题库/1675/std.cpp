#include<bits/stdc++.h>
using namespace std;
char s1[]=" .in",s2[]=" .out";
char db[]={'C','R','F'};
bool check(long long x){
	for(long long i=2;i*i<=x;++i)if(x%i==0)return false;
	return true;
}
int main(){
	srand((unsigned)time(0));
	for(int i=0;i<=9;++i){
		s1[0]=s2[0]=(char)(i+'0');
		freopen(s1,"w",stdout);	
		int a=rand()%24,b=rand()%24,c=rand()%10+1;
		printf("%d %d\n",a,b);
		freopen(s2,"w",stdout);
		if(b<a) b+=24;
	    if(a==b) cout<<"O JOGO DUROU 24 HORA(S)"<<endl;
	    else if(a<b) cout<<"O JOGO DUROU "<<b-a<<" HORA(S)"<<endl;
	}
	return 0;
}
