#include<bits/stdc++.h>
using namespace std;
int a[10005];
int main(){
	freopen("in.txt","w",stdout);
	int n=5,m=20;
	cout<<n<<endl;
	for(int i=2;i<=n;++i)cout<<i<<" "<<rand()%(i-1)+1<<endl;
	for(int i=n;i>=1;--i)cout<<i<<" ";
	cout<<endl<<m<<endl;
	for(int i=1;i<=m;++i){
		int l=rand()%n+1,r=rand()%n+1;
		if(l>r)swap(l,r);
		cout<<rand()%n+1<<" "<<l<<" "<<r<<endl;
	}
	return 0;
}
