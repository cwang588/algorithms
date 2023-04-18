#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	if(n==1)return !printf("! 1\n");
	printf("? 1\n");
	fflush(stdout);
	int a,b,c;
	scanf("%d",&b);
	printf("? 2\n");
	fflush(stdout);
	scanf("%d",&c);
	if(b<c)return !printf("! 1\n");
	printf("? %d\n",n);
	fflush(stdout);
	scanf("%d",&b);
	printf("? %d\n",n-1);
	fflush(stdout);
	scanf("%d",&a);
	if(b<a)return !printf("! %d\n",n);
	int l=1,r=n;
	while(l<r-1){
		int m=(l+r)>>1;
		printf("? %d\n",m);
		fflush(stdout);
		scanf("%d",&b);
		printf("? %d\n",m-1);
		fflush(stdout);
		scanf("%d",&a);
		printf("? %d\n",m+1);
		fflush(stdout);
		scanf("%d",&c);
		if(b<a&&b<c)return !printf("! %d\n",m);
		else{
			if(b>a)r=m;
			else l=m;
		}
	}
	return 0;
}
