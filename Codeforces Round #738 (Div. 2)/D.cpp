#include<bits/stdc++.h>
using namespace std;
int fa[3][100005];
int getfa(int x,int num){
	if(fa[num][x]!=x)fa[num][x]=getfa(fa[num][x],num);
	return fa[num][x];
}
void Merge(int x,int y,int num){
	fa[num][x]=y;
}
int ans[100005][2];
int main(){
	int n,m1,m2; 
	cin>>n>>m1>>m2;
	for(int i=1;i<=n;++i)fa[0][i]=fa[1][i]=i;
	for(int i=1;i<=m1;++i){
		int x,y;
		cin>>x>>y;
		int r1=getfa(x,0),r2=getfa(y,0);
		Merge(r1,r2,0);
	}
	for(int i=1;i<=m2;++i){
		int x,y;
		cin>>x>>y;
		int r1=getfa(x,1),r2=getfa(y,1);
		Merge(r1,r2,1);
	}
	int cnt=0;
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			int r1=getfa(i,0),r2=getfa(j,0),r3=getfa(i,1),r4=getfa(j,1);
			if(r1==r2||r3==r4)continue;
			Merge(r1,r2,0);
			Merge(r3,r4,1);
			++cnt;
			ans[cnt][0]=i;
			ans[cnt][1]=j;
		}
	}
	cout<<cnt<<endl;
	for(int i=1;i<=cnt;++i)cout<<ans[i][0]<<" "<<ans[i][1]<<endl; 
	return 0;
}
