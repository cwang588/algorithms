#include<bits/stdc++.h>
using namespace std;
int a[]={0,1,3,2,6,7,5,4,12,13,15,14,10,11,9,8,24,25,27,26,30,31,29,28,20,21,23,22,18,19,17,16};
int b[15],ans[15];
int main(){
	int tot=0;
	for(int i=1;i<=7;++i)tot+=a[i]^a[i-1];
	for(int i=1;i<=7;++i)b[i]=i;
	int Min=2147483647;
	do{
		int now=0;
		for(int i=1;i<=7;++i)now+=b[i]^b[i-1];
		if(now<Min){
			Min=now;
			for(int i=1;i<=7;++i)ans[i]=b[i];
		}
	}while(next_permutation(b+1,b+8));
	cout<<Min<<" "<<tot<<"\n";
	for(int i=1;i<=10;++i)cout<<ans[i]<<" ";
	return 0;
}