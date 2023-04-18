#include<bits/stdc++.h>
using namespace std;
int main(int arg1,char** arg2){
	int test=0,i;
	for(i=1;i<arg1;++i)
		test=test*10+*arg2[i]-'0';
	cout<<test;
	
	return 0;
}