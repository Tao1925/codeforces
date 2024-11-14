#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 
ll MOD = 998244353;
double eps = 1e-12;
bool solve(){
    int n, a, b;
    cin >> n >> a >> b;
    int x = 0;
    int y = 0;
    string s;
    cin >> s;
    for (int i = 0; i < 15; i++){
        for (char c:s){
            if (c == 'N') y++;
            if (c == 'E') x++;
            if (c == 'W') x--;
            if (c == 'S') y--;
            if (x == a && y == b) return true;
        }
    }
    return false;
}
int main()
{
    fast_cin();
    ll t;
    cin >> t;
    while(t--) {
        bool ans = solve();
        if (ans)
            cout << "YES" << endl;
        else
            cout << "NO" << endl; 
    }
    return 0;
}