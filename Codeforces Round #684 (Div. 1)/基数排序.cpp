#include<bits/stdc++.h>
using namespace std;
struct number{
	int sum,x,y,z,id;//x：个位 y：十位 z：百位 
}num[500005];
bool cmp1(number a,number b){
	if(a.x!=b.x)return a.x<b.x;
	return a.id<b.id;
}
bool cmp2(number a,number b){
	if(a.y!=b.y)return a.y<b.y;
	return a.id<b.id;
}
bool cmp3(number a,number b){
	if(a.z!=b.z)return a.z<b.z;
	return a.id<b.id;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&num[i].sum);
		num[i].x=num[i].sum%10;
		num[i].y=(num[i].sum/10)%10;
		num[i].z=(num[i].sum/100)%10;		
		num[i].id=i;
	}
	sort(num+1,num+n+1,cmp1);
	for(int i=1;i<=n;++i){
		printf("%d ",num[i].sum);
		num[i].id=i;
	}
	printf("\n");
	sort(num+1,num+n+1,cmp2);
	for(int i=1;i<=n;++i){
		printf("%d ",num[i].sum);
		num[i].id=i;
	}
	printf("\n");
	sort(num+1,num+n+1,cmp3);
	for(int i=1;i<=n;++i){
		printf("%d ",num[i].sum);
		num[i].id=i;
	}
	printf("\n");
	return 0;
}
