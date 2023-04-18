#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <list>
#define rep(i,m,n) for(int i=m;i<=n;i++)
#define dop(i,m,n) for(int i=m;i>=n;i--)
#define lowbit(x) (x&(-x))
#define ll long long
#define INF 2147483647
using namespace std;
inline int read(){
    int s=0,w=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
    return s*w;
}
const int maxn=10010;
const int maxm=10010;
struct Ask{      //��¼ѯ��
    int L,R,X,id,lk;        //L,Rѯ������lk��˵����ڿ�
}A[maxm];
struct Do{        //��¼�޸�
    int x,f,t;      //xλ�ã�fԭ������ɫ��t�޸ĺ����ɫ
}D[maxm];
int l,r,a[maxn],n,m,color[maxn],ans,len,m1,m2,x,Ans[maxm],c[maxn];
char ch;
void move(int now,int mode){               
    color[a[now]]+=mode;
    if(!color[a[now]]&&mode==-1) ans--;
    if(color[a[now]]==1&&mode==1) ans++;
}
int cmp(const Ask &A,const Ask &B){
    if(A.lk==B.lk) return A.R<B.R;
    return A.lk<B.lk;
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>m;
    len=(int)sqrt(n);   //��Ĵ�С
    rep(i,1,n)
       cin>>a[i],c[i]=a[i];      //��a���鱸��
    rep(i,1,m){
       cin>>ch;
       if(ch=='Q'){
         cin>>A[++m1].L;             //m1ѯ�ʴ���
         cin>>A[m1].R;
         A[m1].X=m2;
         A[m1].id=m1;
         A[m1].lk=(A[m1].L-1)/len+1;  
       }
       else{       //m2�޸Ĵ���
         cin>>D[++m2].x;     //�޸ĵ�λ��
         D[m2].f=a[D[m2].x];  //����ԭ������ɫ
         cin>>D[m2].t;       //�����޸ĺ����ɫ
         a[D[m2].x]=D[m2].t;  //�޸���ɫ
       }
    }
    rep(i,1,n) a[i]=c[i];   //��a���黹ԭ
    color[a[1]]=1;
    ans=1;
    l=r=1;
    sort(A+1,A+m1+1,cmp);    //��ѯ������
    rep(i,1,m1){   //һ��һ������
                         //Ī��
       while(x<A[i].X){                //x����ִ�е��޸�
         Do tmp=D[++x];
         if(l<=tmp.x&&r>=tmp.x){
           color[a[tmp.x]]--;
           ans-=!color[a[tmp.x]];
           a[tmp.x]=tmp.t;
           color[a[tmp.x]]++;
           ans+=color[a[tmp.x]]==1;
         }
         a[tmp.x]=tmp.t;
       }
       while(x>A[i].X){
         Do tmp=D[x--];
         if(l<=tmp.x&&r>=tmp.x){
           color[a[tmp.x]]--;
           ans-=!color[a[tmp.x]];
           a[tmp.x]=tmp.f;
           color[a[tmp.x]]++;
           ans+=color[a[tmp.x]]==1;
         }
         a[tmp.x]=tmp.f;
       }
       Ask tmp=A[i];
       while(l<tmp.L) move(l-0,-1),l++;       //��ͨĪ��
       while(l>tmp.L) move(l-1,+1),l--;
       while(r<tmp.R) move(r+1,+1),r++;
       while(r>tmp.R) move(r+0,-1),r--;
       Ans[tmp.id]=ans;
    }
    rep(i,1,m1) printf("%d\n",Ans[i]);
    return 0;
}
