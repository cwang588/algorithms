#include<bits/stdc++.h>
using namespace std;
string a[10005];
bool usd[2000005];
int n,m;
int getid(int x,int y){
	return (y-1)*n+x;
}
struct edge{
	int from,to,nxt;
}e[40000006];
int Head[1000005],cnt;
queue<pair<int,int> >q;
void add(int x,int y){
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		cin.get();
		while(!q.empty())q.pop();
		for(int i=1;i<=4*n+3;++i){
			getline(cin,a[i]);
		}
		cnt=0;
		for(int i=1;i<=n*m;++i)usd[i]=Head[i]=0;
		int S,T;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				int x=4*i-1+2*(1-(j%2)),y=6*j-2;
				if(a[x][y]=='S')S=getid(i,j);
				if(a[x][y]=='T')T=getid(i,j);
			}
		}	
//		cout<<S<<" "<<T<<"\n";
		for(int i=1;i<=m;++i){
			for(int j=1;j<n;++j){
				int x=4*j+1+2*(1-(i%2)),y=6*i-2;
				if(a[x][y]==' '){
					add(getid(j,i),getid(j+1,i));
					add(getid(j+1,i),getid(j,i));
		//			cout<<getid(j,i)<<" "<<getid(j+1,i)<<"\n";
				}
			}
		}
		for(int i=1;i<m;++i){
			if(i%2){
				for(int j=1;j<=n;++j){
					int x=4*j+2*(1-(i%2)),y=6*i+1;
					if(a[x][y]==' '){
						add(getid(j,i),getid(j,i+1));
						add(getid(j,i+1),getid(j,i));
					//	cout<<getid(j,i)<<" "<<getid(j+1,i)<<"\n";
					}
				}
				for(int j=2;j<=n;++j){
					int x=4*j-2+2*(1-(i%2)),y=6*i+1;
					if(a[x][y]==' '){
						add(getid(j,i),getid(j-1,i+1));
						add(getid(j-1,i+1),getid(j,i));
					}
				}
			}
			else{
				for(int j=1;j<n;++j){
					int x=4*j+2*(1-(i%2)),y=6*i+1;
					if(a[x][y]==' '){
						add(getid(j,i),getid(j+1,i+1));
						add(getid(j+1,i+1),getid(j,i));
					}
				}
				for(int j=1;j<=n;++j){
					int x=4*j-2+2*(1-(i%2)),y=6*i+1;
					if(a[x][y]==' '){
						add(getid(j,i),getid(j,i+1));
						add(getid(j,i+1),getid(j,i));
					}
				}
			}
		}
		q.push(make_pair(S,1));
		usd[S]=true;
		int ans=0;
		while(!q.empty()){
			int now=q.front().first,num=q.front().second;
			q.pop();
			if(now==T){
				ans=num;
				break;
			}
			for(int i=Head[now];i;i=e[i].nxt){
				int to=e[i].to;
				if(usd[to])continue;
				q.push(make_pair(to,num+1));
				usd[to]=true;
			}
		}
		if(ans)cout<<ans<<"\n";
		else cout<<"-1\n";
	}
	return 0;
}
