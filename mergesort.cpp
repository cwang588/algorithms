#include<bits/stdc++.h>
using namespace std;
int a[100005],tmp[100005];
void mergesort(int l,int r){
	if(l==r)return;
	int m=(l+r)>>1;
	mergesort(l,m);
	mergesort(m+1,r);
	int p1=l,p2=m+1,now=l-1;
	while(p1<=m&&p2<=r){
		++now;
		if(a[p1]<a[p2]){
			tmp[now]=a[p1];
			++p1;
		}
		else{
			tmp[now]=a[p2];
			++p2;
		}
	}
	while(p1<=m)tmp[++now]=a[p1++];
	while(p2<=r)tmp[++now]=a[p2++];
	for(int i=l;i<=r;++i)a[i]=tmp[i];
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	mergesort(1,n);
	for(int i=1;i<=n;++i)printf("%d ",a[i]);
	printf("\n");
	return 0;
}
