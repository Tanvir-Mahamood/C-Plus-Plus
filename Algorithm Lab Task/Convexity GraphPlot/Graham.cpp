/*
Graham Scan

Run this program. Copy the output.
Paste it to https://colab.research.google.com/drive/152F37JNslwAncSeQw1lkwQMeP_gVMoe-#scrollTo=UC_gZd-U81RD
to observe these points in graph.
*/

#include <bits/stdc++.h>
using namespace std;
#define nn  "\n"
//graham scan
struct Point
{
    int x, y;
};

Point p0;

Point nextToTop(stack<Point> &S)
{
    Point p = S.top();
    S.pop();
    Point res = S.top();
    S.push(p);
    return res;
}

void swap(Point &p1, Point &p2)
{
    Point temp = p1;
    p1 = p2;
    p2 = temp;
}

int distSq(Point p1, Point p2)
{
    return (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y);
}

// To find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 --> p, q and r are collinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0;
    return (val > 0)? 1: 2;
}

int compare(const void *vp1, const void *vp2)
{
    Point *p1 = (Point *)vp1;
    Point *p2 = (Point *)vp2;

    int o = orientation(p0, *p1, *p2);
    if (o == 0) return (distSq(p0, *p2) >= distSq(p0, *p1))? -1 : 1;
    return (o == 2)? -1: 1;
}

void convexHull(Point points[], int n)
{
    int ymin = points[0].y, minn = 0;
    for (int i = 1; i < n; i++)
    {
        int y = points[i].y;
        if ((y < ymin) || (ymin == y && points[i].x < points[minn].x)) ymin = points[i].y, minn = i;
    }

    swap(points[0], points[minn]);

    p0 = points[0];
    qsort(&points[1], n-1, sizeof(Point), compare);

    int m = 1;
    for (int i=1; i<n; i++)
    {
        while (i < n-1 && orientation(p0, points[i], points[i+1]) == 0) i++;
        points[m] = points[i];
        m++;
    }
    if (m < 3) return;

    stack<Point> S;
    S.push(points[0]);
    S.push(points[1]);
    S.push(points[2]);

    for (int i = 3; i < m; i++)
    {
        while (S.size()>1 && orientation(nextToTop(S), S.top(), points[i]) != 2) S.pop();
        S.push(points[i]);
    }

    vector<int> vx, vy;
    while (!S.empty())
    {
        Point p = S.top();
        vx.push_back(p.x);
        vy.push_back(p.y);
        S.pop();
    }
    cout << "x = [";
    for(int i=0; i<vx.size(); i++) cout << vx[i] << ","; cout << vx[0];
    cout << "]\ny = [";
    for(int i=0; i<vy.size(); i++) cout << vy[i] << ","; cout << vy[0];
    cout << "]\n";
}

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
inline int gen_random(int l, int r)
{
    return uniform_int_distribution<int>(l, r)(rng);
}

int main()
{
    clock_t start, endd;
    start = clock();

    int n, i, xx, yy;
    //cin >> n;
    n = 500; // How many points
    Point points[n];
    int l = -1000, r =1000;
    vector<int> v1, v2;
    for(int i=0; i<n; i++)
    {
        xx = gen_random(l, r);
        yy = gen_random(l, r);

        v1.push_back(xx);
        v2.push_back(yy);

        points[i].x = xx;
        points[i].y = yy;
    }

    cout << "X = [";
    for(i=0; i<n; i++) cout << v1[i] << ",";
    cout << "]\nY = [";
    for(i=0; i<n; i++) cout << v2[i] << ",";
    cout << "]\n\n";

    convexHull(points, n);
    endd = clock();
    double time_taken = double(endd - start) / double(CLOCKS_PER_SEC);
	cout << "Time: " << fixed << time_taken << setprecision(5);
	cout << " sec " << endl;
    return 0;
}




