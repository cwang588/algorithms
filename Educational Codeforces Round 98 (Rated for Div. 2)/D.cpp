#include<bits/stdc++.h>
using namespace std;
bool usd[105]; 
int a[1005],ans;
void dfs(int pre,int n){
	if(pre==n){
		memset(usd,0,sizeof(usd));
		usd[0]=usd[n+1]=true;
		for(int i=1;i<=n;++i){
			if(!a[i])continue;
			if(usd[i])return;
			int p=0;
			for(int j=1;j<=i;++j){
				if(!usd[j]){
					p=i-j;
					if(i+p>n)return;
					for(int k=j;k<=i+p;++k)usd[k]=true;
					break;
				}
			}
		}
		for(int i=1;i<=n;++i)if(!usd[i])return;
		++ans;
		return;
	}
	a[pre+1]=0;
	dfs(pre+1,n);
	a[pre+1]=1;
	dfs(pre+1,n);
	a[pre+1]=0;
}
int main(){
	for(int i=1;i<=10;++i){
		memset(a,0,sizeof(a));
		ans=0;
		dfs(0,i);
		printf("%d:%d\n",i,ans);
	}
	return 0;
}
