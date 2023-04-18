#include<bits/stdc++.h>
using namespace std;
int l,n,m,Left,Right,mid,now,i,a[50005],s,ans;
int main()
{
    cin>>n>>m>>l;
    for(i=1;i<=n;i++)
        cin>>a[i]; 
    Left=0;Right=l;
    while(Left<=Right)
	{
        mid=(Right+Left)/2;
        now=0;s=0;
        for(i=1;i<=n;i++)
		{
            if(a[i]-a[now]<mid)
                s++;
            else now=i;
		}
        if(s<=m)
		{
            ans=mid;
            Left=mid+1;
		}
        else 
			Right=mid-1;
	}
    cout<<ans;
    return 0;
}
