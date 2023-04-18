#include<iostream>
using namespace std;
int main()
{
//	int a,b;
//	cin>>a>>b;
//	if(a>b)
//	{
//		cout<<a;
//	}
//	else if(a<b)
//	{
//		cout<<b;
//	}
//	else
//	{
//		cout<<"heng!";
//	}
	int i=1,tot=0;
//	while(i<=100)
//	{
//		tot+=i;//tot=tot+i;
//		++i;
//	}
	for(i=1;i<=100;++i)
	{
		tot+=i;
	}
	cout<<tot;
	return 0;
}
