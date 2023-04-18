#include<bits/stdc++.h>
using namespace std;
void work(int n){
	int ans=2147483647,last=-1000;
	for(int i=1;i<=n;++i){
		if(n%i==0){
			ans=min(ans,i-last);
			last=i;
		}
	}
	printf("%d:%d\n",n,ans);
}
int main(){
	for(int i=1;i<=100;++i){
		work(i);
	}
	return 0;
}
