#include<bits/stdc++.h>
using namespace std;
int a[1000005]; 
int main()
{
	freopen("tt.out","w",stdout);
	int n;
	scanf("%d",&n);
//	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)a[i]=rand();
	for(int i=1;i<=n;++i)printf("%d ",a[i]);
	printf("\n");
	int s=clock();
	for(int i=1;i<=n;++i)
		for(int j=1;j<n;++j)
			if(a[j]>a[j+1])
				swap(a[j+1],a[j]);
	int t=clock();
	for(int i=1;i<=n;++i)printf("%d ",a[i]);
	printf("\n%d\n",t-s);
		
	return 0;
}
