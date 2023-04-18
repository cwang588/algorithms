#include<bits/stdc++.h>
using namespace std;
char a[10005],b[10005];
int main(){
	int x;
	cin>>x>>(a+1)>>(b+1);
	int n=strlen(a+1),y=n-x,ans=0;
	for(int i=1;i<=n;++i){
		if(a[i]==b[i]){
			if(x){
				--x;
				++ans;
			}else{
				--y;
			}
		}else{
			if(y){
				--y;
				++ans;
			}else{
				--x;
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}