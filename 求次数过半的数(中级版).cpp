#include<bits/stdc++.h>
using namespace std;
unordered_map<int,int>mm;
int main(){
	int n,m;
	scanf("%d%d",&m,&n);
	while(m--){
		int ans;
		mm.clear();
		for(int i=1;i<=n;++i){
			int t;
			scanf("%d",&t);
			++mm[t];
			if(mm[t]*2>n)ans=t;
		}
		printf("%d\n",ans);
	}
	return 0;
}
