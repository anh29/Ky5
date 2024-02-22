#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#define llu long long int
using namespace std;
struct Point
{
llu x, y;
bool operator<(Point p)
{
return x < p.x || (x == p.x && y < p.y);
}
};
llu orientation(Point p, Point q, Point r)
{
int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
if (val == 0)
return 0;
return (val > 0) ? 1 : 2;
}
llu cross_product(Point O, Point A, Point B)
{
return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}
vector<Point> convex_hull_Andrew(vector<Point> A)
{
int n = A.size(), k = 0;
if (n <= 3)
return A;
vector<Point> ans(2 * n);
sort(A.begin(), A.end());
for (int i = 0; i < n; ++i)
{
while (k >= 2 && cross_product(ans[k - 2], ans[k - 1], A[i]) <= 0)
k--;
ans[k++] = A[i];
}
for (size_t i = n - 1, t = k + 1; i > 0; --i)
{
while (k >= t && cross_product(ans[k - 2], ans[k - 1], A[i - 1]) <= 0)
k--;
ans[k++] = A[i - 1];
}
ans.resize(k - 1);
return ans;
}
double polygonArea(vector<Point> points)
{
int n = points.size();
double area = 0.0;
int j = n - 1;
for (int i = 0; i < n; i++)
{
area += (points[j].x + points[i].x) * (points[j].y - points[i].y);
j = i;
}
return abs(area / 2.0);
}
int main()
{
vector<Point> points;
points.push_back({1, 2});
points.push_back({3, 1});
points.push_back({4, 3});
points.push_back({5, 4});
points.push_back({6, 5});
points.push_back({2, 7});
points.push_back({1, 6});
points.push_back({2, 6});
points.push_back({5, 8});
points.push_back({5, 2});
points.push_back({3, 8});
points.push_back({4, 9});
points.push_back({2, 13});
points.push_back({4, 12});
points.push_back({6, 10});
vector<Point> pts = convex_hull_Andrew(points);
cout << "Convex hull:" << endl;
for (int i = 0; i < pts.size(); i++)
cout << "(" << pts[i].x << ", "
<< pts[i].y << ")" << endl;
cout << "Area: " << polygonArea(pts) << endl;
return 0;
}

