#include<bits/stdc++.h>
using namespace std;
char s[205][205];
int col[205][205],cnt,x[205][205],y[205][205];
struct window{
	char s[205][205];
	unsigned long long h[15];
}w[10005];
set<unsigned long long>ss;
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j)cin>>s[i][j];
	}
	int maxx=0,maxy=0;
	for(int i=2;i<n;++i){
		for(int j=2;j<m;++j){
			if(s[i][j]=='#')continue;
			if(s[i-1][j]=='#'&&s[i][j-1]=='#'){
				col[i][j]=++cnt;
				x[i][j]=y[i][j]=1;
			}
			else if(s[i-1][j]=='#'){
				col[i][j]=col[i][j-1];
				x[i][j]=x[i][j-1];
				y[i][j]=y[i][j-1]+1;
			}
			else{
				col[i][j]=col[i-1][j];
				x[i][j]=x[i-1][j]+1;
				y[i][j]=y[i-1][j];
			}
			w[col[i][j]].s[x[i][j]][y[i][j]]=s[i][j];
			maxx=max(maxx,x[i][j]);
			maxy=max(maxy,y[i][j]);
		}
	}
	for(int i=1;i<=cnt;++i){
		for(int j=1;j<=maxx;++j){
			for(int k=1;k<=maxy;++k){
				w[i].h[1]=w[i].h[1]*19260817+w[i].s[j][k];
			}
		}
		for(int j=maxy;j>=1;--j){
			for(int k=1;k<=maxx;++k){
				w[i].h[2]=w[i].h[2]*19260817+w[i].s[k][j];
			}
		}
		for(int j=maxx;j>=1;--j){
			for(int k=maxy;k>=1;--k){
				w[i].h[3]=w[i].h[3]*19260817+w[i].s[j][k];
			}
		}
		for(int j=1;j<=maxy;++j){
			for(int k=maxx;k>=1;--k){
				w[i].h[4]=w[i].h[4]*19260817+w[i].s[k][j];
			}
		}
		sort(w[i].h+1,w[i].h+4+1);
		unsigned long long now=0;
		for(int j=1;j<=4;++j)now=now*1000000007+w[i].h[j];
		ss.insert(now);
	}
	cout<<ss.size();
	return 0;
}
