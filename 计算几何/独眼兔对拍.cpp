#include<bits/stdc++.h>
using namespace std;
const int INF=1000000005;
struct vec
{
    int x,y;
    inline vec operator+(vec &b) const {return (vec){x+b.x,y+b.y};}     //������
    inline vec operator-(vec &b) const {return (vec){x-b.x,y-b.y};}     //������
};          //�����ṹ��
inline int operator*(vec a,vec b) {return a.x*b.y-a.y*b.x;} //�����Ĳ��
struct point
{
    int x,y;
    inline vec operator-(point &b) const {return (vec){x-b.x,y-b.y};}   //��������
    inline double operator/(point &b) const {return sqrt((x-b.x)*(x-b.y)+(y-b.y)*(y-b.y));} //����֮��ľ���
}a[1005];//ƽ���ϵ�һ����
int n,w=0,vis[1005];    //vis��ʾ�˴����ܲ��Ƿ񱻳Ե���
vector<int>v;           //v��ʾ������
int main()
{
    scanf("%d",&n),a[0].x=a[0].y=INF;       //��һ��������Ϊ�������Ϊ�˷�����һ�д���
    for(int i=1;i<=n;i++) scanf("%d%d",&a[i].x,&a[i].y),w=(a[i].y<a[w].y)?i:w;
    memset(vis,0,sizeof(vis));
    vis[w]=1,v.push_back(w);    //������ĵ����
    point lst1=(point){0,a[w].y},lst2=a[w]; //lst1��ʾ��һ���㣬lst2��ʾǰ��ĵڶ�����
    for(int i=1,mw=-1;i<n;i++,mw=-1)
    {
        for(int j=1;j<=n;j++)
            if(!vis[j]&&(lst2-lst1)*(a[j]-lst1)>=0)     //�����û�������Ҳ���Ҫ������ת
            {
                if(mw==-1) {mw=j;continue;}
                int t=(a[mw]-lst2)*(a[j]-lst2);     //��̰�ĵ�˼�룬Ҫ�������ҵ�����һ�������С
                if(t<0||(t==0&&(a[j]/lst2)<(a[mw]/lst2))) mw=j;
            }
        if(mw==-1) break;
        v.push_back(mw),vis[mw]=1,lst1=lst2,lst2=a[mw];     //��������У���λ�ѷ���
    }
    printf("%d ",n);
    for(int i=0;i<(int)v.size();i++) printf("%d ",v[i]);    //���
    return puts(""),0;
}
