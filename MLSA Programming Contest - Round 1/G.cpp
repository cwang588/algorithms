#include<bits/stdc++.h>
using namespace std;
int to[250005][55],m;
int getid(int x,int y){
	return x*m+y-m;
}
int main(){
	int n;
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			int t;
			cin>>t;
			if(j<m)to[getid(i,j)][0]=getid(t,j+1);
			else to[getid(i,j)][0]=getid(t,1);
		}
	}
	for(int i=1;i<=30;++i){
		for(int j=1;j<=n*m;++j)to[j][i]=to[to[j][i-1]][i-1];
	}
	int t;
	cin>>t;
	while(t--){
		int s,d;
		cin>>s>>d;
		int now=getid(s,1);
		for(int i=30;i>=0;--i){
			if((1<<i)>d)continue;
			now=to[now][i];
			d-=(1<<i);
		}
		if(now%5)cout<<(now/5)+1<<endl;
		else cout<<now/5<<endl;
	}
	return 0;
}
