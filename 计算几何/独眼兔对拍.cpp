#include<bits/stdc++.h>
using namespace std;
const int INF=1000000005;
struct vec
{
    int x,y;
    inline vec operator+(vec &b) const {return (vec){x+b.x,y+b.y};}     //向量加
    inline vec operator-(vec &b) const {return (vec){x-b.x,y-b.y};}     //向量减
};          //向量结构体
inline int operator*(vec a,vec b) {return a.x*b.y-a.y*b.x;} //向量的叉积
struct point
{
    int x,y;
    inline vec operator-(point &b) const {return (vec){x-b.x,y-b.y};}   //向量产生
    inline double operator/(point &b) const {return sqrt((x-b.x)*(x-b.y)+(y-b.y)*(y-b.y));} //两点之间的距离
}a[1005];//平面上的一个点
int n,w=0,vis[1005];    //vis表示此处的萝卜是否被吃掉了
vector<int>v;           //v表示答案数组
int main()
{
    scanf("%d",&n),a[0].x=a[0].y=INF;       //第一个点设置为无穷大，是为了方便下一行处理
    for(int i=1;i<=n;i++) scanf("%d%d",&a[i].x,&a[i].y),w=(a[i].y<a[w].y)?i:w;
    memset(vis,0,sizeof(vis));
    vis[w]=1,v.push_back(w);    //最下面的点入队
    point lst1=(point){0,a[w].y},lst2=a[w]; //lst1表示上一个点，lst2表示前面的第二个点
    for(int i=1,mw=-1;i<n;i++,mw=-1)
    {
        for(int j=1;j<=n;j++)
            if(!vis[j]&&(lst2-lst1)*(a[j]-lst1)>=0)     //这个点没有来过且不需要享有旋转
            {
                if(mw==-1) {mw=j;continue;}
                int t=(a[mw]-lst2)*(a[j]-lst2);     //用贪心的思想，要尽量的找到与上一个面积最小
                if(t<0||(t==0&&(a[j]/lst2)<(a[mw]/lst2))) mw=j;
            }
        if(mw==-1) break;
        v.push_back(mw),vis[mw]=1,lst1=lst2,lst2=a[mw];     //加入答案序列，标位已访问
    }
    printf("%d ",n);
    for(int i=0;i<(int)v.size();i++) printf("%d ",v[i]);    //输出
    return puts(""),0;
}
