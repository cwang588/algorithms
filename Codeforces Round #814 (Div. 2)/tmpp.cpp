#include<bits/stdc++.h>
using namespace std;
int main(){
	int a=1,b=0;
	for(int i=1;i<=10;++i){
		int ta=49*a+3*b,tb=3*a+49*b;
		cout<<ta<<"\n";
		a=ta,b=tb;
	}
	return 0;
}