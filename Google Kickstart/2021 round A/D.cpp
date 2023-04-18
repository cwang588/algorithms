#include<bits/stdc++.h>
using namespace std;
int a[505][505],b[505][505];
int fa[1005];
int getfa(int x){
	if(x!=fa[x])fa[x]=getfa(fa[x]);
	return fa[x];
}
void Merge(int x,int y){
	fa[x]=y;
}
struct edge{
	int x,y;
	long long z;
};
bool cmp(edge a,edge b){
	return a.z>b.z;
}
int main(){
	int t;
	cin>>t;
	for(int Case=1;Case<=t;++Case){
		int n;
		cin>>n;
		for(int i=1;i<=2*n;++i)fa[i]=i;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j)cin>>a[i][j];
		}
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j)cin>>b[i][j];
		}
		int tmp;
		for(int i=1;i<=n;++i)cin>>tmp;
		for(int i=1;i<=n;++i)cin>>tmp;
		vector<edge>e;
		long long ans=0;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				if(a[i][j]!=-1)continue;
				e.push_back(edge{i,j+n,b[i][j]});
				ans+=b[i][j];
			}
		}	
		sort(e.begin(),e.end(),cmp);
		for(auto now:e){
			int r1=getfa(now.x),r2=getfa(now.y);
			if(r1==r2)continue;
			ans-=now.z;
			Merge(r1,r2);
		}
		cout<<"Case #"<<Case<<": "<<ans<<"\n";
	}
	
	
	
	return 0;
}