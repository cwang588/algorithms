#include<bits/stdc++.h>
using namespace std;
int main(){
	int ans=1;
	for(int i=1;i<=2019;i+=2)ans=ans*i%100;
	cout<<ans;
	
	return 0;
}