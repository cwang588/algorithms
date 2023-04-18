#include<bits/stdc++.h>
using namespace std;
int T;
int n;
int a[2005];
int LCR(int x)
{
	if(x%n==0)return n;
	else return x%n;
}
int main()
{
	int i,j,k,l=0;
	scanf("%d",&T);
	while(T--){
		l++;
		scanf("%d",&n);
		printf("Case #%d: %d\n",l,n/2);
			a[1]=1;
			k=1;
			for(i=2;i<=n;i++){
				if(i%2==0)a[i]=(a[i-1]+k)%n;
				else{
					a[i]=(a[i-1]-k+n)%n;
				}
				k++;
			}	
			for(i=0;i<n/2;i++){
				for(j=1;j<n;j++){
					printf("%d %d\n",LCR(a[j]+i),LCR(a[j+1]+i));
				}	
			}		
	}
	return 0;
}