#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 
ll MOD = 998244353;
double eps = 1e-12;
ll solve(){
    ll n,b,c;
    cin >> n >> b >> c;
    ll ans = 0;
    if (b == 0){
        if (n - c > 2) return -1;
        else if (n - c == 2 || n - c == 1) return n - 1;
        else return n;
    }
    if (c > n - 1) return n;
    ans = n - ((n - 1 - c) / b + 1);
    return ans;
}
int main()
{
    fast_cin();
    ll t;
    cin >> t;
    while(t--) {
        ll ans = solve();
        cout << ans << endl;
    }
    return 0;
}