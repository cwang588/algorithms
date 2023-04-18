#include<bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
inline long long read() 
{
    char ch=getchar();
	long long x=0;
	int f=1;
    while(ch<'0'||ch>'9')
	{
        if(ch=='-')f=-1;
        ch=getchar();
    } 
	while('0'<=ch&&ch<='9') 
	{
        x=x*10+ch-'0';
        ch=getchar();
    } 
	return x*f;
}
struct query{
	int t;
	long long x,y;
}q[600005];
vector<long long>v;
int getid(long long x){return lower_bound(v.begin(),v.end(),x)-v.begin()+1;}
unordered_set<int>s[1200005<<2];
bool check(int id,long long x,long long y){
	long long now_x=q[id].x,now_y=q[id].y;
	return (now_x-x)*(now_x-x)+(now_y-y)*(now_y-y)<now_y*now_y;
}
void modify(int l,int r,int rt,int nowl,int nowr,int id,int type){
	//cout << "y: " << l << ' ' << r << ' ' << rt << ' ' << nowl << ' '<< nowr <<' '<< id << ' '<<type << '\n';
	if(nowl<=l&&r<=nowr){
		if(type==1)s[rt].insert(id);
		else s[rt].erase(id);
		return;
	}
	int m=(l+r)>>1;
	if(nowl<=m)modify(lson,nowl,nowr,id,type);
	if(nowr>m)modify(rson,nowl,nowr,id,type);
	return;
}
vector<int>ans;
void query(int l,int r,int rt,int pos){
	//cout << "query: " << l << ' ' << r << ' ' << rt << ' ' << pos << '\n';
	for(auto now:s[rt])ans.push_back(now);
	if(l==r)return;
	int m=(l+r)>>1;
	if(pos<=m)query(lson,pos);
	else query(rson,pos);
}
int main(){
	//freopen("A.in", "r", stdin);
	//freopen("A.out", "w", stdout);
	//cin.tie(0)->sync_with_stdio(0);
//	ios::sync_with_stdio(false);
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;++i){
		q[i].t=read();
		q[i].x=read();
		q[i].y=read();
//		cin>>q[i].t>>q[i].x>>q[i].y;
		if(q[i].t==1){
			v.push_back(q[i].x-q[i].y);
			v.push_back(q[i].x+q[i].y);
		}
		else v.push_back(q[i].x);
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	int len=v.size();
	for(int i=1;i<=n;++i){
		int nowt=q[i].t,nowx=q[i].x,nowy=q[i].y;
		if(q[i].t==1)modify(1,len,1,getid(nowx-nowy),getid(nowx+nowy),i,1);
		else{
			ans.clear();
			query(1,len,1,getid(nowx));
			int now_id=0;
			for(auto now:ans){
				if(check(now,nowx,nowy)){
					now_id=now;
					break;
				}
			}
			if(!now_id)cout<<"-1\n";
			else{
				cout<<now_id<<"\n";
				modify(1,len,1,getid(q[now_id].x-q[now_id].y),getid(q[now_id].x+q[now_id].y),now_id,-1);
			}
		}
	}
	//for(int i=1;i<=n*8;++i)cout<<s[i].size()<<"\n";
	return 0;
}