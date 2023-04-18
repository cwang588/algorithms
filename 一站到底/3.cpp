#include<bits/stdc++.h>
using namespace std;
const int INF=1<<30;
const int maxn=1e5+7;
struct Node
{
    int m,s;
}node[maxn];
int tree[maxn<<2];
void build(int l,int r,int k)
{
    if(l>r)
        return;
    if(l==r)
	{
        tree[k]=node[l].s;
        return ;
    }
    int mid=(l+r)>>1;
    build(l,mid,k<<1);
    build(mid+1,r,k<<1|1);
    tree[k]=max(tree[k<<1],tree[k<<1|1]);
}
int query(int l,int r,int ql,int qr,int k)
{
    if(l>r||ql>r||qr<l)
        return -INF;
    if(ql<=l&&qr>=r)
        return tree[k];
    int mid=(l+r)>>1;
    return max(query(l,mid,ql,qr,k<<1),query(mid+1,r,ql,qr,k<<1|1));
}
bool cmp(Node a,Node b)
{
    return a.m<b.m;
}
int main()
{
    memset(tree,0,sizeof(tree));
    int n,ans=0;
    cin>>n;
    for(int i=0;i<n;++i)
        cin>>node[i].m>>node[i].s;
    sort(node,node+n,cmp);
    build(0,n-1,1);
    for(int i=n-2;i>=0;--i){
        int x=query(0,n-1,i,n-1,1);
        if(x>node[i].s)
            ans++;
    }
    cout<<ans<<endl;
    return 0;
}
