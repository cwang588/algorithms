#include<bits/stdc++.h>
using namespace std;
char a[5][5],b[5][5];
int cnt1[35],cnt2[35];
int main(){
	for(int i=1;i<=3;++i){
		for(int j=1;j<=3;++j)cin>>a[i][j],++cnt1[a[i][j]-'A'+1];
	}
	for(int i=1;i<=3;++i){
		for(int j=1;j<=3;++j)cin>>b[i][j],++cnt2[b[i][j]-'A'+1];
	}
	int num1=0,num2=0;
	for(int i=1;i<=3;++i){
		for(int j=1;j<=3;++j){
			if(a[i][j]==b[i][j]){
				++num1;
				--cnt1[a[i][j]-'A'+1];
				--cnt2[a[i][j]-'A'+1];
			}
		}
	}
	for(int i=1;i<=26;++i)num2+=min(cnt1[i],cnt2[i]);
	cout<<num1<<"\n"<<num2<<"\n";
	return 0;
}