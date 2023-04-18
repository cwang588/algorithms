#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	if(n==1)return !printf("1\n1 1\n");
	int m=(2*n-1)/3;
	while(3*m<2*n-1)++m;	
	printf("%d\n",m);
	while(n%3!=2)printf("%d %d\n",n--,n);
	int num=(2*n-1)/3;
	for(int i=1;i<=num/2+1;++i)printf("%d %d\n",i,num/2+1-i+1);
	for(int i=1;i<=num/2;++i)printf("%d %d\n",n-i+1,n-num/2+i);
	return 0;
}