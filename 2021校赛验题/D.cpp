#include<bits/stdc++.h>
using namespace std;
vector<int>a[100005],b[100005];
set<int>s[1000005];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		a[i].push_back(0);
		for(int j=1;j<=m;++j){
			char tmpp;
			cin>>tmpp;
			int tmp=tmpp-'0';
			a[i].push_back(tmp);
			if(tmp){
				s[j].insert(i);
				b[i].push_back(j);
			}
		}
	}
	queue<int>q;
	for(int i=1;i<=m;++i)if(s[i].size()==1)q.push(i);
	int ans=n;
	while(!q.empty()){
		int now=q.front();
		q.pop();
		if(s[now].size()==0)continue;
		--ans;
		int stu=*(s[now].begin());
		for(auto x:b[stu]){
			s[x].erase(stu);
			if(s[x].size()==1)q.push(x);
		}
	}
	printf("%d\n",ans);
	return 0;
}
