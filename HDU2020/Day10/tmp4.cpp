#include <iostream>
#include <cstring>
using namespace std;
int dp(int x,int y)
{
	if(x==0)
		return 1;
	if(y==0)
		return 0;
	if(x==y)
		return (1+dp(x,y-1));
	if(x<y)
		return dp(x,x);
	if(x>y)
		return dp(x,y-1)+dp(x-y,y);
}
int main()
{
	int n,m;
	cin>>m>>n;
	cout<<dp(m,n)<<endl;
	return 0;
}
