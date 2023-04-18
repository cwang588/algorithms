#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n,L,R;
	cin>>n>>L>>R;
	long long t=L%n;
	if(R-L>=n-1-t)cout<<n-1<<"\n";
	else cout<<t+R-L<<"\n";
	return 0;
}