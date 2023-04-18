#include<bits/stdc++.h>
using namespace std;
int num[6];
unordered_map<string,int>ans;
unordered_map<string,bool>usd;
string modify(string now,int l,int r,int orient){
	string re=now;
	for(int i=l;i<=r;++i){
		re[i]+=orient;
		if(re[i]>'9')re[i]-=10;
		if(re[i]<'0')re[i]+=10;
	}
	return re;
}
void init(){
	usd["0000"]=true;
	queue<string>q;
	q.push("0000");
	while(!q.empty()){
		string now=q.front();
		q.pop();
		for(int i=0;i<=3;++i){
			for(int j=i;j<=3;++j){
				for(int k=-1;k<=1;k+=2){
					string to=modify(now,i,j,k);
					if(usd[to])continue;
					q.push(to);
					ans[to]=ans[now]+1;
					usd[to]=true;
				}
			}
		}
	}
}
int main(){
	//ios::sync_with_stdio(false);
	init();	
	int t;
	cin>>t;
	while(t--){
		string a,b;
		cin>>a>>b;
		for(int i=0;i<4;++i){
			b[i]-=a[i]-'0';
			if(b[i]>'9')b[i]-=10;
			if(b[i]<'0')b[i]+=10;
		}
		cout<<ans[b];
		if(t)cout<<"\n";
	}
	return 0;
}