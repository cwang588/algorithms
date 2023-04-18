#include<bits/stdc++.h>
using namespace std;
char s[100005];
bool usd[100005];
int main(){
    int t;
    cin>>t;
    for(int Case=1;Case<=t;++Case){
        int n;
        long long d,c,m;
        cin>>n>>d>>c>>m>>s+1;
        bool ky=true;
        for(int i=1;i<=n;++i)usd[i]=false;
		for(int i=1;i<=n;++i){
            if(s[i]=='C'){
                if(!c)break;
                --c;
            }
            else{
                if(!d)break;
                --d;
                c+=m;
            }
            usd[i]=true;
        }
        for(int i=1;i<=n;++i){
        	if(s[i]=='D'&&!usd[i]){
        		ky=false;
        		break;
			}
		}
        cout<<"Case #"<<Case<<": ";
        if(ky)cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;   
}