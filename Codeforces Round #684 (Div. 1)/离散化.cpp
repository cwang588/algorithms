vector<int>v;
int getid(int x){
	return lower_bound(v.begin(),v.end(),x)-v.begin()+1;
}




for(int i=1;i<=n;++i)v.push_back(a[i]);
sort(v.begin(),v.end());
v.erase(unique(v.begin(),v.end()),v.end());

getid(a[i]);
