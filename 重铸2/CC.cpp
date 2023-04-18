#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("in.txt","w",stdout);
	int n=1000000,m=999999;
	cout<<n<<" "<<m<<endl;
	for(int i=1;i<n;++i){
		int x=rand()%n+1,y=rand()%n+1;
		cout<<i<<" "<<i-1<<endl;
	}
//	for(int i=1;i<=m;++i){
//		cout<<"1 2\n";
//	}
	return 0;
}
