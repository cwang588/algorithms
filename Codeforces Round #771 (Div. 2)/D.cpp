#include<bits/stdc++.h>
using namespace std;
int a[1005][1005],pos1[1005],pos2[1005];
struct answer{
	int x,y,z;
};
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j)cin>>a[i][j];
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<n;++j){
			if(a[i][j]==a[i][j+1]){
				pos1[i]=j;
				break;
			}
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<n;++j){
			if(a[j][i]==a[j+1][i]){
				pos2[i]=j;
				break;
			}
		}
	}
	for(int i=1;i<=n;++i){
		if(pos1[i]==0||pos2[i]==0)return !printf("-1\n");
	}
	vector<answer>ans;
	for(int i=1;i<=n;++i){
		for(int j=1;j<pos1[i];++j)ans.push_back(answer{i,j,a[i][j]});
		for(int j=n-1;j>pos1[i];++j)ans.push_back(answer{i,j,a[i][j+1]});
	}
	for(int i=1;i<=n;++i)ans.push_back()
	return 0;
}