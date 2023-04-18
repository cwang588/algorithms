#include<bits/stdc++.h>
using namespace std;
int a[100005];
int ans[100005];
int num[100005],tmp[100005];
int main(){
	int t;
	cin>>t;
	for(int Case=1;Case<=t;++Case){
		set<int>s;
		int n;
		cin>>n;
		for(int i=1;i<=n;++i)cin>>a[i],num[i]=tmp[i]=0;
		for(int i=1;i<=n;++i){
			if(!usd[i]){
				int now=i,cnt=1;
				usd[now]=true;
				while(a[now]!=i){
					++cnt;
					now=a[now];
					usd[now]=true;
				}
				++num[cnt];
				++tmp[cnt];
				s.insert(cnt);
			}
		}
		ans[n]=s.size()-1;
		for(int i=n-1;i>=1;--i){
			for(auto x:s){
				if(num[x-1]>tmp[x-1]){
					--tmp[x];
				}
			}
		}
		cout<<"\n";
	}
	
	
	return 0;
}