#include<bits/stdc++.h>
using namespace std;
struct res {
	double x1, y_1, x2, y2, dis;
	bool operator<(const res& b) const {
		return this->dis < b.dis;
	}
};
double ansx, dis;
double sq(double x) {
    return x * x;
}
double A, B, X1, Y1, X2, Y2;
double x1, y_1, x2, y2;
double Rand() { return (double)rand() / RAND_MAX; }
double calcdis(double xx, bool X) {
	if (X) return min(
			sqrt(sq(x1-xx)+sq(y_1-y2)), min(
			sqrt(sq(x1-X1)+sq(y_1-Y1))+sqrt(sq(xx-X2)+sq(y2-Y2)),
			sqrt(sq(x1-X2)+sq(y_1-Y2))+sqrt(sq(xx-X1)+sq(y2-Y1))
		));
	else return min(
			sqrt(sq(x1-x2)+sq(y_1-xx)), min(
			sqrt(sq(x1-X1)+sq(y_1-Y1))+sqrt(sq(x2-X2)+sq(xx-Y2)),
			sqrt(sq(x1-X2)+sq(y_1-Y2))+sqrt(sq(x2-X1)+sq(xx-Y1))
		));
}
double calc(double xx, bool X) {
//	cout << "calc" <<xx << '\n';
	if (X) {
		double ret = min(
			sqrt(sq(x1-xx)+sq(y_1-y2)), min(
			sqrt(sq(x1-X1)+sq(y_1-Y1))+sqrt(sq(xx-X2)+sq(y2-Y2)),
			sqrt(sq(x1-X2)+sq(y_1-Y2))+sqrt(sq(xx-X1)+sq(y2-Y1))
		));
		if (ret > dis) dis = ret, ansx = xx;
		return ret;
	} else {
		double ret = min(
			sqrt(sq(x1-x2)+sq(y_1-xx)), min(
			sqrt(sq(x1-X1)+sq(y_1-Y1))+sqrt(sq(x2-X2)+sq(xx-Y2)),
			sqrt(sq(x1-X2)+sq(y_1-Y2))+sqrt(sq(x2-X1)+sq(xx-Y1))
		));
		if (ret > dis) dis = ret, ansx = xx;
		return ret;
	}
	return -1;
}

const double eps = 1e-7;
void sanfen(double l, double r, bool X) {
	calc(l, X);
	calc(r, X);
	while (l + eps < r) {
		double mid = (l + r) / 2;
		if (calcdis(mid, X) < calcdis(mid + eps / 2, X)) l = mid;
		else r = mid;
	}
	if (calcdis(l, X) > dis) dis = calcdis(l, X), ansx = l;
}
void simulateAnneal(bool X) {
	dis = 0.0;
	ansx = 0.0;
	vector<double> vec{0, X?X1:Y1, X?X2:Y2, X?A:B};
	sort(vec.begin(), vec.end());
	for (int i = 0; i < vec.size() - 1; ++i) {
		sanfen(vec[i], vec[i+1], X);
	}
}
res solve(double X, double Y) {
	// up, modify x2
	x1 = X; y_1 = Y; y2 = B;
	dis = calcdis(0, 1);
	//cout << "dis: " << dis << '\n';
	simulateAnneal(1);
	res ret = res{x1, y_1, ansx, y2, calcdis(ansx, 1)};
	// down, x2
	x1 = X; y_1 = Y; y2 = 0;
	dis = calcdis(0, 1);//cout << "dis: " << dis << '\n';
	simulateAnneal(1);
	ret = max(ret, res{x1, y_1, ansx, y2, calcdis(ansx, 1)});
	// left, y2
	x1 = X; y_1 = Y; x2 = 0;
	dis = calcdis(0, 0);//cout << "dis: " << dis << '\n';
	simulateAnneal(0);
	ret = max(ret, res{x1, y_1, x2, ansx, calcdis(ansx, 0)});
	// right, y2
	x1 = X; y_1 = Y; x2 = A;
	dis = calcdis(0, 0);//cout << "dis: " << dis << '\n';
	simulateAnneal(0);
	ret = max(ret, res{x1, y_1, x2, ansx, calcdis(ansx, 0)});
	return ret;
}
int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		printf("Case #%d:\n", t);
	cin >> A >> B >> X1 >> Y1 >> X2 >> Y2;
	res a;
	a.dis = 0;
	a = max(a, solve(0, 0));
//	printf("%.8f %.8f\n%.8f %.8f\n", a.x1, a.y_1,a.x2, a.y2);
	a = max(a, solve(0, B));
//	printf("%.8f %.8f\n%.8f %.8f\n", a.x1, a.y_1,a.x2, a.y2);
	a = max(a, solve(A, B));
//	printf("%.8f %.8f\n%.8f %.8f\n", a.x1, a.y_1,a.x2, a.y2);
	a = max(a, solve(A, 0));
	printf("%.8f %.8f\n%.8f %.8f\n", a.x1, a.y_1,a.x2, a.y2);
	}
	return 0;
}