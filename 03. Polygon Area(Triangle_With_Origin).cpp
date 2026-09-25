#include<bits/stdc++.h>
using namespace std ;
using ll = long long ;
const int mod = 1e9+7 ;

/*
    Shoe-Lace Formula baad e ei system e o polygon er area calculation kora
    jay . Ekhane proti duita adjacent point er jonne origin ke third point
    dhore trivuj er khetrofol hishab kora hoy . Shobgula add korar pore answer
    er moddhe kebol polygon er area ta baki thake . Bairer ongsho ta clockwise
    ar anti_clockwise rotation er maddhome erase hoye jay .
*/

int main(){
    ios_base::sync_with_stdio(0) ; cin.tie(0) ;

    int n ; cin >> n ; vector<pair<ll,ll>> co_ordinates(n+1) ;
    for(int i = 0 ; i < n ; i++)
        cin >> co_ordinates[i].first >> co_ordinates[i].second ;

    co_ordinates[n] = co_ordinates[0] ;

    ll area = 0 ;

    for(int i = 0 ; i < n ; i++){
        int x1 = co_ordinates[i].first ;
        int y1 = co_ordinates[i].second ;
        int x2 = co_ordinates[i+1].first ;
        int y2 = co_ordinates[i+1].second ;
// Eita mulbindo soho aro duita bindu niye gothito trivuj er area calculation er formula .
        ll triangle_area = ((x1*1LL*y2)-(y1*1LL*x2)) ;
        area += triangle_area ;
    }

    cout << abs(area) << '\n' ;

    return 0 ;
}
