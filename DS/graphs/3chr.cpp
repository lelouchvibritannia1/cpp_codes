 #include "bits/stdc++.h"
// #include<iostream>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

using namespace std;

#define int long long int
#define double long double
typedef pair<int,int> p64;
typedef pair<double,double> pdd;
typedef vector<int> v64;
typedef vector<vector<int> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
int MOD = 1e9 + 7;
double eps = 1e-8;
int MAX=1e5;
#define G(x) int x; cin >> x
#define GS(x) string x; cin >> x
#define F(i,l,r) for(int i=l;i<r;i++)
#define FD(i,r,l) for(int i=r;i>l;i--)
#define CO(x) cout << x << '\n'
#define CO_(x) cout << x << ' '
#define GA(x,n) v64 x(n); F(i,0,n) cin >> x[i]
#define CA(x,n) F(i,0,n) {CO_(x[i]);} cout << '\n'
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)



void init_code(){
    fast_cin();
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif

}



/*this here is code */

struct Point
{
    int x, y;
};

// Orientation of three points (p, q, r)
int orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0)
        return 0;             // Collinear
    return (val > 0) ? 1 : 2; // Clockwise or Counterclockwise
}

// Compare function for sorting points by polar angle
bool comparePolarAngle(Point p1, Point p2)
{
    int o = orientation(Point{0, 0}, p1, p2);
    if (o == 0) // Collinear points, choose the one closer to the origin
        return (p1.x * p1.x + p1.y * p1.y) < (p2.x * p2.x + p2.y * p2.y);
    return (o == 2); // Counter-clockwise, sort in descending order of polar angle
}

// Find convex hull using Graham scan algorithm
vector<Point> convexHull(vector<Point> &points)
{
    int n = points.size();
    if (n <= 3)
        return points;

    // Find the point with the lowest y-coordinate (and leftmost in case of ties)
    int minY = points[0].y, minIndex = 0;
    for (int i = 1; i < n; ++i)
    {
        int y = points[i].y;
        if ((y < minY) || (y == minY && points[i].x < points[minIndex].x))
        {
            minY = y;
            minIndex = i;
        }
    }

    // Swap the lowest point with the first point
    swap(points[0], points[minIndex]);

    // Sort the remaining points based on polar angle
    sort(points.begin() + 1, points.end(), comparePolarAngle);

    // Initialize the convex hull with the first two points
    vector<Point> hull = {points[0], points[1]};

    // Build the convex hull
    for (int i = 2; i < n; ++i)
    {
        while (hull.size() >= 2 && orientation(hull[hull.size() - 2], hull[hull.size() - 1], points[i]) != 2)
            hull.pop_back();
        hull.push_back(points[i]);
    }

    return hull;
}

// Calculate centroid of a set of points
Point calculateCentroid(const vector<Point> &points)
{
    int n = points.size();
    int sumX = 0, sumY = 0;
    for (const Point &p : points)
    {
        sumX += p.x;
        sumY += p.y;
    }
    Point centroid;
    centroid.x = sumX / n;
    centroid.y = sumY / n;
    return centroid;
}

int32_t main()
{
    int N;
    cin >> N;

    vector<Point> frontLeft, frontRight, backLeft, backRight;
    for (int i = 0; i < N; ++i)
    {
        int x, y;
        cin >> x >> y;
        if (x >= 0 && y >= 0)
            frontRight.push_back({x, y});
        else if (x < 0 && y >= 0)
            frontLeft.push_back({x, y});
        else if (x < 0 && y < 0)
            backLeft.push_back({x, y});
        else
            backRight.push_back({x, y});
    }

    int speakerCount = 0;
    if (!frontLeft.empty())
        ++speakerCount;
    if (!frontRight.empty())
        ++speakerCount;
    if (!backLeft.empty())
        ++speakerCount;
    if (!backRight.empty())
        ++speakerCount;

    cout << speakerCount << endl;

    return 0;
}

/*which ends here*/
