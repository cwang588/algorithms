#include<bits/stdc++.h>
using namespace std;
void digit(long n,long m)   
{
	if(m>0)cout <<setw(2)<<n%10;
	if(m>1)digit(n/10,m/10);
	cout <<setw(2)<<n%10;
} 
int main()
{
	long x,x2;
	cout <<"Input a number:"<<endl; 
	cin >>x;
	x2=1;
	while(x2<x)x2*=10;   
	x2/=10;   
	digit(x,x2);
	cout <<endl; 
}
