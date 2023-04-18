#include<bits/stdc++.h>
using namespace std;
int a[]={0,0,21,13,41,51,61,17,81,19};
bool usd[10][1005];
vector<int>v[15];
bool check(int now,int d){
	while(now){
		if(now%10==d)return true;
		now/=10;
	}
	return false;
}
void init(){
	for(int i=2;i<=9;++i){
		for(int j=i;j<=i*a[i]-i-a[i];++j){
			if(check(j,i)){
				v[i].push_back(j);
				usd[i][j]=true;
			}
		}
	}
	for(int i=2;i<=9;++i){
		for(int j=i;j<=i*a[i]-i-a[i];++j){
			if(!usd[i][j]){
				for(int x:v[i]){
					usd[i][j]|=usd[i][j-x];
				}
			}
		}
	}
}
int main(){
	init();
	int t;
	scanf("%d",&t);
	while(t--){
		int n,d;
		scanf("%d%d",&n,&d);
		while(n--){
			int tmp;
			scanf("%d",&tmp);
			if(tmp>a[d]*d-d-a[d])printf("YES\n");
			else{
				if(usd[d][tmp])printf("YES\n");
				else printf("NO\n");
			}
		}
	}
	return 0;
}
