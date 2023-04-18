#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005],c[100005],p[100005],ans[100005];
vector<int>v[100005];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i)scanf("%d",&a[i]),p[i]=0;
		for(int i=1;i<=n;++i)scanf("%d",&b[i]);
		for(int i=1;i<=m;++i)scanf("%d",&c[i]);
		for(int i=1;i<=n;++i)v[b[i]].push_back(i);
		if(v[c[m]].empty()){
			printf("NO\n");
			continue;
		}
		int tmp=v[c[m]][v[c[m]].size()-1];
		for(int i=1;i<=m;++i){
			if(v[c[i]].empty())ans[i]=tmp;
			else{
				if(p[c[i]]==v[c[i]].size())ans[i]=v[c[i]][0];
				else{
					ans[i]=v[c[i]][p[c[i]]++];
					a[ans[i]]=c[i];
				}
			}
		}
		bool ky=true;
		for(int i=1;i<=n;++i){
			if(a[i]!=b[i]){
				ky=false;
				break;
			}
		}
		if(!ky)printf("NO\n");
		else{
			printf("YES\n");
			for(int i=1;i<=m;++i)printf("%d ",ans[i]);
			printf("\n");
		}
		for(int i=1;i<=n;++i)v[b[i]].clear();
	}
	
	return 0;
}
