#include<bits/stdc++.h>
using namespace std;
long long a[10005];
struct print{
	int i,j;
	long long x;
}p[30005];
struct Node{
	long long a;
	int id;
}node[10005],tt[10005];
int cnt,cnttt;
bool cmp(Node x,Node y){
	return x.id-a[x.id]<y.id-a[y.id];
}
bool cmpp(Node x,Node y){
	return x.a>y.a;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		cnt=cnttt=0;
		scanf("%d",&n);
		long long tmp=0;
		for(int i=1;i<=n;++i){
			scanf("%lld",&a[i]);
			tmp+=a[i];
		}
		if(tmp%n){
			printf("-1\n");
			continue;
		}
		tmp/=n;
		bool ky=true;
		int num=0;
		for(int i=2;i<=n;++i){
			if(a[i]<=tmp)continue;
			else{
				long long x=a[i]/i;
				if(a[i]-i*x>tmp){
					node[++cnt]={a[i],i};
				}
				if(x==0)continue;
				else{
					++num;
					p[num]={i,1,x};
					a[1]+=x*i;
					a[i]-=x*i;
				}
			}
		}		
		for(int i=2;i<=n;++i){
			long long x=a[i]/i;
			if(x==0)continue;
			else{
				++cnttt;
				tt[cnttt]={i*x,i};
			}
		}
		sort(node+1,node+1+cnt,cmp);
		sort(tt+1,tt+1+cnttt,cmpp);
		for(int i=1;i<=cnttt;++i){
			if(a[1]>=n)break;
			p[++num]={tt[i].id,1,tt[i].a/tt[i].id};
			a[1]+=tt[i].a;
			a[tt[i].id]-=tt[i].a;
		}
		if(a[1]<n){
			for(int i=2;i<=n;++i){
				
			}
		}
		for(int i=1;i<=cnt;++i){
			if(a[1]<node[i].id-node[i].a){
				ky=false;
				break;
			}
			++num;
			p[num]={1,node[i].id,node[i].id-a[node[i].id]};
			++num;
			p[num]={node[i].id,1,1};
			a[1]+=a[node[i].id];
			a[node[i].id]=0;
		} 
		if(!ky){
			printf("-1\n");
			continue;
		}
		for(int i=2;i<=n;++i){
			if(tmp==a[i])continue;
			++num;
			p[num]={1,i,tmp-a[i]};
		}
		if(num>3*n){
			printf("-1\n");
			continue;
		}
		printf("%d\n",num);
		for(int i=1;i<=num;++i){
			printf("%d %d %lld\n",p[i].i,p[i].j,p[i].x);
		}
	}
	return 0;
}
