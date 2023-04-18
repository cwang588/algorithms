#include<bits/stdc++.h>
using namespace std;
int a[55][55];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int now1=1,now2=n*n;
		for(int i=1;i<=n;++i){
			if(i%2){
				for(int j=1;j<=n;++j){
					if((i+j)%2==0)a[i][j]=now1++;
					else a[i][j]=now2--;
				}
			}else{
				for(int j=n;j>=1;--j){
					if((i+j)%2==0)a[i][j]=now1++;
					else a[i][j]=now2--;
				}
			}
		}
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j)cout<<a[i][j]<<" ";
			cout<<"\n";
		}
	}
	
	
	return 0;
}