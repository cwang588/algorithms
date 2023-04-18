#include<bits/stdc++.h>
using namespace std;
int a[8][8],dis[2005];
bool usd[2005];
vector<int>mov[9]={{8,7,5},{8,7,6,4},{7,6,3},{8,5,4,2},{7,5,4,3,1},{6,4,3,0},{5,2,1},{4,2,1,0},{3,1,0}};
int getnext(int now,int pos){
	for(const auto x:mov[pos]){
		now^=(1<<x);
	}
	return now;
}
int main(){
	queue<int>q;
	q.push(0);
	usd[0]=true;
	while(!q.empty()){
		int now=q.front();
		q.pop();
		for(int i=0;i<9;++i){
			int to=getnext(now,i);
			if(usd[to])continue;
			dis[to]=dis[now]+1;
			q.push(to);
			usd[to]=true;					
		}
	}
	int t;
	cin>>t;
	while(t--){
		int n=0;
		for(int i=1;i<=3;++i){
			for(int j=1;j<=3;++j){
				n<<=1;
				char now;
				cin>>now;
				if(now=='*')n|=1;
			}
		}
		cout<<dis[n]<<"\n";
	}
	
	return 0;
}