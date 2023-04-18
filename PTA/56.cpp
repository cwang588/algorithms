#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
struct node{
    double x,y;
}p[10005],s[10005];
int n;
double ans,mid;
double CJ(node a1,node a2,node b1,node b2)
{
    return (a2.x-a1.x)*(b2.y-b1.y)-(b2.x-b1.x)*(a2.y-a1.y);
}//�������0����a��ת��b 
double dis(node p1,node p2)
{
    return sqrt( (double)(p2.y-p1.y)*(p2.y-p1.y)*1.0+(double)(p2.x-p1.x)*(p2.x-p1.x)*1.0 );
}//������빫ʽ 
bool cmp(node p1,node p2)
{
    double tmp=CJ(p[1],p1,p[1],p2);
    if(tmp>0) return 1;
    if(tmp==0 && dis(p[0],p1)<dis(p[0],p2)) return 1;
    return 0;
}//���ռнǵĴ�С���� 
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        scanf("%lf%lf",&p[i].x,&p[i].y);
        if(i!=1&&p[i].y<p[1].y)
        {
            mid=p[1].y;p[1].y=p[i].y;p[i].y=mid;
            mid=p[1].x;p[1].x=p[i].x;p[i].x=mid;
        }
    } 
    //init 

    sort(p+2,p+1+n,cmp);//���ռнǴ�С 
    s[1]=p[1];
    int tot=1;//��Ϊ��͵�һ����͹���� 
    for(int i=2;i<=n;i++)
    {
        while(tot>1&&CJ(s[tot-1],s[tot],s[tot],p[i])<=0) tot--;
        tot++;
        s[tot]=p[i];
    }
    s[tot+1]=p[1];
    for(int i=1;i<=tot;i++) ans+=dis(s[i],s[i+1]);
    printf("%.2lf\n",ans);
    return 0;
}
