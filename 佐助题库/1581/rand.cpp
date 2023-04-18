#include<bits/stdc++.h>
using namespace std;
char tmp[50005];
int main(){
	srand((unsigned)time(0));
	freopen("15815.in","w",stdout);
	for(int i=1;i<=300;++i){
		int t=rand()%2;
		cout<<(char)(t+'a');
	}
	printf(",");
	int n=rand()%10+1,m=rand()%10+1;
	for(int i=1;i<=n;++i){
		int t=rand()%2;
		cout<<(char)(t+'a');
	}
	printf(",");
	for(int i=1;i<=m;++i){
		int t=rand()%2;
		cout<<(char)(t+'a');
	}
	printf("\n");
	return 0;
}
