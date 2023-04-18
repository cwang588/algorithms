#include<bits/stdc++.h>
using namespace std;
int main(){
	int cnt=0;
	for(long long i=1;i<=10000000;++i){
		if((1000*i)%(1000+i)==0)++cnt,cout<<i<<" "<<(1000*i)/(1000+i)<<endl;
	}
	cout<<cnt;
	return 0;
}