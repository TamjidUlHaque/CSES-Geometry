#include<bits/stdc++.h>
using namespace std ;
using ll = long long ;
const int mod = 1e9+7 ;

int where_is_the_point(int x1 , int y1 , int x2 , int y2 , int x3 , int y3){
    ll slope_difference = ((y2-y1)*1LL*(x3-x1)) - ((x2-x1)*1LL*(y3-y1)) ;
    if(slope_difference==0) return 0 ;
    else if(slope_difference>0) return 1 ;
    else return -1 ;
}

void solve(){

    ll x1 , y1 , x2 , y2 , x3 , y3 ;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 ;

    int location = where_is_the_point(x1,y1,x2,y2,x3,y3) ;

    if(location==0) cout << "TOUCH" ;
    else if(location==-1) cout << "LEFT" ;
    else cout << "RIGHT" ;

    cout << endl ;
}

int main(){
    ios_base::sync_with_stdio(0) ; cin.tie(0) ;

    int test = 1 ;

    cin >> test ;

    while(test--)
        solve() ;

    return 0 ;
}
