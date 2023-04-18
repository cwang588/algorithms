#include<bits/stdc++.h>
using namespace std;
int cnt[200005];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;++i){
		int x;
		cin>>x;
		++cnt[x];
	}
	if(n==1)return !printf("N\n");
	for(int i=0;i<200000;++i){
		cnt[i+1]+=cnt[i]/2;
		cnt[i]%=2;
	}
	int num=0;
	for(int i=0;i<200000;++i){
		if(cnt[i])++num;
	}
	if(num<=2)printf("Y\n");
	else printf("N\n");
	return 0;
}
