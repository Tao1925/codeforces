#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 
ll MOD = 998244353;
double eps = 1e-12;

vector<string> read_file(string file_name){
    ifstream infile(file_name);
    int sz = 24*24*24;
    vector<string> ans;
    while(sz--){
        string result;
        infile >> result;
        if (result == "YES"){
            int n;
            infile >> n;
            n*=2;
            string s;
            while(n--) infile >> s;
        }
        ans.push_back(result);
        // if (sz % 1000 == 0) cout << sz << endl;
    }
    infile.close();
    return ans;
}
void solve(){
    vector<string> result1 = read_file("data.out");
    vector<string> result2 = read_file("data.out.bak2");
    // cout << "parse end" << endl;
    for (int i = 0; i < 24 * 24 * 24; i++){
        if (result1[i] != result2[i]){
            cout << i << endl;
            cout << "1 = " << result1[i] << " 2 = " << result2[i] << endl;
            break;
        }
    }
    cout << "end" << endl;
}
int main()
{
    fast_cin();
    ll t = 1;
    //cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}