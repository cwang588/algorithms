#include<bits/stdc++.h>
using namespace std;
unordered_map<char,int>id;
int idcnt;
vector<int>a[15]; 
int num[15],n,ans,b[15];
long long getnum(int now){
	if(num[b[a[now][0]]]==0)return -1000000;
	long long re=0;
	for(const auto &x:a[now])re=re*10+num[b[x]];
	return re;
}
void dfs(int last,int cnt){
	if(cnt==idcnt){
		for(int i=1;i<=idcnt;++i)b[i]=i;
		do{
			long long tot=0;
			for(int i=1;i<n;++i)tot+=getnum(i);
			if(tot==getnum(n)){
				++ans;
			}
		}while(next_permutation(b+1,b+1+idcnt));
		return;
	}
	for(int i=last+1;cnt+10-i>=idcnt;++i){
		num[cnt+1]=i;
		dfs(i,cnt+1);
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;++i){
		string s;
		cin>>s;
		int m=s.length();
		for(int j=1;j<=m;++j){
			if(!id[s[j-1]-'A'])id[s[j-1]-'A']=++idcnt;
			a[i].push_back(id[s[j-1]-'A']);
		}
	}
	dfs(-1,0);
	cout<<ans<<"\n";
	return 0;
}