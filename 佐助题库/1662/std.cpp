#include<bits/stdc++.h>
using namespace std;
char s1[]=" .in",s2[]=" .out";
int a[7] = {100, 50, 20, 10, 5, 2, 1};
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
		int a=rand()%10000+1,b=rand()%10000+1,c=rand()%10000+1;
		printf("%d.0 %d.0 %d.0\n",a,b,c);
		freopen(s2,"w",stdout);
		cout.setf(ios_base::fixed);
	    cout.precision(3);
	    cout<<"TRIANGULO: "<<(double)a*c*0.5<<endl;
	    cout<<"CIRCULO: "<<3.14159*(double)c*c<<endl;
	    cout<<"TRAPEZIO: "<<(double)(a+b)*c/2<<endl;
	    cout<<"QUADRADO: "<<(double)b*b<<endl;
	    cout<<"RETANGULO: "<<(double)a*b;
	}
	return 0;
}	
