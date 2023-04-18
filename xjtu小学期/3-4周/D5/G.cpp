#include<bits/stdc++.h>
#define LL long long
#define mod 1000000007
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define INF 0x3f3f3f3f
using namespace std;
 
const int N = 1e6 + 10;
 
set<int> ans;
int n,m,a[N],s[N],p[N];
 
void manacher()
{
    int len=2*n-1;
    for(int i=len;i>=0;--i)
        s[i+i+1]=s[i],s[i+i]=-1;
    int id,mx=0;
    for(int i=1;i<len+len+1;++i)
    {
        if (mx>i) p[i]=min(p[2*id-i],mx-i); else p[i]=1;
        while(s[i-p[i]]==s[i+p[i]]&&i-p[i]>=0&&i+p[i]<len+len+1)++p[i];
        if(i+p[i]>mx) id=i,mx=p[i]+i;
    }
}
int main()
{
   	scanf("%d%d",&n,&m);
    if (n==1)
    {
        int tt; 
		scanf("%d",&tt);
        return !printf("1\n%d",2*tt%m);
    }
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
        s[i-1]=(a[i%n]-a[i-1]+m)%m;
    for(int i=n;i<2*n-1;i++) s[i]=s[i-n];
    manacher();
    for(int i=2;i<4*n;i+=2)
        if (p[i]/2>=n/2&&(a[(i/2-1)%n]+a[(i/2+1)%n])%m==a[(i/2)%n]*2%m) ans.insert(2*a[(i/2)%n]%m);
    if (n%2==0)
        for(int i=1;i<4*n;i+=2)
        {
            if (p[i]>=n) ans.insert((a[(i/2)%n]+a[(i/2+1)%n])%m);
        }
    printf("%d\n",ans.size()); int t=0;
    for(auto i:ans)
    {
        t++;
        printf("%d%c",i," \n"[t==ans.size()]);
    }
    return 0;
}

