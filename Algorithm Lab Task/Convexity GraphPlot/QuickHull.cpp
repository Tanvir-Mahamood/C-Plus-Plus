/*
Quick Hull

Run this program. Copy the output.
Paste it to https://colab.research.google.com/drive/152F37JNslwAncSeQw1lkwQMeP_gVMoe-#scrollTo=UC_gZd-U81RD
to observe these points in graph.
*/

#include<bits/stdc++.h>
using namespace std;
#define nn  "\n"
#define PI 3.141592654
//Quick Hull
set<pair<int, int>> hull;

int findSide(pair<int, int> p1, pair<int, int> p2, pair<int, int> p)
{
    int val = (p.second - p1.second) * (p2.first - p1.first) - (p2.second - p1.second) * (p.first - p1.first);

    if(val > 0) return 1;
    if(val < 0) return -1;
    return 0;
}

int lineDist(pair<int, int> p1, pair<int, int> p2, pair<int, int> p)
{
    return abs ((p.second - p1.second) * (p2.first - p1.first) - (p2.second - p1.second) * (p.first - p1.first));
}

void quickHull(pair<int, int> a[], int n, pair<int, int> p1, pair<int, int> p2, int side)
{
    int ind = -1;
    int max_dist = 0;

    for(int i=0; i<n; i++)
    {
        int temp = lineDist(p1, p2, a[i]);
        if(findSide(p1, p2, a[i]) == side && temp > max_dist)
        {
            ind = i;
            max_dist = temp;
        }
    }

    if (ind == -1)
    {
        hull.insert(p1);
        hull.insert(p2);
        return;
    }

    quickHull(a, n, a[ind], p1, -findSide(a[ind], p1, p2));
    quickHull(a, n, a[ind], p2, -findSide(a[ind], p2, p1));
}

void printHull(pair<int, int> a[], int n)
{
    if (n < 3)
    {
        cout << "Convex hull not possible\n";
        return;
    }

    int min_x = 0, max_x = 0;
    for (int i=1; i<n; i++)
    {
        if (a[i].first < a[min_x].first) min_x = i;
        if (a[i].first > a[max_x].first) max_x = i;
    }

    quickHull(a, n, a[min_x], a[max_x], 1);
    quickHull(a, n, a[min_x], a[max_x], -1);

    vector<pair<int,int>> result;
    while (!hull.empty())
    {
        //cout << "(" <<( *hull.begin()).first << ", " << (*hull.begin()).second << ") ";
        result.push_back({( *hull.begin()).first, ( *hull.begin()).second});
        hull.erase(hull.begin());
    }

    int ymin = result[0].second, minn = 0;
    for (int i = 1; i < result.size(); i++)
    {
        int yyy = result[i].second;
        if ((result[i].second < ymin) || (ymin == result[i].second && result[i].first < result[minn].first)) ymin = result[i].second, minn = i;
    }
    swap(result[0], result[minn]); //Reference Point to sort

    vector<pair<double,pair<int,int>>> sort_result ;
    for(int i=1; i<result.size(); i++)
    {
        double y_p = result[0].second - result[i].second;
        double x_p = result[0].first - result[i].first;

        double angle = (atan2 (y_p,x_p)*180/PI) ;
        angle += (angle<0) * 360 ;
        sort_result.push_back ({angle,{result[i].first, result[i].second}});
    }
    sort(sort_result.begin(), sort_result.end()); //counterclockwise sort : https://ideone.com/fork/MXtcfD

    cout << "x = [" << result[0].first << ", ";
    for(int i=0; i<sort_result.size(); i++) cout << sort_result[i].second.first << ","; cout << result[0].first;
    cout << "]\ny = [" << result[0].second << ", ";
    for(int i=0; i<sort_result.size(); i++) cout << sort_result[i].second.second << ","; cout << result[0].second;
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
    n=500; // How many points
    pair<int,int> a[n];
    int l = -1000, r =1000;
    vector<int> v1, v2;
    for(i=0; i<n; i++)
    {
        //cin >> xx >> yy;

        xx = gen_random(l, r);
        yy = gen_random(l, r);

        v1.push_back(xx);
        v2.push_back(yy);


        a[i].first = xx;
        a[i].second = yy;
    }

    cout << "X = [";
    for(i=0; i<n; i++) cout << v1[i] << ",";
    cout << "]\nY = [";
    for(i=0; i<n; i++) cout << v2[i] << ",";
    cout << "]\n\n";

    printHull(a, n);

    endd = clock();
    double time_taken = double(endd - start) / double(CLOCKS_PER_SEC);
	cout << "Time: " << fixed << time_taken << setprecision(5);
	cout << " sec " << endl;

    return 0;
}

/*
10
8 33
11 88
97 33
20 29
14 81
17 44
65 95
84 89
16 59
70 23
*/
