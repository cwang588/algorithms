#include<bits/stdc++.h>
using namespace std;
int main(){
	srand((unsigned)time(0));
	freopen("1576.in","w",stdout);
	printf("10000\n");
	for(int i=1;i<=10000;++i){
		for(int j=1;j<=200;++j){
			int t=rand()%26;
			cout<<(char)(t+'a');
		}
		cout<<endl;
	}
	return 0;
}
