#include<bits/stdc++.h>
using namespace std;
int fa[1000006],sz[1000006];
int getfa(int x){
	if(fa[x]!=x)fa[x]=getfa(fa[x]);
	return fa[x];
}
void Merge(int x,int y){
	int r1=getfa(x),r2=getfa(y);
	if(r1!=r2){
		fa[r1]=r2;
		sz[r2]+=sz[r1];
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n*2;++i)fa[i]=i;
		for(int i=1;i<=n*2;i+=2)sz[i]=1,sz[i+1]=0;
		for(int i=1;i<=m;++i){
			int x,y;
			string c;
			cin>>x>>y>>c;
			if(c=="imposter"){
				Merge(2*x-1,2*y);
				Merge(2*x,2*y-1);
			}else{
				Merge(2*x-1,2*y-1);
				Merge(2*x,2*y);
			}
		}
		int ans=0;
		bool ky=true;
		for(int i=1;i<=2*n;++i)getfa(i);
		for(int i=1;i<=n*2;i+=2){
			if(fa[i]==fa[i+1]){
				ky=false;
				break;
			}
			if(fa[i]==i)ans+=max(sz[i],sz[i+1]);
		}
		if(!ky)ans=-1;
		cout<<ans<<"\n";
	}
	
	
	return 0;
}