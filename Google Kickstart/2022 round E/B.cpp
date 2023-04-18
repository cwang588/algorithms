#include<bits/stdc++.h>
using namespace std;
struct stu{
	int a,id,ans;
}s[100005];
bool cmp(stu x,stu y){
	return x.a<y.a;
}
int main(){
	int t;
	cin>>t;
	for(int Case=1;Case<=t;++Case){
		int n;
		cin>>n;
		for(int i=1;i<=n;++i)cin>>s[i].a,s[i].id=i;
		sort(s+1,s+1+n,cmp);
		int now=1,Max=-1;
		for(int i=1;i<=n;++i){
			while(now<=n&&a[now]<=a[i]*2)
		}
	}
	
	
	return 0;
}