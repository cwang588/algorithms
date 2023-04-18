#include<bits/stdc++.h>
using namespace std;
int a[100005],b[300005],cnt[35],mi[32];
bool cmp(int x,int y){
	return x>y;
}
map<int,int>mm;
int main(){
	int n,m;
	cin>>n>>m;
	mi[0]=1;
	for(int i=1;i<=30;++i)mi[i]=mi[i-1]*2,mm[mi[i]]=i;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=1;i<=m;++i)cin>>b[i];
	for(int i=1;i<=n;++i){
		for(int j=30;j>=0;--j){
			if(a[i]>=mi[j]){
				a[i]-=mi[j];
				++cnt[j];
			}
		}
	}
	sort(b+1,b+1+m);
	int ans=0;
	for(int i=1;i<=m;++i){
		int now=mm[b[i]];
		for(int j=now;j<=30;++j){
			if(cnt[j]){
				--cnt[j];
				++ans;
				for(int k=j-1;k>=now;--k)++cnt[k];
				break;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
