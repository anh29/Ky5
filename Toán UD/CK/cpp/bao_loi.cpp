#include <bits/stdc++.h>
using namespace std;

struct Point {
    double x, y;
};

double polygonArea(vector<Point> P, int n) {
    double area = 0.0;
    int j = n - 1;
    for (int i = 0; i < n; i++) {
        area += (P[j].x + P[i].x) * (P[j].y - P[i].y);
        j = i;
    }
    return abs(area / 2.0);
}

int orientation(Point p, Point q, Point r) {
    double val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0; // Collinear
    return (val > 0) ? 2 : 1; // Clockwise or Counterclockwise
}

void convexHull(Point points[], int n) {
    if (n < 3) return;

    vector<Point> hull;
    int l = 0;
    for (int i = 1; i < n; i++)
        if (points[i].x < points[l].x)
            l = i;

    int p = l, q;
    do {
        hull.push_back(points[p]);
        q = (p + 1) % n;
        for (int i = 0; i < n; i++) {
            if (orientation(points[p], points[i], points[q]) == 2)
                q = i;
        }
        p = q;
    } while (p != l);

    cout << "Convex Hull vertices: ";
    for (int i = 0; i < hull.size(); i++)
        cout << "(" << hull[i].x << ", " << hull[i].y << "), ";
    cout << endl;

    cout << "Convex Hull Area: " << polygonArea(hull, hull.size()) << endl;
}

int main() {
    Point points[] = {{2, 5}, {3, 7}, {4, 3}, {2, 9},{6, 12},
                      {7, 16}, {8, 3}, {9, 8}, {10, 7}, {11, 12}};
                      
	int n = sizeof(points)/sizeof(points[0]);
    convexHull(points, n);
    return 0;
}

