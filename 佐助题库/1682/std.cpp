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
		int a=rand()%24,b=rand()%60,c=rand()%24,d=rand()%60;
		printf("%d %d %d %d\n",a,b,c,d);
		freopen(s2,"w",stdout);
		b+=a*60,d+=c*60;
    a=(d-b+24*60)%(24*60);
    a=(a)?(a):(24*60);
    printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n",a/60,a%60);
	}
	return 0;
}
