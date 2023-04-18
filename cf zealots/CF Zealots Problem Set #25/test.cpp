#include<bits/stdc++.h>
using namespace std;
int calc(int i){
	if(i==1)return 1;
	int re=0;
	do{
		++re;
		i>>=1;
	}while(!(i&1));
	return re;
}
int main(){
	int tot=0;
	for(int i=1;i<=100000;++i)tot+=calc(i);
	cout<<tot<<"\n";
	return 0;
}