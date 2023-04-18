#include<cstdio>
using namespace std;
int father[100000005];
int find(int x)
{
    if(father[x]!=x)
        father[x]=find(father[x]);
    return father[x];
}
void unionn(int a,int b)
{
    father[b]=a;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
        father[i]=i;
    for(int i=1;i<=m;++i)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if(a==1)
        {
            int r1=find(b);
            int r2=find(c);
            if(r1!=r2)
                unionn(r1,r2);
        }
        else
        {	
            if(find(b)==find(c))
                printf("Y\n");
            else
                printf("N\n");
        }	
    }	
    
    return 0;
}
