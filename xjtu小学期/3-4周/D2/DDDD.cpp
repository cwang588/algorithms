#include <bits/stdc++.h>
using namespace std;
const int MAX_N=5000005;
int n;
priority_queue <pair<double,double>,vector<pair<double,double> >,greater<pair<double,double> > > q;
double D1,C,D2; 
struct d
{
	double D,P; 
}dd[MAX_N]; 
double can[MAX_N];
int main()
{
	std::ios::sync_with_stdio(false);
    cin>>D1>>C>>D2>>dd[0].P>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>dd[i].D>>dd[i].P;
    }
    dd[n+1].D=D1;
    double cost=0;
    for(int i=0;i<=n;i++)
    {
        q.push(make_pair(dd[i].P,C));
        double dist=dd[i+1].D-dd[i].D;
        while(!q.empty())
        {
            if(dist<q.top().second*D2)
            {
                auto t=q.top();
                q.pop();
                t.second-=dist/D2;
                cost+=dist/D2*t.first;
                q.push(t);
                break; 
            }
            dist-=q.top().second*D2;
            cost+=q.top().first*q.top().second;
            q.pop();
        }
        if(dist&&q.empty())
        {
            puts("No Solution");
            return 0;
        }
    }
    printf("%.2lf\n",cost);
    return 0;
}
