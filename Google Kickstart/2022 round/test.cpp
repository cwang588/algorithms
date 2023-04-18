#include<bits/stdc++.h>
using namespace std;
void print(int x){
	cout<<x<<"\n";
//	vector<int>a;
//	while(x){
//		a.push_back(x&1);
//		x/=2;
//	}
//	while(a.size()<32)a.push_back(0);
//	for(int i=32;i>=1;--i)cout<<a[i-1];
//	cout<<"\n";
}
int main(){
	int a=123,b=-123;
	print(a);
	print(a<<3);
	print(a>>3);
	print(b);
	print(b<<3);
	print(b>>3);	
	return 0;
}