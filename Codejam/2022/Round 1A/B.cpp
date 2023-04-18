#include<bits/stdc++.h>
using namespace std;
int a[205];
int main(){
	int t;
	cin>>t;
	for(int Case=1;Case<=t;++Case){
		int n;
		cin>>n;
		assert(n==100);
		int now=1;
		for(int i=1;i<=30;++i){
			a[i]=now;
			cout<<now<<" ";
			now<<=1;
		}
		for(int i=31;i<=n;++i){
			int tmp=1000000000-i+31;
			a[i]=tmp;
			cout<<1000000000-i+31<<" ";
		}
		cout<<endl;
		for(int i=n+1;i<=n*2;++i)cin>>a[i];
		sort(a+1,a+1+n*2);
		reverse(a+1,a+1+n*2);
		int sum=0;
		for(int i=1;i<=2*n;++i){
			if(sum<=0){
				cout<<a[i]<<" ";
				sum+=a[i];
			}
			else sum-=a[i];
		}
		cout<<endl;
	}
	
	
	return 0;
}