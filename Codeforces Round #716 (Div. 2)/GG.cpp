#include<bits/stdc++.h>
using namespace std;
void sswap(int *p,int *q){
	int *temp;
	*temp=*p;
	*p=*q;
	*q=*temp;
}
int main(){
	int a,b;
	cin>>a>>b;
	sswap(&a,&b);
	cout<<a<<b;
	return 0;
}
