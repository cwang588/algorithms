#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	long long a=0,b=0;
	for(long long i=1;;++i){
		if(i*(i+1)/2>=n){
			long long now=i*i;
			cout<<now-2*(i*(i+1)/2-n)<<"\n";
			break;
		}
	}
	return 0;
}