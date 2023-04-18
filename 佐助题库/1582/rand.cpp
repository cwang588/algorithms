#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("15820.in","w",stdout);
	srand((unsigned)time(0));
	for(int i=1;i<=5000;++i){
		int tmp=rand()%10+1;
		cout<<tmp<<"\n";
		for(int j=1;j<=tmp;++j){
			int n=rand()%10+191;
			for(int k=1;k<=n;++k)cout<<(char)('a'+rand()%2);
			cout<<"\n";
		}
	}
	cout<<"0\n";
	return 0;
}
