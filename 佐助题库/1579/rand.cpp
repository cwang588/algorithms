#include<bits/stdc++.h>
using namespace std;
void work(){
	int now=rand()%26,t=rand()%3;
	if(t==1)cout<<(char)('a'+now);
	else if(t==2)cout<<(char)('A'+now);
	else cout<<now%10;
}
int main(){
	srand((unsigned)time(0));
	freopen("15795.in","w",stdout);
	int n=rand()%5+1,m=rand()%5+25;
	while(n--)work();
	printf(" ");
	while(m--)work();
	return 0;
}
