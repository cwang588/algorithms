#include<bits/stdc++.h>
using namespace std;
int main(){
	srand((unsigned)time(0));
	freopen("15731.in","w",stdout);
	for(int i=1;i<=100;++i){
		int t=rand()%126;
		if(t<32)t=32;
		cout<<(char)t; 
	}
	cout<<endl;
	return 0;
}
