#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 2e7+10;
const int MAX = 5e5+100;
int prime[MAXN],mark[MAXN];
int tot,phi[MAXN];
ll btree[MAX];
int n;
ll a[MAX];
void getphi(int N)
{
    phi[1]=1;
    tot=0;
    for(int i=2;i<=N;i++)
    {
        if(!mark[i])
        {
            prime[++tot]=i;
            phi[i]=i-1;
        }

        for(int j=1;j<=tot;j++)

        {

            if(i*prime[j]>N) break;

            mark[i*prime[j]]=1;

            if(i%prime[j]==0)

            {

                phi[i*prime[j]]=phi[i]*prime[j];

                break;

            }

            else
				phi[i*prime[j]]=phi[i]*(prime[j]-1);
        }

    }

}

 

inline int lowbit(int x)

{

    return x&(-x);

}

 

void add(int l,ll x)  //区间更新

{

    for(int i=l;i<=n;i+=lowbit(i))

    {

        btree[i]+=x;

    }

}

 

ll query(int l) 
{
    ll sum=0;
    for(int i=l;i>0;i-=lowbit(i))
        sum+=btree[i];
    return sum;
}

 

 

ll quick(ll a,ll b,ll p,int& ok)

{

    ll ans=1;

    while(b)

    {

        if(b&1)

        {

            if(ans*a>=p) ok=1;

            ans=ans*a%p;

 

        }

        if(a*a>=p) ok=1;

        a=a*a%p;

        b=b>>1;

    }

    return ans;

}

 

ll  dfs(int now,int r,ll p)

{

    ll tmp=query(now);

    if(now==r||p==1)

    {

        //if(cnt!=0)

            return tmp%p+(tmp>=p?p:0);

        /*else

            return tmp%p;*/

    }

    ll k=dfs(now+1,r,(ll)phi[p]);

    int ok=0;

    if(tmp>=p) ok=1,tmp=tmp%p;   //！！！tmp=tmp%p

    ll ans= quick(tmp,k,p,ok);

    if(ok)

    {

        ans+=p;

    }

    //if(cnt!=0)

        return ans;


 

}

 

int main()

{

    getphi(MAXN-2);

    int m;

    scanf("%d%d",&n,&m);

    a[0]=0;

    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        add(i,a[i]-a[i-1]);
    }

    for(int i=0;i<m;i++)

    {

        int l,r,mode;

        ll x;

        scanf("%d%d%d%lld",&mode,&l,&r,&x);

        if(mode==1)

        {

            add(l,x);

            add(r+1,-x);

        }

        else

        {

            printf("%lld\n",dfs(l,r,x)%x);  //%x用于去除dfs内a[l]%x时加上x的情况

        }

    }
    return 0;
}

