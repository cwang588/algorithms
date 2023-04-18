#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[55];
bool isPrime(int x)
{
	if(x==1)return false;
	for(int i=2;i*i<=x;++i)
		if(x%i==0)
			return false;
	return true;
}
int ans;
void dfs(int now,int num,int tot)//now:当前序号 num:已经选的数字个数 tot:已经选择的数字和 
{
	if(num==k)
	{
		if(isPrime(tot)==true)++ans;
		return;
	}
	if(now>n)return;
	dfs(now+1,num,tot);//不选当前数
	dfs(now+1,num+1,tot+a[now]); //选当前数 
}
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;++i)cin>>a[i];
	dfs(1,0,0);
	cout<<ans<<endl;	
	return 0;
} 
