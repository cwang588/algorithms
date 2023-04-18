#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<map>
#include<algorithm>
using namespace std;
namespace cg
{
	const double eps=1e-8;
	const double PI=acos(-1.0);
	int sgn(double x)//���ź��� 
	{
	    if(fabs(x)<eps)return 0;
	    if(x<0)return -1;
	    else return 1;
	}
	struct point
	{
	    double x,y;
	    point() {}
	    point(double _x,double _y)
	    {
	        x=_x;
	        y=_y;
	    }
	    point operator -(const point &b)const
	    {
	        return point(x-b.x,y-b.y);
	    }
		//���
	    double operator ^(const point &b)const
	    {
	        return x*b.y-y*b.x;
	    }
		//���
	    double operator *(const point &b)const
	    {
	        return x*b.x + y*b.y;
	    }
		//��ԭ����ת�Ƕ�B������ֵ������x,y�ı仯
	    void transXY(double B)
	    {
	        double tx = x,ty = y;
	        x = tx*cos(B) - ty*sin(B);
	        y = tx*sin(B) + ty*cos(B);
	    }
	    void input()
	    {
	        scanf("%lf%lf",&x,&y);
	    }
	};
	struct Line
	{
	    point s,e;//����ȷ��һ��ֱ�ߣ�s e�������㣬������ֱ�߻��߶� 
	    double k;//k�Ǽ��� 
		Line() {}
	    Line(point _s,point _e)
	    {
	        s = _s;
	        e = _e;
	        k = atan2(e.y - s.y,e.x - s.x);
	    }
		//��ֱ���ཻ�󽻵�
		//��һ��ֵΪ0��ʾֱ���غϣ�Ϊ1��ʾƽ�У�Ϊ0��ʾ�ཻ,Ϊ2���ཻ
		//ֻ�е�һ��ֵΪ2ʱ�������������
	    pair<int,point> operator &(const Line &b)const
	    {
	        point res = s;
	        if(sgn((s-e)^(b.s-b.e)) == 0)
	        {
	            if(sgn((s-b.e)^(b.s-b.e)) == 0)
	                return make_pair(0,res);//�غ�
	            else return make_pair(1,res);//ƽ��
	        }
	        double t=((s-b.s)^(b.s-b.e))/((s-e)^(b.s-b.e));
	        res.x+=(e.x-s.x)*t;
	        res.y+=(e.y-s.y)*t;
	        return make_pair(2,res);
	    }
	    point operator ^(const Line &b)const
	    {
	        point res = s;
	        double t = ((s - b.s)^(b.s - b.e))/((s - e)^(b.s - b.e));
	        res.x += (e.x - s.x)*t;
	        res.y += (e.y - s.y)*t;
	        return res;
	    }
	};
	//��������
	double dist(point a,point b)
	{
		return sqrt((a-b)*(a-b));
	}
	//�ж����߶��Ƿ��ཻ 
	bool inter(Line l1,Line l2)
	{
	    return
	        max(l1.s.x,l1.e.x) >= min(l2.s.x,l2.e.x) &&
	        max(l2.s.x,l2.e.x) >= min(l1.s.x,l1.e.x) &&
	        max(l1.s.y,l1.e.y) >= min(l2.s.y,l2.e.y) &&
	        max(l2.s.y,l2.e.y) >= min(l1.s.y,l1.e.y) &&
	        sgn((l2.s-l1.e)^(l1.s-l1.e))*sgn((l2.e-l1.e)^(l1.s-l1.e)) <= 0 &&
	        sgn((l1.s-l2.e)^(l2.s-l2.e))*sgn((l1.e-l2.e)^(l2.s-l2.e)) <= 0;
	}
	//�ж�ֱ�ߺ��߶��ཻ
	bool Seg_inter_line(Line l1,Line l2) //�ж�ֱ��l1���߶�l2�Ƿ��ཻ
	{
	    return sgn((l2.s-l1.e)^(l1.s-l1.e))*sgn((l2.e-l1.e)^(l1.s-l1.e)) <= 0;
	}
	//�㵽ֱ�߾��� ����Ϊresult,�ǵ㵽ֱ������ĵ�
	point PointToLine(point P,Line L)
	{
	    point result;
	    double t = ((P-L.s)*(L.e-L.s))/((L.e-L.s)*(L.e-L.s));
	    result.x = L.s.x + (L.e.x-L.s.x)*t;
	    result.y = L.s.y + (L.e.y-L.s.y)*t;
	    return result;
	}
	//�㵽�߶ξ��� ����Ϊresult,�ǵ㵽ֱ������ĵ�
	point NearestPointToLineSeg(point P,Line L)
	{
	    point result;
	    double t = ((P-L.s)*(L.e-L.s))/((L.e-L.s)*(L.e-L.s));
	    if(t >= 0 && t <= 1)
	    {
	        result.x = L.s.x + (L.e.x - L.s.x)*t;
	        result.y = L.s.y + (L.e.y - L.s.y)*t;
	    }
	    else
	    {
	        if(dist(P,L.s) < dist(P,L.e))
	            result = L.s;
	        else result = L.e;
	    }
	    return result;
	}
	//����������� ��ı�Ŵ�0~n-1
	double CalcArea(point p[],int n)
	{
	    double res = 0;
	    for(int i = 0; i < n; i++)
	        res += (p[i]^p[(i+1)%n])/2;
	    return fabs(res);
	}
	//�жϵ����߶���
	bool OnSeg(point P,Line L)
	{
	    return
	        sgn((L.s-P)^(L.e-P)) == 0 &&
	        sgn((P.x - L.s.x) * (P.x - L.e.x)) <= 0 &&
	        sgn((P.y - L.s.y) * (P.y - L.e.y)) <= 0;
	}
	//�жϵ���͹�������
	//���γ�һ��͹�������Ұ���ʱ�����������˳ʱ��������<0��Ϊ>0��
	//��ı��:0~n-1
	//����ֵ��
	//-1:����͹�������
	//0:����͹����α߽���
	//1:����͹�������
	int inConvexPoly(point a,point p[],int n)
	{
	    for(int i = 0; i < n; i++)
	    {
	        if(sgn((p[i]-a)^(p[(i+1)%n]-a)) < 0)return -1;
	        else if(OnSeg(a,Line(p[i],p[(i+1)%n])))return 0;
	    }
	    return 1;
	}
	//*�жϵ�������������
	//���߷���poly[]�Ķ�����Ҫ���ڵ���3,��ı��0~n-1
	//����ֵ
	//-1:����͹�������
	//0:����͹����α߽���
	//1:����͹�������
	int inPoly(point p,point poly[],int n)
	{
	    int cnt;
	    Line ray,side;
	    cnt = 0;
	    ray.s = p;
	    ray.e.y = p.y;
	    ray.e.x = -100000000000.0;//-INF,ע��ȡֵ��ֹԽ��
	    for(int i = 0; i < n; i++)
	    {
	        side.s = poly[i];
	        side.e = poly[(i+1)%n];
	        if(OnSeg(p,side))return 0;
	//���ƽ�����򲻿���
	        if(sgn(side.s.y - side.e.y) == 0)
	            continue;
	        if(OnSeg(side.s,ray))
	        {
	            if(sgn(side.s.y - side.e.y) > 0)cnt++;
	        }
	        else if(OnSeg(side.e,ray))
	        {
	            if(sgn(side.e.y - side.s.y) > 0)cnt++;
	        }
	        else if(inter(ray,side))
	            cnt++;
	    }
	    if(cnt % 2 == 1)return 1;
	    else return -1;
	}
	//�ж�͹�����
	//�����߱�
	//�������˳ʱ�����Ҳ��������ʱ�����
	//��ı��0~n-1
	bool isconvex(point poly[],int n)
	{
	    bool s[3];
	    memset(s,false,sizeof(s));
	    for(int i = 0; i < n; i++)
	    {
	        s[sgn( (poly[(i+1)%n]-poly[i])^(poly[(i+2)%n]-poly[i]) )+1] = true;
	        if(s[0] && s[2])return false;
	    }
	    return true;
	}
	point List[10005];
	bool _cmp(point p1,point p2)
	{
	    double tmp = (p1-List[0])^(p2-List[0]);
	    if(sgn(tmp) > 0)return true;
	    else if(sgn(tmp) == 0 && sgn(dist(p1,List[0]) - dist(p2,List[0])) <= 0)
	        return true;
	    else return false;
	}
	//��ƽ�潻��ֱ�ߵ���ߴ�����Ч����
	//�������͸������˳���й�
	bool HPIcmp(Line a,Line b)
	{
	    if(fabs(a.k-b.k)>eps)return a.k < b.k;
	    return ((a.s - b.s)^(b.e - b.s)) < 0;
	}
	Line Q[1005];
	//��һ��λ�����ƽ�潻��ֱ�ߣ��ڶ�����������ֱ���������������������ཻ�Ժ��
	//���õ�ѹջ�����ĸ�������ջ�ж��ٸ�Ԫ��
	void HPI(Line line[], int n, point res[], int &resn)
	{
	    int tot = n;
	    sort(line,line+n,HPIcmp);
	    tot = 1;
	    for(int i = 1; i < n; i++)
	        if(fabs(line[i].k - line[i-1].k) > eps)
	            line[tot++] = line[i];
	    int head = 0, tail = 1;
	    Q[0] = line[0];
	    Q[1] = line[1];
	    resn = 0;
	    for(int i = 2; i < tot; i++)
	    {
	        if(fabs((Q[tail].e-Q[tail].s)^(Q[tail-1].e-Q[tail-1].s))<eps||fabs((Q[head].e-Q[head].s)^(Q[head+1].e-Q[head+1].s)) < eps)
	            return;
	        while(head < tail && (((Q[tail]^Q[tail-1])-line[i].s)^(line[i].e-line[i].s)) > eps)
	            tail--;
	        while(head < tail && (((Q[head]^Q[head+1]) -line[i].s)^(line[i].e-line[i].s)) > eps)
	            head++;
	        Q[++tail] = line[i];
	    }
	    while(head < tail && (((Q[tail]^Q[tail-1]) -Q[head].s)^(Q[head].e-Q[head].s)) > eps)
	        tail--;
	    while(head < tail && (((Q[head]^Q[head-1]) -Q[tail].s)^(Q[tail].e-Q[tail].e)) > eps)
	        head++;
	    if(tail<=head+1)return;
	    for(int i=head;i<tail;i++)
	        res[resn++]=Q[i]^Q[i+1];
	    if(head <tail-1)
	        res[resn++]=Q[head]^Q[tail];
	}
}
using namespace cg;
point p[10005],t[10005];
Line l[10005];
int main()
{
	int n,num=0,cnt=0; 
	cin>>n;
	while(n)
	{
		++cnt;
		for(int i=1;i<=n;++i)p[i].input();
		for(int i=1;i<n;++i)l[i]=Line(p[i+1],p[i]);
		l[0]=Line(p[1],p[n]);
		HPI(l,n,t,num);
		printf("Room #%d:\nSurveillance is ",cnt);
		if(num>1)printf("possible.\n\n");
		else printf("impossible.\n\n");
		cin>>n;
	}
	return 0;
}
