#include<bits/stdc++.h>
using namespace std;
void work(){
	int now=rand()%26,t=rand()%2;
	if(t==1)cout<<(char)('a'+now);
	else cout<<(char)('A'+now);
}
int main(){
	srand((unsigned)time(0));
	freopen("1577.in","w",stdout);
	for(int i=1;i<=1000;++i){
		int n=rand()%1005;
		while(n--)work();
		if(i==1000)printf(".\n");
		else printf(" ");
	}
	return 0;
}
