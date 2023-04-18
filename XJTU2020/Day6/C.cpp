#include<bits/stdc++.h>
using namespace std;
long long f[100005],t[100005];
int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	for(int Case=1;Case<=T;++Case)
	{
		int n;
		long long S;
		cin>>n>>S;
		for(int i=1;i<=n;++i)cin>>f[i]>>t[i];
		long long MaxHappy=0,MaxSave=-2147483647;
		for(int i=1;i<=n;++i)
		{
			if(t[i]<=S)MaxSave=max(MaxSave,f[i]);
			else if(t[i]<=S+t[i])MaxSave=max(MaxSave,f[i]-t[i]+S);
//			if(t[i]<=S)
//			{
//				if(MaxHappy==S)MaxSave=max(MaxSave,f[i]);
//				else 
//				{
//					MaxHappy=s;
//					MaxSave=f[i];
//				}
//			}
//			else 
//			{
//				if(MaxHappy==t[i]-S)MaxSave=()
//			}
		}
		cout<<"Case #"<<Case<<": "<<MaxSave<<endl; 
	}
	return 0;
}
