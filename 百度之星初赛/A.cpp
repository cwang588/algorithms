#include<bits/stdc++.h>
using namespace std;
double b[100005],c[100005];
int tmp[1005];
bool cmp(int x,int y)
{
	return b[x]*(1-c[y]+b[y])<b[y]*(1-c[x]+b[x]);
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n; 
		for(int i=1;i<=n;++i)cin>>b[i]>>c[i],tmp[i]=i;
		sort(tmp+1,tmp+1+n,cmp);
		int now=tmp[1];
		printf("%.5f\n",(1-c[now])/(1-c[now]+b[now]));
	}
	return 0;
} 
