#include<bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
long long a[1000005],mx[1000005<<2],mxcnt[1000005<<2],se[1000005<<2],sum[1000005<<2],col[100005<<2];
void change(int l,int r,int rt,long long x){
    if(x>=mx[rt])return;
    sum[rt]+=(x-mx[rt])*mxcnt[rt];
    mx[rt]=x;
}
void update(int l,int r,int rt){
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
    mx[rt]=max(mx[rt<<1],mx[rt<<1|1]);
    mxcnt[rt]=0;
    if(mx[rt<<1]==mx[rt])mxcnt[rt]+=mxcnt[rt<<1];
    if(mx[rt<<1|1]==mx[rt])mxcnt[rt]+=mxcnt[rt<<1|1];
    se[rt]=max(se[rt<<1],se[rt<<1|1]);
    if(mx[rt<<1]!=mx[rt<<1|1])se[rt]=max(se[rt],min(mx[rt<<1],mx[rt<<1|1]));
}
void push_down(int l,int r,int rt){
    int m=(l+r)>>1;
    mx[rt<<1]+=col[rt];
    se[rt<<1]+=col[rt];
    sum[rt<<1]+=col[rt]*(m-l+1);
    mx[rt<<1|1]+=col[rt];
    se[rt<<1|1]+=col[rt];
    sum[rt<<1|1]+=col[rt]*(r-m);
    col[rt]=0;
    change(lson,mx[rt]);
    change(rson,mx[rt]);
}
void build(int l,int r,int rt){
    if(l==r){
        mx[rt]=sum[rt]=a[l];
        se[rt]=-1;
        mxcnt[rt]=1;
        return;
    }
    int m=(l+r)>>1;
    build(lson);
    build(rson);
    update(l,r,rt);
}
void modify(int l,int r,int rt,int nowl,int nowr,long long x){
    if(x>=mx[rt])return;
    if(nowl<=l&&nowr>=r&&x>se[rt]){
        change(l,r,rt,x);
        return;
    } 
    int m=(l+r)>>1;
    push_down(l,r,rt);
    if(nowl<=m)modify(lson,nowl,nowr,x);
    if(nowr>m)modify(rson,nowl,nowr,x);
    update(l,r,rt);
}
long long querymax(int l,int r,int rt,int nowl,int nowr){
    if(nowl<=l&&r<=nowr)return mx[rt];
    int m=(l+r)>>1;
    push_down(l,r,rt);
    long long re=0;
    if(nowl<=m)re=max(re,querymax(lson,nowl,nowr));
    if(nowr>m)re=max(re,querymax(rson,nowl,nowr));
    return re;
}
long long querysum(int l,int r,int rt,int nowl,int nowr){
    if(nowl<=l&&r<=nowr)return sum[rt];
    int m=(l+r)>>1;
    push_down(l,r,rt);
    long long re=0;
    if(nowl<=m)re+=querysum(lson,nowl,nowr);
    if(nowr>m)re+=querysum(rson,nowl,nowr);
    return re;
}
void add(int l,int r,int rt,int nowl,int nowr,long long x){
	if(nowl<=l&&r<=nowr){
		mx[rt]+=x;
		se[rt]+=x;
		sum[rt]+=x*(r-l+1);
		col[rt]+=x;
		return;
	}
	push_col(l,r,rt);
	int m=(l+r)>>1;
	if(nowl<=m)add(lson,nowl,nowr,x);
	if(nowr>m)add(rson,nowl,nowr,x);
	update(l,r,rt);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;++i)cin>>a[i];
        build(1,n,1);
        for(int i=1;i<=m;++i){
            int op;
            cin>>op;
            if(op==2){
                int l,r;
                long long x;
                cin>>l>>r>>x;
                modify(1,n,1,l,r,x);
            }
            else if(op==4){
                int l,r;
                cin>>l>>r;
                printf("%lld\n",querymax(1,n,1,l,r));
            }
            else if(op==3){
                int l,r;
                cin>>l>>r;
                printf("%lld\n",querysum(1,n,1,l,r));
            }
            else if(op==1){
            	int l,r,x;
            	cin>>l>>r;
            	add(1,n,1,l,r,x);
            }
            else{
            	int l,r;
            	cin>>l>>r;
            }
        }
    }
    return 0;
}

