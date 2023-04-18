#include<bits/stdc++.h>
using namespace std;
char s[100005];
int main(){
	cin>>(s+1);
	int n=strlen(s+1);
	int tot=0,last=0;
	for(int i=1;i<=n;++i){
		if(s[i]=='w'&&!last)last=i;
		if(s[i]=='w'&&s[i+1]!='w'){
			tot+=2*(i-last+1)-1;
			last=0; 
		}
	}
	printf("%d\n",tot);
	return 0;
}
