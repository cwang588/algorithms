#include<bits/stdc++.h>
using namespace std;
int a[1005];
int calc(int i){
	int x=a[2]-a[1],y=abs(a[i]-a[1]),z=abs(a[i]-a[2]);
	if(x>y)swap(x,y);
	if(y>z)swap(y,z);
	if(x>y)swap(x,y);
	return y;
}
int calcc(int i){
	int x=abs(a[i]-a[1]),y=abs(a[i+1]-a[1]),z=abs(a[i+1]-a[i]);
	if(x>y)swap(x,y);
	if(y>z)swap(y,z);
	if(x>y)swap(x,y);
	return y;
}
int main(){
	int n; 
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=3;i<=n;++i)printf("%d:%d\n",i,calc(i));
	return 0;
}
