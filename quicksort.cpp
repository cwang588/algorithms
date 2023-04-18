#include<bits/stdc++.h>
using namespace std;
int a[100005];
void quicksort(int l,int r){
	if(l>=r)return;
	int tmp=a[(l+r)>>1];
	int p1=l,p2=r;
	while(p1<=p2){
		while(a[p1]<tmp){
			++p1;
		}
		while(a[p2]>tmp){
			--p2;
		}
		if(p1>p2)break;
		swap(a[p1],a[p2]);
		++p1,--p2;
	}
	quicksort(l,p2);
	quicksort(p1,r);
}
int main(){
	srand((unsigned)time(0));
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	quicksort(1,n);
	for(int i=1;i<=n;++i)printf("%d ",a[i]);
	printf("\n");
	return 0;
}
