#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<int>a[2005];
int usd[2005];
signed main(){
	int n;
	cin>>n;
	for(int i=1;i<=n*2;++i){
		int x,y;
		cin>>x>>y;
		a[x].push_back(y-n);
	}
	for(int i=1;i<=n;++i)sort(a[i].begin(),a[i].end());
	long long tot=0;
	for(int l=1;l<=n;++l){
		memset(usd,0,sizeof(usd));
		long long ans=0;
		for(int r=l;r<=n;++r){
			int x=a[r][0],y=a[r][1];
			if(!usd[x]&&!usd[y])ans+=(y-x)*(x+n-y+1)+x*(n-y+1);
			else if(!usd[x]){
				ans+=x*(n-x+1);
				if(y==a[usd[y]][0])ans+=(n-a[usd[y]][1]+1)*(y-x);
				else{
					if(a[usd[y]][0]>x)ans+=(n-y+1)*(a[usd[y]][0]-x);
				}
			}    
			else if(!usd[y]){
				ans+=y*(n-y+1);
				if(x==a[usd[x]][1])ans+=a[usd[x]][0]*(y-x);
				else{
					if(a[usd[x]][1]<y)ans+=x*(y-a[usd[x]][1]);
				}
			}
			else{
				if(usd[x]==usd[y])ans+=x*(n-y+1);
				else{
					map<int,vector<int> >pos;
					pos[0].push_back(0);			
					pos[n+1].push_back(0);			
					pos[a[usd[x]][0]].push_back(usd[x]);			
					pos[a[usd[x]][1]].push_back(usd[x]);			
					pos[a[usd[y]][0]].push_back(usd[y]);			
					pos[a[usd[y]][1]].push_back(usd[y]);			
					vector<pair<int,vector<int> > >tmp;
					for(auto tt:pos)tmp.push_back(tt);
					int m=tmp.size();
					for(int i=1;i<m-2;++i){
						for(int j=i+1;j<m-1;++j){
							int cntx=0,cnty=0;
							for(int k=i;k<=j;++k){
								for(auto tt:tmp[k].second){
									if(tt==usd[x])++cntx;
									else ++cnty;
								}
							}
							if(j==i+1){
								if(cntx==0||cnty==0)ans+=(tmp[j+1].first-tmp[j].first)*(tmp[i].first-tmp[i-1].first);
							}
							else ans+=(tmp[j+1].first-tmp[j].first)*(tmp[i].first-tmp[i-1].first);
						}
					}			
				}
			}
			usd[x]=r;
			usd[y]=r;
			tot+=ans;
		}
	}
	cout<<tot<<"\n";
	return 0;
}