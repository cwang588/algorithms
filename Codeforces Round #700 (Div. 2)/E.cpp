#include<bits/stdc++.h>
using namespace std;
int b[100005],a[100005];
unordered_map<int,bool>usd;
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&b[i]);
	int cnt=0;
	for(int i=1;i<=n;++i){
		if(b[i]!=b[i-1])a[++cnt]=b[i];
	}
	int ans=0,lasta=0,lastb=0;
	for(int i=1;i<=cnt;++i){
		if(!usd[a[i]]){
			++ans;
			usd[a[i]]=true;
		} 
		else{
			usd.clear();
			usd[a[i]]=usd[a[i-1]]=true;
		}
	}
	printf("%d\n",ans);
	return 0;
}
