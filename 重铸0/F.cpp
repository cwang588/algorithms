#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005],rd[100005];
bool usd[100005];
vector<int>v;
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i],++rd[a[i]];
	for(int i=1;i<=n;++i){
		cin>>b[i];
		if(a[i]!=b[i])usd[i]=usd[b[i]]=true;
	}
	int ans=0;
	for(int i=1;i<=n;++i){
		if(rd[i])continue;
		v.clear();
		v.push_back(i);
		int now=i;
		while(a[now]){
			v.push_back(a[now]);
			now=a[now];
		}
		int num=0;
		for(int j=0;j<v.size();++j){
			++num;
			if(usd[v[j]]){
				for(int k=j+1;k<v.size();++k)usd[v[k]]=true;
				break;
			}
		}
		if(num==v.size())continue;
		if(!num)ans+=v.size()-1;
		else ans+=v.size()-num;
	}
	for(int i=1;i<=n;++i){
		if(usd[i]){
			if(b[i])++ans;
		}
	}
	cout<<ans;
	return 0;
}
