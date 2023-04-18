#include<bits/stdc++.h>
using namespace std;
void work(){
	int now=rand()%26,t=rand()%2;
	if(t==1)cout<<(char)('a'+now);
	else cout<<(char)('A'+now);
}
int main(){
	srand((unsigned)time(0));
	freopen("15675.in","w",stdout);
	for(int i=1;i<=30;++i)work();
	printf("\n");
	work();
	return 0;
}
