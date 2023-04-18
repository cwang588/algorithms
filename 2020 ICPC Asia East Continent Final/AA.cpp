#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("in.txt","w",stdout);
	for(int i=1;i<=1000000;++i){
		int t=rand()%3;
		if(!t)cout<<(char)('A'+rand()%26);
		else if(t==1)cout<<(char)('a'+rand()%26);
		else cout<<(char)('0'+rand()%10);
	}
	cout<<endl; 
	return 0;
}
