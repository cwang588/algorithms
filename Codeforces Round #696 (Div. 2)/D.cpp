#include<bits/stdc++.h>
using namespace std;
int a[200005],odd[200005],even[200005];
int f1[200005][25],f2[200005][25];
int minodd(int l,int r){
	if(l>r)return 0;
	int k=log2(r-l+1);
	return min(f1[l][k],f1[r-(1<<k)+1][k]);
}
int mineven(int l,int r){
	if(l>r)return 0;
	int k=log2(r-l+1);
	return min(f2[l][k],f2[r-(1<<k)+1][k]);
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",&n);
		for(int i=1;i<=n;++i){
			if(i%2){
				odd[i]=a[i]-even[i-1];
				even[i]=even[i-1];
			}
			else{
				even[i]=a[i]-odd[i-1];
				odd[i]=odd[i-1];
			}
		}
		for(int i=1;i<=n;++i){
			f1[i][0]=odd[i];
			f2[i][0]=even[i];
		}
		for(int j=1;j<=21;++j)
			for(int i=1;i+(1<<j)<=n+1;++i){
				f1[i][j]=max(f1[i][j-1],f1[i+(1<<(j-1))][j-1]);
				f2[i][j]=max(f2[i][j-1],f2[i+(1<<(j-1))][j-1]);
			}
		if(minodd(1,n)>=0&&mineven(1,n)){
			if((n%2==0&&even[n]==0)||(n%2&&odd[n]==0)){
				printf("YES\n");
				continue;
			}
		}
		bool ky=false;
		for(int i=1;i<n;++i){
			if(minodd(1,i-1)>=0&&mineven(1,i-1)>=0){
				if(minodd(i,n))
			}
			else break;
		}
	}
	return 0;
}
