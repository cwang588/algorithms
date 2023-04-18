#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100004];
int work(int l1,int r1,int l2,int r2,int k){
	if(l1>r1)return b[l2+k-1];
	if(l2>r2)return a[l1+k-1];
	if(k==1)return min(a[l1],b[l2]);
	int mid1=min(l1+k/2-1,r1),mid2=min(l2+k/2-1,r2);
	if(a[mid1]<=b[mid2])return work(mid1+1,r1,l2,r2,k-(mid1-l1+1));
	else return work(l1,r1,mid2+1,r2,k-(mid2-l2+1));
}
int main(){
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=1;i<=m;++i)cin>>b[i];
	printf("%d\n",work(1,n,1,m,k));
	return 0;
}