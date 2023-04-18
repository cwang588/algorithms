#include<bits/stdc++.h>
using namespace std;
int p[105];
bool check(int l,int r){
	int tot=0,num=r-l+1;
	for(int i=l;i<=r;++i)tot+=p[i];
	for(int i=l;i<=r;++i)if(num*p[i]==tot)return true;
	return false;
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;++i)cin>>p[i];
	int ans=0;
	for(int i=1;i<=n;++i){
		for(int j=i;j<=n;++j){
			if(check(i,j))++ans;
		}
	}
	printf("%d\n",ans);
	return 0;
}
