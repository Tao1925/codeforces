#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 
ll MOD = 998244353;
double eps = 1e-12;

int n;
const int MA = 2e5+3;
int dat[3][MA];
int ind[3][MA];
int cur_max[3];
int av[MA];
stack<pair<int, int>> st;
stack<pair<int, int>> ans;

char to_c(int a){
    if (a == 0) return 'q';
    if (a == 1) return 'k';
    if (a == 2) return 'j';
    return 'a';
}

void dfs(int cur){
    if (av[cur] == 1) return;
    av[cur] = 1;
    if (cur == n - 1) {ans = st; return;}
    for (int i = 0; i < 3; i++){
        if (dat[i][cur] <= cur_max[i]) continue;
        for (int j = cur_max[i] + 1; j < dat[i][cur]; j++){
            int index = ind[i][j];
            if (index < cur) continue;
            st.push(make_pair(i, index));
            dfs(index);
            st.pop();
        }
        cur_max[i] = dat[i][cur];
    }
}

void solve(){
    cin >> n;
    for (int i = 0 ; i < 3; i++){
        for (int j = 0; j < n; j++){
            int d; cin >> d; d--;
            dat[i][j] = d;
            ind[i][d] = j;
        }
    }
    for (int i = 0; i < n; i++) av[i] = 0;
    for (int i = 0; i < 3; i++) cur_max[i] = -1;
    dfs(0);
    if (av[n - 1] == 1){
        cout << "YES" << endl;
        vector<pair<char, int>> st_r;
        while(!ans.empty()){
            st_r.push_back(ans.top());
            ans.pop();
        }
        cout << st_r.size() << endl;
        reverse(st_r.begin(), st_r.end());
        for (auto& it: st_r){
            cout << to_c(it.first) << ' ' << it.second + 1 << endl;
        }
    }else cout << "NO" << endl;
}
int main()
{
    fast_cin();
    ll t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}