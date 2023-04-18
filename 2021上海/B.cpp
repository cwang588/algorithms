#include<bits/stdc++.h>
using namespace std;
int ans[25][25];
int a[25];
void work(int n){
	int minpos=20;
	for(int i=1;i<n;++i){
		if(a[i]==a[i+1]-1)minpos=min(minpos,a[i]);
		if(a[i]==n&&a[i+1]==1)minpos=min(n,a[i]);
	}	
	for(int i=0;i<minpos;++i)ans[n][i]++;
}
int main(){
	for(int i=1;i<=10;++i){
		for(int j=1;j<=i;++j)a[j]=j;
		work(i);
		while(next_permutation(a+1,a+i+1)){
			work(i);
		}
		for(int j=0;j<=i;++j)cout<<ans[i][j]<<" ";
		cout<<endl; 
	}

	
	return 0;
}