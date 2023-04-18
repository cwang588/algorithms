#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;
const int N=605;
int fa[N],value[N],dp[N][N],sum1[N],sum2[N],last[N][N];
int anslist[N],ans[N];
int getfa(int x)
{
    if(fa[x]!=x)
    {
        int t=fa[x];
        fa[x]=getfa(fa[x]);
        value[x]+=value[t];
    }
    return fa[x];
}
void Merge(int x,int y,int z)
{
	int r1=getfa(x),r2=getfa(y);
	fa[r1]=r2;
	value[r1]=value[y]+z-value[x];
} 
int main()
{
   // ios::sync_with_stdio(false);
    int n,p1,p2;
    cin>>n>>p1>>p2;
    while(n||p1||p2)
    {
        memset(fa,0,sizeof(fa));
        memset(value,0,sizeof(value));
        memset(dp,0,sizeof(dp));
        memset(last,0,sizeof(last));
        memset(sum1,0,sizeof(sum1));
        memset(sum2,0,sizeof(sum2));
        memset(anslist,0,sizeof(anslist));
        memset(ans,0,sizeof(ans));
        for(int i=1;i<=p1+p2;++i)value[i]=0,fa[i]=i;
        for(int i=1;i<=n;++i)
        {
            int x,y;
            string s;
            cin>>x>>y>>s;
            if(s=="no")Merge(x,y,1);
            else Merge(x,y,0);
        }
        for(int i=1;i<=p1+p2;++i)getfa(i);
        for(int i=1;i<=p1+p2;++i)
        {
            getfa(i);
            if(value[i]%2)++sum1[fa[i]];
            else ++sum2[fa[i]];
        }
       // if(p1==p2)printf("no\n");
        //else
        {
            dp[0][0]=1;
            for(int i=1;i<=p1+p2;++i)
                for(int j=0;j<=p1;++j)
                {
                    dp[i][j]=dp[i-1][j];
                    if(j>=sum1[i]&&sum1[i])
					{
						dp[i][j]+=dp[i-1][j-sum1[i]];
						if(dp[i-1][j-sum1[i]])last[i][j]=i*2;
                	}	
					if(j>=sum2[i]&&sum2[i])
					{
						dp[i][j]+=dp[i-1][j-sum2[i]];
						if(dp[i-1][j-sum2[i]])last[i][j]=i*2+1;
                	}	
                }
            if(dp[p1+p2][p1]!=1)printf("no\n");
            else
            {
                int now=p1+p2,tot=p1,num=0,ansnum=0;
                while(last[now][tot])
                {
                    int tmp=last[now][tot];
                    anslist[++num]=tmp;
                    if(tmp%2)tot-=sum2[tmp/2];
                    else tot-=sum1[tmp/2];
                    now=tmp/2-1;
                }
                bool ky=true;
                for(int i=1;i<=num;++i)
                {
                    int tmp=anslist[i];
                    if(sum1[tmp/2]==sum2[tmp/2])
                    {
                    	ky=false;
                    	break;
                    }
                    if(tmp%2==0)
                    {
                        for(int j=1;j<=p1+p2;++j)
                            if(fa[j]==tmp/2&&value[j]%2)
                                ans[++ansnum]=j;
                    }
                    else
                    {
                        for(int j=1;j<=p1+p2;++j)
                            if(fa[j]==tmp/2&&value[j]%2==0)
                                ans[++ansnum]=j;
                    }
                }
                if(!ky)printf("no\n");
                else 
                {
	                sort(ans+1,ans+1+ansnum);
	                for(int i=1;i<=ansnum;++i)printf("%d\n",ans[i]);
	                printf("end\n");
            	}
			}
        }
        cin>>n>>p1>>p2;
    }
    return 0;
}

