#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005],tot[100005];
unordered_map<int,int>m;
set<int>sp,sn;
int getrpos(int l,int r){
	if((l+r)%2)return (l+r)>>1;
	return (l+r)/2-1;
}
int getlpos(int l,int r){
	if((l+r)%2)return (l+r)/2+1;
	return (l+r)/2+1;
}
bool cmp(int x,int y){
	return x>y;
}
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i],b[i]=a[i],m[a[i]]=i;
	sort(b+1,b+1+n,cmp);
	sp.insert(214748364);
	sn.insert(214748364);
	for(int i=1;i<=n;++i){
		int Max=*sp.upper_bound(m[b[i]]),Min=-(*sn.upper_bound(-m[b[i]]));
		int r=min(n,getrpos(m[b[i]]+1,Max-1)),l=max(1,getlpos(Min+1,m[b[i]]-1));
		if(m[b[i]]-Min>2){
			++tot[l];
			--tot[m[b[i]]];
		}
		if(Max-m[b[i]]>2){
			++tot[m[b[i]]+1];
			--tot[r+1];
		}
		sp.insert(m[b[i]]);
		sn.insert(-m[b[i]]);
	}
	for(int i=1;i<=n;++i){
		tot[i]+=tot[i-1];
		cout<<tot[i]<<" ";
	}
	return 0;
}
