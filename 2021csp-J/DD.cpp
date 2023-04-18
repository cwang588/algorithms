#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("1.in","w",stdout);
	int n=200000;
	cout<<n<<"\n";
	srand(time(0));
	for(int i=1;i<=n;++i)cout<<rand()%2<<" ";
	
	return 0;
}