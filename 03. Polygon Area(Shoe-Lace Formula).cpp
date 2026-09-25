#include<bits/stdc++.h>
using namespace std ;
using ll = long long ;
const int mod = 1e9+7 ;

int main(){
    ios_base::sync_with_stdio(0) ; cin.tie(0) ;

    int n ; cin >> n ; vector<pair<ll,ll>> co_ordinates(n+1) ;
    for(int i = 0 ; i < n ; i++)
        cin >> co_ordinates[i].first >> co_ordinates[i].second ;

    co_ordinates[n] = co_ordinates[0] ;

    ll plus = 0 , minus = 0 ;

    for(int i = 0 ; i < n ; i++){
        plus += co_ordinates[i].first * co_ordinates[i+1].second ;
        minus += co_ordinates[i].second * co_ordinates[i+1].first;
    }

    ll area = abs(plus-minus) ;

    cout << area << '\n' ;

    return 0 ;
}
