#include<bits/stdc++.h>
using namespace std;
int a[100005];
struct node
{
    int l,r,fa;
}T[100005];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    scanf("%d",&a[i]);
    int num=0;
    for(int i=1;i<=n;++i)
    {
        if(a[i]!=-1)
        {
            ++num;
            if(i*2<=n)T[a[i]].l=a[i*2];
            else T[a[i]].l=-1;
            if(i*2+1<=n)T[a[i]].r=a[i*2+1];
            else T[a[i]].r=-1;
            if(i/2>0)T[a[i]].fa=a[i/2];
            else T[a[i]].fa=-1;
        }
    }
    printf("The size of the tree is %d\n",num);
    printf("Node %d is the root node of the tree\n",a[1]);
    for(int i=1;i<=num;++i)
    {
        printf("The father of node %d is %d, the left child is %d, and the right child is %d\n",i,T[i].fa,T[i].l,T[i].r);
    }
    return 0;
}
