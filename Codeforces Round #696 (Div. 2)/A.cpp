#include<bits/stdc++.h>
using namespace std;
char a[100005];
int ans[100005];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n>>(a+1);
		for(int i=1;i<=n;++i){
			if(a[i]=='1'){
				if(ans[i-1]!=2){
					printf("1");
					ans[i]=2;
				}
				else{
					printf("0");
					ans[i]=1;
				}
			}
			else{
				if(ans[i-1]!=1){
					printf("1");
					ans[i]=1;
				}
				else{
					printf("0");
					ans[i]=0;
				}
			}
		}
		printf("\n");
	}
	return 0;
}
