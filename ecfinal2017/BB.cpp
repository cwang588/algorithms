#include <bits/stdc++.h>
using namespace std;
const int tmax=2e5+5;
int n,m,a[tmax],mnow;
double xba,sum;
struct node{
    int all,num;
    bool operator <(const node &rhs)const
    {
        return 1.0*all*all/(num*(num+1))<1.0*rhs.all*rhs.all/(rhs.num*(rhs.num+1));
    }
};
priority_queue<node> Q;
void work()
{
    int i;
    node tmp;
    for(i=1;i<=mnow;i++)
    {
        tmp=Q.top();
        Q.pop();
        tmp.num++;
        Q.push(tmp);
    }
    while(!Q.empty())
    {
        tmp=Q.top();
        Q.pop();
        sum+=tmp.num*(1.0*tmp.all/tmp.num-xba)*(1.0*tmp.all/tmp.num-xba);
        //printf("%d %d\n",tmp.all,tmp.num);
    }
    printf("%.16lf\n",sum/m);
    return;
}
int main()
{
    int T,i,kase=0;
    cin>>T;
    for(kase=1;kase<=T;kase++)
    {
        scanf("%d%d",&n,&m);
        xba=sum=0;
        mnow=m-n;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            xba+=1.0*a[i];
        }
        xba/=1.0*m;
        for(i=1;i<=n;i++)
            Q.push(node{a[i],1});
        printf("Case #%d: ",kase);
        work();
    }
    return 0;
}

