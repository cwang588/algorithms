#include<bits/stdc++.h>
using namespace std;
int x[100005][13],a[100005],b[100005];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=10;++i)x[0][i]=i;
	for(int i=1;i<=n;++i){
		cin>>a[i]>>b[i];
		++a[i];
		++b[i];
		for(int j=1;j<=10;++j)x[i][j]=x[i-1][j];
		swap(x[i][a[i]],x[i][b[i]]);
	}
	for(int i=1;i<=m;++i){
		int l,r;
		cin>>l>>r;
		for(int j=1;j<=10;++j){
			for(int k=1;k<=10;++k){
				if(x[l-1][k]==x[r][j]){
					cout<<k-1;
					break;
				}
			}
			if(j<10)cout<<" ";
		}
		cout<<endl;
	}
	return 0;
}
