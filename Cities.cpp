#include<bits/stdc++.h>
using namespace std;
int a[5005];
vector<int>pos[5005];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i){
			scanf("%d",&a[i]);
			pos[i].push_back(i);
		}
	}
	return 0;
}
