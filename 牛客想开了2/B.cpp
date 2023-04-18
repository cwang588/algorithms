#include<bits/stdc++.h>
#define ll long long
using namespace std;
int p[20] = {0,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,51};
ll ans,n;
void dfs(int pos,ll num,ll sum,int len)
{
    if (sum>n) 
		return;
    if (sum<=n) 
		ans=max(ans,num);
    for (int i=1;i<=len;i++) 
	{
        ll res=pow(p[pos],i);
        if (sum>n/res)
			break;
        dfs(pos+1,num*(i+1),sum*(res),i);

    }

}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
    	cin>>n;
    	ans=0;
    	dfs(1,1,1,30);
    	cout<<ans<<endl;
    }
    return 0;

}

