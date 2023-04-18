#include<bits/stdc++.h>
using namespace std;
set<long long>s;
void dfs(long long now){
	if(s.count(now)||now>1e9)return;
	s.insert(now);
	dfs(now*2+1);
	dfs(now*4);	
}
int main(){
	dfs(1);
	cout<<s.size();
	
	return 0;
}