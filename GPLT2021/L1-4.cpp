#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		double now;
		cin>>now;
		if(now<m)printf("On Sale! %.1f\n",now);
	}
	return 0;
}
