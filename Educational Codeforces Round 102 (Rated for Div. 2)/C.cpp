#include<bits/stdc++.h>
using namespace std;
int ans[15],a[15],b[15],p[15],maxb[15];
void work(int n,int k){
	for(int i=1;i<=k;++i)a[i]=p[i]=i;
	for(int i=k+1;i<=n;++i)a[i]=2*k-i;
	int num=0;
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			if(a[i]>a[j])++num;
		}
	}
	int maxnum=0,now=0;
	for(int i=1;i<=n;++i)b[i]=p[a[i]];
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			if(b[i]>b[j])++now;
		}
	}
	if(now<=num){
		for(int i=1;i<=n;++i){
			maxb[i]=b[i];
			ans[i]=p[i];
		}
	}
	while(next_permutation(p+1,p+1+k)){
		now=0;
		for(int i=1;i<=n;++i)b[i]=p[a[i]];
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;++j){
				if(b[i]>b[j])++now;
			}
		}
		bool ky=true;
		for(int i=1;i<=n;++i){
			if(b[i]>maxb[i])break;
			else if(b[i]<maxb[i]){
				ky=false;
				break;
			}
			else;
		}
		if(!ky)continue;
		if(now<=num){
			maxnum=now;
			for(int i=1;i<=n;++i){
				maxb[i]=b[i];
				ans[i]=p[i];
			}
		}
	}
}
int main(){
	for(int i=1;i<=8;++i){
		for(int j=1;j<=i;++j){
			if(j*2<=i)continue;
			work(i,j);
			printf("%d %d:\n",i,j);
			for(int k=1;k<=j;++k)printf("%d ",ans[k]);
			printf("\n");
		}
	}
	
	return 0;
}
