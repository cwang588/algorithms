#include<bits/stdc++.h>
using namespace std;
int a[20000005];
struct modify
{
    int x,y,val;
}work[1000005];
int n,m,p;
void Clear()
{
    for(int i=1;i<=p;++i)
        if(m*work[i].x+work[i].y<n*m)
            a[m*work[i].x+work[i].y]=0;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        bool re=false,ub=false;
        scanf("%d%d%d",&n,&m,&p);
        for(int i=1;i<=p;++i)
        {
            scanf("%d%d%d",&work[i].x,&work[i].y,&work[i].val);
            if(m*work[i].x+work[i].y>=n*m||m*work[i].x+work[i].y<0)re=true;
            else a[m*work[i].x+work[i].y]=work[i].val;
            if(work[i].x>=n||work[i].x<0||work[i].y>=m||work[i].y<0)ub=true;
        }
        if(re)printf("Runtime error\n");
        else
        {
            for(int i=0;i<n*m;++i)
            {
                printf("%d ",a[i]);
                if((i+1)%m==0)printf("\n");
            }
            if(ub)printf("Undefined Behaviour\n");
            else printf("Accepted\n");
        }
        Clear();
    }
    return 0;
}
