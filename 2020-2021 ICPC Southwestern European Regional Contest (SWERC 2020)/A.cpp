#include<bits/stdc++.h>
using namespace std;
map<string,int>pos;
struct thing{
	string name;
	int cnt,last;
}a[300005];
int now;
bool cmp(thing x,thing y){
	if(x.cnt!=y.cnt)return x.cnt>y.cnt;
	return x.last>y.last;
}
int main(){
	int n,k;
	cin>>n>>k;
	getchar();
	for(int i=1;i<=3*n;++i){
		string s;
		getline(cin,s);
		if(!pos[s]){
			++now;
			a[now].name=s;
			a[now].cnt=1;
			a[now].last=i;
			pos[s]=now;
		}
		else{
			++a[pos[s]].cnt;
			a[pos[s]].last=i;
		}
	}
	sort(a+1,a+1+now,cmp);
	for(int i=1;i<=k;++i)cout<<a[i].name<<endl;
	return 0;
}
