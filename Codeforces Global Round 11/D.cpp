#include<bits/stdc++.h>
using namespace std;
int a[55],tmp[55];
vector<int>v[55];
int n;
void work(int now){
	int nn=v[now].size();
	int pos=0;
	for(int i=nn-1;i>=0;--i){
		for(int j=1;j<=v[now][i];++j)tmp[pos+j]=a[n-pos-v[now][i]+j];
		pos+=v[now][i];
	}
	for(int i=1;i<=n;++i)a[i]=tmp[i];
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	int ans=0;
	while(1){
		for(int i=1;i<=n;++i){
			int pos=0;
			for(int j=1;j<=n;++j)if(a[j]==a[i]+1)pos=j;
			if(pos<i&&pos){
				++ans;
				if(pos>1)v[ans].push_back(pos-1);
				int now=pos;
				while(a[now+1]==a[now]+1)++now;
				v[ans].push_back(now-pos+1);
				v[ans].push_back(i-now);
				if(i<n)v[ans].push_back(n-i);
				work(ans);
				break;
			}
		}
		bool ky=true;
		for(int i=1;i<=n;++i)if(a[i]!=a[i-1]+1)ky=false;
		if(ky)break;
	}
	printf("%d\n",ans);
	for(int i=1;i<=ans;++i){
		printf("%d ",v[i].size());
		for(auto x:v[i])printf("%d ",x);
		printf("\n");
	}
	
	return 0;
}
