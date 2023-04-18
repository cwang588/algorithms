#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int k;
long long A,h;
int a[50];
unordered_map<long long,vector<int>>m[2];
set<long long>s[2];
long long mi[1005];
void dfs(int id,int now){
	if(now==k+1){
		long long now=0;
		vector<int>tmp;
		for(int i=1;i<=(1<<(k-1));++i){
			now+=(id*(1<<(k-1))+i)*mi[a[id*(1<<(k-1))+i]];
			now%=mod;
			tmp.push_back(a[i]);
		}
		s[id].insert(now);
		m[id][now]=tmp;
		return;
	}
	if(now==2){
		int pos=0;
		for(int i=1;i<=(1<<(k-1));++i){
			if(a[id*(1<<(k-1))+i]<=2){
				pos=i;
				break;
			}
		}
		if(pos<=)
	}
}
int main(){
	cin>>k>>A>>h;
	for(int i=1;i<=16;++i){
		memset(a,0,sizeof(a));
		a[i]=1;
		dfs(0,2);
	}
	
	return 0;
}
