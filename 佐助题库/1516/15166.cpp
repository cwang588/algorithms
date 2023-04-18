#include<bits/stdc++.h>
using namespace std;
long long a[100005];
int main()
{
	freopen("in.in","r",stdin);
//	freopen("out9.out","w",stdout);
    int n,m;
    cin>>m>>n;
    for(int i=0;i<m;i++)cin>>a[i];
    sort(a,a+m);
    long long ans=0;
    for(int i=0;i<n;i++)
    {
        long long x;
        cin>>x;
        int idx = lower_bound(a,a+m,x)-a;
        if(idx==m)ans+=x-a[m-1];
        else
        if(idx==0)ans+=a[0]-x;
        else
        if(a[idx]!=x)
        ans+=min(a[idx]-x,x-a[idx-1]);
    }
    cout<<ans;
    return 0;
}
