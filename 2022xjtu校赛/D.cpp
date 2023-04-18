#include<bits/stdc++.h>
using namespace std;
int main(){
	int i,c,p;
	cin>>i>>c>>p;
	int num=min(i,min(c/2,p));
	c-=num*2,p-=num;
	cout<<num+min(c/3,p);
	return 0;
}