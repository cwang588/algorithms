#include<bits/stdc++.h>
using namespace std;
void jiaohuan(int &x,int &y)
{
	int t=x;
	x=y;
	y=t;
	return; 
}
int main()
{
	int a,b;
	cin>>a>>b;
	jiaohuan(a,b);
	cout<<a<<' '<<b<<endl;
	swap(a,b);
	cout<<a<<' '<<b<<endl;
	return 0;
}
