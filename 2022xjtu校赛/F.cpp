#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		long long n,m;
		cin>>n>>m;
		printf("%.8f\n",m+1.0*m/(m+1)*n);
	}
	return 0;
}