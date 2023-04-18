#include<bits/stdc++.h>
using namespace std;
long long a[50005];
bool usd[50005];
int last[50005],tmp[50005];
int n;
int Max(){
	int Max=0,re;
	for(int i=1;i<=n;++i){
		if(usd[i])continue;
		if(a[i]>=Max){
			Max=a[i];
			re=i;
		}
	}
	return re;
}
int Min(){
	int Min=2147483647,re;
	for(int i=1;i<=n;++i){
		if(usd[i])continue;
		if(a[i]<Min){
			Min=a[i];
			re=i;
		}
	}
	return re;
}
int main(){
	int t;
	cin>>t>>n;
	for(int i=1;i<=n;++i)usd[i]=false,last[i]=0,cin>>a[i],tmp[i]=a[i];
	bool ky=true;
	for(int i=1;i<n;++i){
		int l=Max(),r=Min();
		if(last[r]){
			printf("%d\n",n-last[r]+1);
			ky=false;
			break;
		}
		usd[r]=true;
		a[l]-=a[r];
		last[l]=i;
	}
	if(ky)printf("1\n");
	--t;
	while(t--){
		int m;
		cin>>m;
		for(int i=1;i<=n;++i)a[i]=tmp[i],usd[i]=false,last[i]=0;
		while(m--){
			int x,y;
			cin>>x>>y;
			a[x]=y;
		}
		ky=true;
		for(int i=1;i<n;++i){
			int l=Max(),r=Min();
			if(last[r]){
				printf("%d\n",n-last[r]+1);
				ky=false;
				break;
			}
			usd[r]=true;
			a[l]-=a[r];
			last[l]=i;
		}
		if(ky)printf("1\n");
	}
	return 0;
}
