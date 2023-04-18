#include<bits/stdc++.h>
int a[25][25];
using namespace std;
int n,m;
int mov[8][2]={{0,-1},{0,1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
bool judge(int x,int y){
	for(int i=0;i<8;++i){
		int tox=x+mov[i][0],toy=y+mov[i][1];
		if(tox>=1&&tox<=n&&toy>=1&&toy<=m&&a[tox][toy])return false;
	}
	return true;
}
int main(){
	int t;	
	cin>>t;
	while(t--){
		memset(a,0,sizeof(a));
		cin>>n>>m;
		for(int i=1;i<=m;i+=2)a[1][i]=a[n][i]=1;
		for(int i=2;i<n;++i){
			for(int j=1;j<=m;++j){
				if((j!=1&&j!=m)||!judge(i,j))a[i][j]=0;
				else a[i][j]=1;
			}
		}
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j)cout<<a[i][j];
			cout<<endl;
		}
	}
	return 0;
}
