#include<bits/stdc++.h>
using namespace std;
void work(){
	int now=rand()%26,t=rand()%2;
	if(t==1)cout<<(char)('a'+now);
	else cout<<(char)('A'+now);
}
int main(){
	freopen("15691.in","w",stdout);
	for(int i=1;i<=100000;++i)work();
	printf("\n");
	return 0;
}
