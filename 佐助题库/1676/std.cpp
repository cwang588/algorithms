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
		int n=rand()%2500,b=rand()%24,c=rand()%10+1;
		printf("%d.00\n",n);
		freopen(s2,"w",stdout);
		double a=(double)n;
		double x,y,z;
		if(a>0&&a<=400.00)
    {
        x=a*1.15;
        y=a*0.15;
        z=15;
    }
    else
    if(a>400.01&&a<=800.00)
    {
        x=a*1.12;
        y=a*0.12;
        z=12;
    }
    else
    if(a>800.01&&a<=1200.00)
    {
        x=a*1.1;
        y=a*0.1;
        z=10;
    }
    else
    if(a>1200.01&&a<=2000.00)
    {
        x=a*1.07;
        y=a*0.07;
        z=7;
    }
    else
    if(a>2000.00)
    {
        x=a*1.04;
        y=a*0.04;
        z=4;
    }
    cout<<"Novo salario: "<<fixed<<setprecision(2)<<x<<endl;
    cout<<"Reajuste ganho: "<<fixed<<setprecision(2)<<y<<endl;
    cout<<"Em percentual: "<<int(z)<<" %"<<endl;
	}
	return 0;
}
