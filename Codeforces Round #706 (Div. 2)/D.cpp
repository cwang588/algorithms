#include<bits/stdc++.h>
using namespace std;
int a[100005],l[100005],r[100005];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=1;i<=n;++i){
		if(a[i]>a[i-1])l[i]=l[i-1]+1;
		else l[i]=1;
	}
	a[n+1]=10000005;
	for(int i=n;i>=1;--i){
		if(a[i]>a[i+1])r[i]=r[i+1]+1;
		else r[i]=1;
	}
	int Max=0,maxnum=0;
	for(int i=1;i<=n;++i){
		if(l[i]==r[i]){
			if(l[i]>Max){
				Max=l[i];
				maxnum=1;
			}
			else if(l[i]==Max)++maxnum;
			else;
		}
		else{
			int now=max(l[i],r[i]);
			if(now>Max){
				Max=now;
				maxnum=1;
			}
			else if(now==Max)++maxnum;
			else;
		}
	}
	int ans=0;
	for(int i=1;i<=n;++i){
		if(l[i]!=r[i])continue;
		else{
			if(l[i]==Max&&maxnum==1)++ans;
		}
	}
	printf("%d\n",ans);
	return 0;
}
