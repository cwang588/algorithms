#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("in.txt","w",stdout);
	cout<<"1000000"<<endl;
	for(int i=1;i<=1000000;++i){
		cout<<rand()*rand()%1000000+9000000<<" ";
	}
	cout<<endl;
	return 0;
}
