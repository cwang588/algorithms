#include <bits/stdc++.h>
using namespace std;
int v[1000005],t[1000005],f[1000005];
int main()
{
	int T,m,xx;
	while(cin>>m>>T>>xx)
	{
		memset(v,0,sizeof(v)); 
		memset(t,0,sizeof(v)); 
		memset(f,0,sizeof(v)); 
		for(int i=1;i<=m;i++)
			cin>>t[i];
		for(int i=1;i<=m;i++)
			cin>>v[i];
		for(int i=1;i<=m;i++)
			for(int j=T;j>=t[i];j--)
				f[j]=max(f[j],f[j-t[i]]+v[i]);	
		if(f[T]>=xx)
			printf("Baoqian\n");
		else
			printf("Niyingle\n");	
	}	
	return 0;
}
