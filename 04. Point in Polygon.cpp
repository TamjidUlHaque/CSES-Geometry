#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9+7;
#define sesh '\n'
#define gap ' '
#define F first
#define S second
#define pii pair<ll,ll>
#define vii vector<pii>

int where_is_the_point(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
    ll slope_difference = ((y2-y1) * 1LL * (x3-x1)) - ((x2-x1) * 1LL * (y3-y1));
    if (slope_difference == 0) return 0;
    else if (slope_difference > 0) return 1;
    else return -1;
}

bool onSegment(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
    return min(x1, x2) <= x3 && x3 <= max(x1, x2) &&
           min(y1, y2) <= y3 && y3 <= max(y1, y2);
}

bool doIntersect(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3, ll x4, ll y4) {
    int location1 = where_is_the_point(x1, y1, x2, y2, x3, y3);
    int location2 = where_is_the_point(x1, y1, x2, y2, x4, y4);
    int location3 = where_is_the_point(x3, y3, x4, y4, x1, y1);
    int location4 = where_is_the_point(x3, y3, x4, y4, x2, y2);

    // Jodi purapuri intersect kore tahole ekta line er duita point arekline
    // er dui side e obosthan korbe .
    if (location1 != location2 && location3 != location4) return true;

/*    // Jodi kuno ekta point arek sorolrekher thik upore obosthan kore .
    if (location1 == 0 && onSegment(x1, y1, x2, y2, x3, y3)) return true;
    if (location2 == 0 && onSegment(x1, y1, x2, y2, x4, y4)) return true;
    if (location3 == 0 && onSegment(x3, y3, x4, y4, x1, y1)) return true;
    if (location4 == 0 && onSegment(x3, y3, x4, y4, x2, y2)) return true;
 */
    return false;
}

int point_location_in_polygon(pii curPoint, const vii &vertices) {
    ll x = curPoint.F, y = curPoint.S;
    int n = vertices.size();
    int intersect_cnt = 0;

    pii farPoint = {1000000007LL, y}; // far right ray

    for (int i = 0; i < n; i++) {
        pii a = vertices[i];
        pii b = vertices[(i+1)%n];

        // Boundary check
        if (where_is_the_point(a.F, a.S, b.F, b.S, x, y) == 0 &&
            onSegment(a.F, a.S, b.F, b.S, x, y)) {
            return 0; // boundary
        }

        // Skip horizontal edges
        if (a.S == b.S) continue;

        // Count intersection with ray
        if (doIntersect(a.F, a.S, b.F, b.S, x, y, farPoint.F, farPoint.S)) {
            // Extra condition: only count if the edge actually crosses the ray
            if ((a.S > y) != (b.S > y)) {
                intersect_cnt++ ;
            }
        }
    }

    return (intersect_cnt % 2 == 1) ? 1 : -1;
}

void solve() {

    int n , query ; cin >> n >> query ;
    vii vertices(n) ;

    for(int i = 0 ; i < n ; i++)
        cin >> vertices[i].F >> vertices[i].S ;

    while(query-- > 0){
        pii curPoint;
        cin >> curPoint.F >> curPoint.S;

        int res = point_location_in_polygon(curPoint, vertices);
        if (res == 0) cout << "BOUNDARY" << sesh;
        else if (res == 1) cout << "INSIDE" << sesh;
        else cout << "OUTSIDE" << sesh;
    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int test = 1;
    //cin >> test;

    while (test--) solve();

    return 0;
}
