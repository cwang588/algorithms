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
		int a=rand()%20,b=rand()%20,c=rand()%20;
		if(a<b)swap(a,b);
		if(a<c)swap(a,c);
		printf("%d %d %d\n",a,b,c);
		freopen(s2,"w",stdout);
		if (a < b) swap(a, b);
    if (a < c) swap(a, c);
    if (b < c) swap(b, c);

    if (a >= b + c) 
        cout << "NAO FORMA TRIANGULO" << endl;
    else
    {
        if (a * a == b * b + c * c) 
            cout << "TRIANGULO RETANGULO" << endl;
        if (a * a > b * b + c * c)
            cout << "TRIANGULO OBTUSANGULO" << endl;
        if (a * a < b * b + c * c) 
            cout << "TRIANGULO ACUTANGULO" << endl;
        if (a == b && a == c) 
            cout << "TRIANGULO EQUILATERO" << endl;
        if ((a == b && a != c && b != c) || (a == c && a != b && c != b)|| (b == c && b != a && c != a)) 
            cout << "TRIANGULO ISOSCELES" << endl;
    }

	}
	return 0;
}
