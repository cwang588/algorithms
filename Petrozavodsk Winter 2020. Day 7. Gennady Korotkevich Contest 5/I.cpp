#include<bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
struct Point {
	typedef Point P;
	T x, y;
	explicit Point(T x=0, T y=0) : x(x), y(y) {}
	bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
	bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
	P operator+(P p) const { return P(x+p.x,y+p.y); }
	P operator-(P p) const { return P(x-p.x,y-p.y); }
	P operator*(T d) const { return P(x*d,y*d); }
	P operator/(T d) const { return P(x/d,y/d); }
	T dot(P p) const { return x*p.x+y*p.y; }
	T cross(P p) const { return x*p.y-y*p.x; }
	T cross(P a, P b) const { return (a-*this).cross(b-*this); }
	T dist2() const { return x*x+y*y; }
	double dist() const { return sqrt((double)dist2()); }
	double angle() const { return atan2(y, x); }
	P unit() const { return *this/dist(); }
	P perp() const { return P(-y,x); }
	P normal() const { return perp().unit(); }
	P rotate(double a) const {
	return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
	friend ostream& operator<<(ostream& os,P p) {
	return os <<"("<<p.x<<","<<p.y<<")";}
};
typedef Point<ll>P;
vector<P>convexHull(vector<P>pts){
	if(sz(pts)<=1)return pts;
	sort(all(pts));
	vector<P>h(sz(pts)+1);
	int s=0,t=0;
	for(int it=2;it--;s=--t,reverse(all(pts))){
		for(P p:pts){
			while(t>=s+2&&h[t-2].cross(h[t-1],p)<=0)t--;
			h[t++]=p;
		}
	}
	return {h.begin(),h.begin()+t-(t==2&&h[0]==h[1])};
}
template<class T>
T polygonArea2(vector<Point<T>>& v) {
	T a=v.back().cross(v[0]);
	rep(i,0,sz(v)-1) a += v[i].cross(v[i+1]);
	return a;
}
long long gcd(long long x,long long y){
	return y?gcd(y,x%y):x;
}
long long get_num(P a,P b){
	long long tx=abs(a.x-b.x),ty=abs(a.y-b.y),g=gcd(tx,ty);
	return g-1;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<P>now;
		for(int i=1;i<=n;++i){
			long long x,y;
			cin>>x>>y;
			now.push_back(P(x,y));
		}
		auto convex=convexHull(now);
		long long A=polygonArea2(convex),b=sz(convex)+get_num(convex.back(),convex[0]);
		for(int i=0;i<sz(convex)-1;++i)b+=get_num(convex[i],convex[i+1]);
		assert((A-b)%2==0);
		if((A-b+2)/2+b==n)cout<<"1\n";
		else cout<<"0\n";
	}
	
	
	return 0;
}