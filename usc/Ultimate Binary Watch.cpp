#include<bits/stdc++.h>
using namespace std;
char ans[5][10],a[16];
int id[]={0,1,3,7,9};
int main(){
	cin>>(a+1);
	for(int i=1;i<=4;++i){
		int now=a[i]-'0';
		for(int j=0;j<4;++j){
			if((1<<j)&now)ans[4-j][id[i]]='*';
			else ans[4-j][id[i]]='.';
		}
	}
	for(int i=1;i<=4;++i){
		for(int j=1;j<=9;++j){
			if(!ans[i][j])cout<<" ";
			else cout<<ans[i][j];
		}
		cout<<"\n";
	}
	return 0;
}