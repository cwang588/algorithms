#include<bits/stdc++.h>
using namespace std;
int x[1000005],v[1005][1005];
struct edge{
	int x,y,z;
}e[20000005];
int cnt,fa[1000005],n,m;
int getid(int x,int y){
	return (x-1)*m+y;
}
bool cmp(edge a,edge b){
	return a.z>b.z;
}
int getfa(int x){
	if(fa[x]!=x)fa[x]=getfa(fa[x]);
	return fa[x];
}
void Merge(int x,int y){
	fa[x]=y;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	for(int Case=1;Case<=t;++Case){
		int sx,sy,tx,ty,A,B,C,P;
		cin>>n>>m>>sx>>sy>>tx>>ty>>x[1]>>x[2]>>A>>B>>C>>P;
		cnt=0;
		for(int i=3;i<=n*m;++i)x[i]=(A*x[i-1]+B*x[i-2]+C)%P;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				v[i][j]=x[(i-1)*m+j];
				fa[getid(i,j)]=getid(i,j);
			}
		}
		for(int i=1;i<=n;++i){
			for(int j=1;j<m;++j){
				e[++cnt]={getid(i,j),getid(i,j+1),v[i][j]*v[i][j+1]};
			}
		}
		for(int i=1;i<=m;++i){
			for(int j=1;j<n;++j){
				e[++cnt]={getid(j,i),getid(j+1,i),v[j][i]*v[j+1][i]};
			}
		}
		sort(e+1,e+1+cnt,cmp);
		long long ans=0;
		int num=0;
		for(int i=1;i<=cnt;++i){
			int r1=getfa(e[i].x),r2=getfa(e[i].y);
			if(r1==r2)continue;
			ans+=e[i].z;
			Merge(r1,r2);
			++num;
			if(num==n*m-1)break;
		}
		cout<<"Case #"<<Case<<": "<<ans<<"\n";
	}
	return 0;	
}