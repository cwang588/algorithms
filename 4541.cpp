#include<bits/stdc++.h>
using namespace std;
bool judge(int x)//判断x是否是质数 
{
	if(x==1)
		return false;
	for(int i=2;i*i<=x;++i)
		if(x%i==0)
			return false;
	return true; 
} 
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;++i)
		if(judge(i)==true)
     		cout<<i<<' ';
	return 0;
}
