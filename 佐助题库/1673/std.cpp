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
		int n=rand()%20000;
		printf("%.2f\n",(double)n/100.0);
		freopen(s2,"w",stdout);
		double a=n/100.0;
		if (a>=0&&a<=25)
	    printf("Intervalo [%d,%d]",0,25);
	    else if (a>25&&a<=50)
	    printf("Intervalo (%d,%d]",25,50);
	    else if (a>50&&a<=75)
	    printf("Intervalo (%d,%d]",50,75);
	    else if (a>75&&a<=100)
	    printf("Intervalo (%d,%d]",75,100);
	    else 
	    printf("Fora de intervalo");
	}
	return 0;
}
