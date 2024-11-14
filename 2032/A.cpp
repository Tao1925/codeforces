#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    n--;
    auto ask = [&](int x, int y) -> int {
        cout << "? " << x << " " << y << endl;
        int op;
        cin >> op;
        return op;
    };
    int r = 2;
    while(ask(1, r)){
        r++;
    }
    vector<int> fa(n + 1);
    for (int i = 1; i < r; i++){
        fa[i] = 0;
    }
    fa[r] = 1;
    int z = 1;
    for (int i = r + 1; i <= n; i++){
        while(ask(r, i)){
            r = ++z;
        }
        fa[i] = r;
        r = i;
    }
    cout << "! ";
    for (int i = 1; i <= n; i++) cout << fa[i] << " ";
    cout << endl;
}
int main(){
    // freopen("furniture.in","r",stdin);
    // freopen("furniture.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    solve();
}
