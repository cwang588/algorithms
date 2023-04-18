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
		int n=rand()%5000+1,b=rand()%60,c=rand()%24,d=rand()%60;
		printf("%d\n",n);
		freopen(s2,"w",stdout);
		double a=(double)n;
		if(a>0&&a<=2000.0) cout<<"Isento";
	    else if(a>2000.0&&a<=3000) printf("R$ %.2lf",(a-2000)*0.08);
	    else if(a>3000.0&&a<=4500) printf("R$ %.2lf",(a-3000)*0.18+80);
	    else if(a>4500.0) printf("R$ %.2lf",(a-4500)*0.28+350);
	}
	return 0;
}
