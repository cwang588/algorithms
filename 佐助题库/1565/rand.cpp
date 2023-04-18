#include<bits/stdc++.h>
using namespace std;
string s[]={"Hunter","Bear","Gun"};
int main(){
	freopen("1565.in","w",stdout);
	int n=100;
	cout<<n<<"\n";
	for(int i=1;i<=n;++i){
		int r1=rand()%3,r2=rand()%3;
		cout<<s[r1]<<" "<<s[r2]<<"\n";
	}
	return 0;
}
