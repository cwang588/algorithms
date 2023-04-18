#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("in.txt","w",stdout);
	cout<<"10"<<endl;
	for(int j=1;j<=10;++j){
		int n=10000;
		cout<<n<<endl;
		for(int i=2;i<=n;++i)cout<<i<<" "<<rand()%(i-1)+1<<endl;
		for(int i=2;i<=n;++i)cout<<i<<" "<<rand()%(i-1)+1<<endl;
	}
	return 0;
}
