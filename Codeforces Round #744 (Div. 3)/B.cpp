#include<bits/stdc++.h>
using namespace std;
int a[50005],b[50005];
struct ans{
	int l,r,num;
};
vector<ans>m;
void rotate(int l,int r,int k){
	int len=r-l+1;
	for(int i=1;i<=k;++i){
		int tmp=a[l];
		for(int j=l;j<r;++j)a[j]=a[j+1];
		a[r]=tmp;
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;++i)cin>>a[i],b[i]=a[i];
		sort(b+1,b+n+1);
		m.clear();
		for(int i=1;i<=n;++i){
			if(a[i]==b[i])continue;
			for(int j=i;j<=n;++j){
				if(a[j]==b[i]){
					m.push_back(ans{i,n,j-i});
					rotate(i,n,j-i);
					break;
				}
			}
		}
		cout<<m.size()<<"\n";
		for(auto x:m)cout<<x.l<<" "<<x.r<<" "<<x.num<<"\n";
	}
	
	return 0;
}
