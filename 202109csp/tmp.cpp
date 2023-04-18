#include<bits/stdc++.h>
using namespace std;
int calc(int p,int q){
	return (p-q)*(p-q);
}
int main(){
	int a,b,c,x,y,z;
	cin>>a>>b>>c>>x>>y>>z;
	cout<<calc(a,x)+calc(b,y)+calc(c,z);
	return 0;
}