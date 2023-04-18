#include<bits/stdc++.h>
using namespace std;
char a[1005][10005];
int now[10005];
stack<char>st;
vector<char>ans;
int main(){
	int n,m,s;
	cin>>n>>m>>s;
	int tmp;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j)cin>>a[i][j];
	}
	cin>>tmp;
	int numcnt=0;
	while(tmp!=-1){
		if(!tmp){
			if(!st.empty()){
				ans.push_back(st.top());
				--numcnt;
				st.pop();
			}
		}
		else{
			++now[tmp];
			if(now[tmp]<=m){
				if(numcnt==s){
					ans.push_back(st.top());
					st.pop();
					--numcnt;
				}
				st.push(a[tmp][now[tmp]]);
				++numcnt;
			}
		}
		cin>>tmp;
	}
	for(int i=0;i<ans.size();++i)cout<<ans[i];
	return 0;
}
