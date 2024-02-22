#include <bits/stdc++.h>
#include <random>
#define llu long long int
using namespace std;

struct Point {
	llu x, y;
	bool operator<(Point p){
		return x < p.x || (x == p.x && y < p.y);
	}
};

void Input(vector<Point>& points, int n) {
    points.resize(n);
    mt19937 gen(123); 
    uniform_int_distribution<int> dis(1, 10); 
    for (int i = 0; i < n; i++) {
        points[i].x = dis(gen);
        points[i].y = dis(gen);
    }
}


void Output(const vector<Point> &points) { 
        cout << "Points:" << endl;
    for (int i = 0; i < points.size(); i++) {
        cout << "(" << points[i].x << ", " << points[i].y << ")" << "; ";
    }
    
}

llu cross_product(Point O, Point A, Point B){
	return (A.x - O.x) * (B.y - O.y)
		- (A.y - O.y) * (B.x - O.x);
}

vector<Point> convex_hull(vector<Point> A){
	int n = A.size(), k = 0;
	if (n <= 3)
		return A;

	vector<Point> ans(2 * n);

	sort(A.begin(), A.end());

	for (int i = 0; i < n; ++i) {
		while (k >= 2 && cross_product(ans[k - 2], ans[k - 1], A[i]) <= 0)
			k--;
			ans[k++] = A[i];
	}

	for (size_t i = n - 1, t = k + 1; i > 0; --i) {
		while (k >= t && cross_product(ans[k - 2], ans[k - 1], A[i - 1]) <= 0)
			k--;
			ans[k++] = A[i - 1];
	}
	ans.resize(k - 1);
	return ans;
}
// Tinh dien tich bao loi
double area_convexhull(const vector<Point> &points) {
    double area = 0.0;
    int n = points.size();
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        area += (double)(points[i].x * points[j].y - points[j].x * points[i].y);
    }
    return abs(area) / 2.0;
}

// Khoang cach tu mot diem den mot doan thang
double pointToLine_distance(Point A, Point B, Point P) {
    return abs((B.x - A.x) * (A.y - P.y) - (A.x - P.x) * (B.y - A.y)) / sqrt(pow(B.x - A.x, 2) + pow(B.y - A.y, 2));
}
double cal_distance(Point p1, Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}


bool isInsideConvexHull(const vector<Point>& convexHull, Point p) {
    int n = convexHull.size();
    if (n < 3) return false;

    int count = 0;
    for (int i = 0, j = n - 1; i < n; j = i++) {
        if (((convexHull[i].y > p.y) != (convexHull[j].y > p.y) &&
            (p.x < (convexHull[j].x - convexHull[i].x) * (p.y - convexHull[i].y) / (convexHull[j].y - convexHull[i].y) + convexHull[i].x))) {
            count++;
        }
    }
    return (count % 2 == 1);
}
void listPointsInsideConvexHull(const vector<Point> &convexHull, const vector<Point> &points) {
    cout << "Diem ben trong bao loi :" << endl;
    int n = points.size();
    for (int i = 0; i < n; i++) {
        if (isInsideConvexHull(convexHull, points[i])) {
            bool isOnConvexHull = false;
            for (const Point &p : convexHull) {
                if (p.x == points[i].x && p.y == points[i].y) {
                    isOnConvexHull = true;
                    break;
                }
            }
            if (!isOnConvexHull) {
                cout << "(" << points[i].x << ", " << points[i].y << ")" << endl;
            }
        }
    }
}
// Tim cap diem gan nhat trong bao loi 
void closest_points(const vector<Point> &points) {
    vector<Point> convex_hull_points = convex_hull(points);
    int n = convex_hull_points.size();
    double min_distance = DBL_MAX;
    Point closest_point1, closest_point2;

    for (int i = 0; i < n; i++) {
        Point p1 = convex_hull_points[i];
        Point p2 = convex_hull_points[(i + 1) % n];
        double distance = cal_distance(p1, p2);

        if (distance < min_distance) {
            min_distance = distance;
            closest_point1 = p1;
            closest_point2 = p2;
        }
    }

    cout << "Cap diem gan nhat ben trong bao loi là: " << "(" << closest_point1.x << ", " << closest_point1.y << ")"<< " và " << "(" << closest_point2.x << ", " << closest_point2.y << ")" << endl;
    cout << "Khoang cach gan nhat la: " << min_distance << endl;
}
int main(){
    cout << "Thuat toan : MonotoneChain "<<endl;
	int n;
    cout << "Nhap vao so diem: ";
    cin >> n;
    vector<Point> points;
    Input(points, n);
    cout << "Cac diem vua nhap la: \n"; 
    Output(points);
    cout << "\nCac diem bao loi la: \n";
    vector<Point> ans = convex_hull(points);
    Output(ans);
    cout << "\n Dien tich cua bao loi la: " << area_convexhull(ans) << endl;
    closest_points(ans);
    
    listPointsInsideConvexHull(ans, points);
    return 0;
}

