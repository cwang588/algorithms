#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("in.txt","w",stdout);
	int n=200000;
	cout<<n<<endl;
	for(int i=1;i<=n;++i){
		cout<<rand()%2+1<<" "<<2*i<<" 1\n";
	}
	return 0;
}