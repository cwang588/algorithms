#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,num1=0,num2=0;
	scanf("%d",&n);
	while(n--){
		int t;
		scanf("%d",&t);
		if(t%2)++num1;
		else ++num2;
	}
	int ans;
	if(num1>num2){
		if(num1==num2+1)ans=(num2-1)*2;
		else{
			ans=num2*2+(num1-num2)/3*2;
			if((num1-num2)%3==1)--ans;
		}
	}
	else if(num1<num2)++ans;
	else ans=num1*2;
	printf("%d\n",ans);
	return 0;
}
