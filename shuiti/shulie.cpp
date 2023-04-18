#include<bits/stdc++.h>
using namespace std;
int main()
{
	int B;
	cin>>B;
	if(B<0)
	cout<<"A*B";
	if(B==0)
	cout<<"A*B B*C";
	if(B>0)
	cout<<"B*C"; 
	return 0;
}
