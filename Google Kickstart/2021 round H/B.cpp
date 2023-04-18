#include<bits/stdc++.h>
using namespace std;
struct color{
	bool usd[3];
	void clear(){
		memset(usd,0,sizeof(usd));
	}
}col[100005];
int main(){
	int t;
	cin>>t;
	for(int Case=1;Case<=t;++Case){
		int n;
		cin>>n;
		int ans=0;
		for(int i=1;i<=n;++i){
			col[i].clear();
			char now;
			cin>>now;
			if(now=='R')col[i].usd[0]=true,ans+=1;
			else if(now=='Y')col[i].usd[1]=true,ans+=1;
			else if(now=='B')col[i].usd[2]=true,ans+=1;
			else if(now=='O')col[i].usd[0]=col[i].usd[1]=true,ans+=2;
			else if(now=='P')col[i].usd[0]=col[i].usd[2]=true,ans+=2;
			else if(now=='G')col[i].usd[1]=col[i].usd[2]=true,ans+=2;
			else if(now=='A')col[i].usd[0]=col[i].usd[1]=col[i].usd[2]=true,ans+=3;
			else;
		}
		for(int i=1;i<=n;++i){
			for(int j=0;j<=2;++j)if(col[i].usd[j]&&col[i-1].usd[j])--ans;
		}
		cout<<"Case #"<<Case<<": "<<ans<<"\n";
	}
	
	return 0;
}