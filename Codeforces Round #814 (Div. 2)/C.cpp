#include<bits/stdc++.h>
using namespace std;
int a[100005],Max[100005],pos[100005];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;++i)cin>>a[i];
		int now=0;
		for(int i=1;i<=n;++i)Max[i]=now=max(now,a[i]),pos[i]=1e9+7;
		stack<int>s;
		for(int i=1;i<=n;++i){
			while(!s.empty()&&a[s.top()]<a[i]){
				pos[s.top()]=i;
				s.pop();
			}
			s.push(i);
		}
		for(int i=1;i<=m;++i){
			int x,y;
			cin>>x>>y;
			if(Max[x]!=a[x])cout<<"0\n";
			else{
				if(x>1)cout<<max(0,min(y-x+2,pos[x]-x))<<"\n";
				else cout<<max(0,min(y-x+1,pos[x]-x-1))<<"\n";
			}
		}
	}
	
	return 0;
}