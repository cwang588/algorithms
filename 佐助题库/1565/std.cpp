#include<bits/stdc++.h>
using namespace std;
int main(){
//	freopen("1565.in","r",stdin);
//	freopen("1565.out","w",stdout);
	int n;
	cin>>n;
	string s1,s2;
	while(n--){
		cin>>s1>>s2;
		if(s1==s2){
			printf("Tie\n");
			continue;
		} 
		if(s1=="Hunter"){
			if(s2=="Gun")printf("Player1\n");
			else printf("Player2\n");
		}
		else if(s1=="Bear"){
			if(s2=="Gun")printf("Player2\n");
			else printf("Player1\n");
		}
		else{
			if(s2=="Bear")printf("Player1\n");
			else printf("Player2\n");
		}
	}
	return 0;
}
