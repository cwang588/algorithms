#include<bits/stdc++.h>
using namespace std;
void work(){
	int now=rand()%26,t=1;
	if(t==1)cout<<(char)('a'+now);
	else cout<<(char)('A'+now);
}
int main(){
	srand((unsigned)time(0));
	freopen("15701.in","w",stdout);
	int k=rand()%10+1;
	double n=(double)k/100.0;
	cout<<n<<"\n";	
	for(int i=1;i<=100;++i)work();
	printf("\n");
	for(int i=1;i<=100;++i)work();
	printf("\n");
	return 0;
}
