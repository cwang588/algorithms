#include<bits/stdc++.h>
using namespace std;
int a[100006],b[100005],sum[405][405];
int lowbit(int x){
	return x&(-x);
}
void add(int x,int id){
	while(x<=300){
		++sum[id][x];
		x+=lowbit(x);
	}
}
int ask(int x,int id){
	int re=0;
	while(x){
		re+=sum[id][x];
		x-=lowbit(x);
	}
	return re;
}
unordered_map<int,int>pos[406]; 
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n*m;++i)cin>>a[i],b[i]=a[i];
		sort(b+1,b+1+n*m);
		for(int i=1;i<=n;++i)pos[i].clear();
		long long ans=0;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				sum[i][j]=0;
				int now=m*(i-1)+j;
				pos[i][b[now]]=j;
			}
		}
		for(int i=1;i<=n*m;++i){
			int tmp=1437,p;
			for(int j=1;j<=n;++j){
				if(!pos[j][a[i]])continue;
				int now=m-pos[j][a[i]]-ask(m,j)+ask(pos[j][a[i]],j);
				if(tmp>now){
					tmp=now;
					p=j;
				}
			}
			ans+=tmp;
			add(pos[p][a[i]],p);
			if(pos[p][a[i]]>1&&b[(p-1)*m+pos[p][a[i]]-1]==a[i])--pos[p][a[i]];
			else pos[p][a[i]]=0;
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
