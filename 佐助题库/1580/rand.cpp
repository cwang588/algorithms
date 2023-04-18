#include<bits/stdc++.h>
using namespace std;
char tmp[50005];
int main(){
	srand((unsigned)time(0));
	freopen("1580.in","w",stdout);
	for(int i=1;i<=5000;++i){
		memset(tmp,0,sizeof(tmp));
		for(int j=1;j<=8;++j){
			int t=rand()%26;
			tmp[j]=t+'a';
		}
		for(int j=1;j<=rand()%13+1;++j){
			for(int k=1;k<=8;++k)cout<<tmp[k];
		}
		cout<<"\n";
	}
	printf(".\n");
	return 0;
}
