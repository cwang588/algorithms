#include<bits/stdc++.h>
using namespace std;
void work(){
	int now=rand()%26,t=rand()%2;
	if(t==1)cout<<(char)('a'+now);
	else cout<<(char)('A'+now);
}
int main(){
	srand((unsigned)time(0));
	freopen("1567.in","w",stdout);
	for(int j=1;j<=50000;++j){
		for(int i=1;i<=10;++i)work();
		printf(" ");
		for(int i=1;i<=3;++i)work();
		printf("\n");
	}
	return 0;
} 
