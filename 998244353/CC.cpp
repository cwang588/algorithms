#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("in.txt","w",stdout);
	cout<<"2 50000\n";
	for(int i=1;i<50000;++i)cout<<i<<" "<<i+1<<" 1\n";
	for(int i=1;i<50000-1;++i)cout<<i<<" "<<i+1<<" 1\n";
	cout<<"49999 50000 2\n";
	return 0;
}