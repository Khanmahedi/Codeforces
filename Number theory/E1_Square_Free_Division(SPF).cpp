
#include<bits/stdc++.h>
#pragma GCC target("popcnt")
using namespace std;
#define ll       long long
#define pb      push_back
#define TT ll time;        cin >> time; while(time--)
#define FastIo  ios_base::sync_with_stdio(false);cin.tie(NULL) ;
#ifndef ONLINE_JUDGE
#include "algodebug.h"
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
const ll int INF = 9223372036854775807 , nmax = 2501 , block = 350 , N = 2e5+20 ;

const ll MAXN = 1e7 ;
vector < ll > primes ;
ll spf[MAXN + 1] , vis[MAXN + 100] ;
int main(){
    FastIo ;

    for( ll i = 2 ; i <= MAXN ; i++){
        if(spf[i] == 0){
            primes.pb(i) ;
            spf[i] = i ;
        }
        for(auto it: primes){
            if(it > spf[i] or it * i > MAXN) break ;
            spf[it * i] = it ;
        }
    }

    vis[1] = 1 ;
    ll mx = 0 ;
     for( ll i = 2 ; i <=  MAXN ; i++){
            ll x = i ;
            
            ll last = 0 , cnt = 0 , ans = 1 ;
            while(x > 1){
                if(last == spf[x]){
                    cnt = cnt*last ;
                }
                else{
                    if(last != 0){
                        cnt = cnt * last ;
                        cnt = cnt - 1 ;
                        cnt = cnt/(last - 1) ;
                        ans = ans*cnt ;
                    }
                    last = spf[x] ;
                    cnt = spf[x] ;
                }
                x = x/last ;
            }




                cnt = cnt * last ;
                cnt = cnt - 1 ;
                cnt = cnt/(last - 1) ;
                ans = ans*cnt ;
          
             if(ans <= MAXN) {
                if(!vis[ans])
                vis[ans] = i ;
            }

        }


    TT{

       
         ll n ;
         cin >>  n; 
         if(!vis[n]) cout << "-1" << endl ;
         else cout << vis[n] << endl ;

        
        

}
}
