#include<iostream> 
using namespace std;
int main()
{
	int a,b,c,d,ans1,ans2,t1,t2;
	char t;
	cin>>a>>t>>b>>c>>t>>d;
	ans1=a*c;
	ans2=b*d;
	if(ans1>ans2) 
	{
		t1=ans1;
		t2=ans2;
	}
	else
	{
		t1=ans2;
		t2=ans1;
	} 
	while(t2!=0)
	{
		int tt=t1;
		t1=t2;
		t2=tt%t2;
	}
	ans1/=t1;
	ans2/=t1;
	cout<<ans2<<' '<<ans1;
	return 0;
}
