#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e3+7;
const double eps = 1e-8, pi = acos(-1);
struct point
{
    double x, y;
    point() {}
    point(int a, int b) { x = a, y = b; }
    friend point operator + (const point &a, const point &b)
    {
        return point(a.x+b.x, a.y+b.y);
    }
    friend point operator - (const point &a, const point &b)
    {
        return point(a.x-b.x, a.y-b.y);
    }
    friend point operator * (const double &a, const point &b)
    {
        return point(a*b.x, a*b.y);
    }
    friend point operator / (const point &a, const double &b)
    {
        return point(a.x/b, a.y/b);
    }
}v[MAXN], e[10][20];
double dot(point s, point t)
{
    return s.x*t.x+s.y*t.y;
}
double det(point s, point t)
{
    return s.x*t.y-t.x*s.y;
}
struct line
{
    point a, b;
    line() {}
    line(point x, point y) { a = x, b = y; }
};
bool line_make_point(line a, line b, point &res)
{
    double s1 = det(a.a-b.a, b.b-b.a);
    double s2 = det(a.b-b.a, b.b-b.a);
    res = (s1*a.b-s2*a.a)/(s1-s2);
    return true;
}
int main()
{   
    int n; scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d%d", &v[i].x, &v[i].y);
    int id; double score = 0;
    for(int k = 3; k <= 8; k++)
    {
        double Maxx = 0, Minn = 1e9;
        for(int i = 1; i <= k+1; i++) 
			e[k][i].x = cos(2.0*pi/k*(i-1)), e[k][i].y = sin(2.0*pi/k*(i-1));
        for(int i = 1; i <= k; i++)
        {
            point s = e[k][i], t = e[k][i+1];
            for(int j = 1; j <= n; j++)
            {
                if(det(s, v[j]) > -eps && det(t, v[j]) < -eps)
                {
                    line l1(v[j], v[j]+(s-t)), l2(point(0, 0), s);
                    point res;
                    if(line_make_point(l1, l2, res))
                    {
                        double r = sqrt(res.x*res.x+res.y*res.y);
                        Maxx = max(Maxx, r), Minn = min(Minn, r);
                    }
                }
            }
            double ss = (Minn/Maxx)*(Minn/Maxx);
            if(ss > score)
            {
                score = ss;
                id = k;
            }
        }
    }
    printf("%d %.10lf\n", id, score);
    //system("pause");
}
