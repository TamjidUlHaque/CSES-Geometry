#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std ;
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define Bismillah() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef vector<long long> vll ;
#define pb push_back
#define infinity LLONG_MAX
#define aura LLONG_MIN
#define F first
#define S second
#define sesh '\n'
#define gap ' '

#define len(x) int((x).size())
#define all(n) n.begin(), n.end()
#define nsort(v) sort(v.begin(),v.end());
#define rsort(v) sort(v.rbegin(),v.rend());
#define flip(v) reverse(v.begin(),v.end());


#define Sum(a)     ( accumulate ((a).begin(), (a).end(), 0ll))
#define Boro(vec) *(max_element(vec.begin(),vec.end()))
#define Chuto(vec) *(min_element(vec.begin(),vec.end()))
#define minidx(a)    ( min_element((a).begin(), (a).end()) - (a).begin())
#define maxidx(a)    ( max_element((a).begin(), (a).end()) - (a).begin())

void IcpcDhakaRegionalist2025(){
    ll x1 , y1 , x2 , y2 , x3 , y3 ;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 ;

    ll area = ((x1*y3+x3*y2+x2*y1)-(y1*x3+y3*x2+y2*x1)) ;

    if(area==0) cout << "TOUCH" << sesh ;
    else if(area > 0) cout << "RIGHT" << sesh ;
    else cout << "LEFT" << sesh ;

}

int main(){
    Bismillah() ;

    int testcase = 1 ;

    cin >> testcase ;

    for(int tc = 1 ; tc <= testcase ; tc++){
        //cout << "Case " << tc << ": " ;
        IcpcDhakaRegionalist2025() ;
    }

    return 0 ;
}
