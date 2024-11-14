#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 
ll MOD = 998244353;
double eps = 1e-12;
void solve(){
    ll n,m,v;
    cin >> n >> m >> v;
    vector<ll> nums(n);
    for (ll i = 0; i < n; i++) cin >> nums[i];
    unordered_map<ll,ll> pre, post;
    pre[0] = -1, post[0] = n;
    vector<ll> pre_sum(n,0), post_sum(n,0);
    pre_sum[0] = nums[0];
    post_sum[n-1] = nums[n-1];
    for (ll i = 1 ; i < n; i++) pre_sum[i] = pre_sum[i-1] + nums[i];
    for (ll i = n - 2; i >= 0; i--) post_sum[i] = post_sum[i+1] + nums[i]; 
    ll tmp = 0, cnt = 0;
    for (ll i = 0 ; i < n; i++){
        tmp += nums[i];
        if (tmp >= v){
            tmp = 0;
            cnt++;
            pre[cnt] = i;
        }
    }
    tmp = 0, cnt = 0;
    for (ll i = n - 1; i >= 0; i--){
        tmp += nums[i];
        if (tmp >= v){
            tmp = 0;
            cnt++;
            post[cnt] = i;
        }
    }
    ll x = 0, y = n-1;
    ll ans = -1;
    ll tot = pre_sum[n-1];
    for (ll i = 0; i <= m; i++){
        ll pre_cnt = i, post_cnt = m - i;
        if(pre.count(pre_cnt) == 0 || post.count(post_cnt) == 0) continue;
        ll pre_ind = pre[pre_cnt], post_ind = post[post_cnt];
        if(pre_ind == -1){
            ans = max(ans, tot - post_sum[post_ind]);
            continue;
        }
        if (post_ind == n){
            ans = max(ans, tot - pre_sum[pre_ind]);
            continue;
        }
        if (pre_ind >= post_ind) continue;
        ans = max(ans, tot - pre_sum[pre_ind] - post_sum[post_ind]);
    }
    cout << ans << endl;
}
int main()
{
    fast_cin();
    
    #ifdef LOCAL
        // 本地调试时使用文件输入输出
        ifstream infile("../in&out/data.in");
        ofstream outfile("../in&out/data.out");

        // 检查文件是否成功打开
        if (!infile || !outfile) {
            cerr << "Unable to open input/output file." << endl;
            return 1; // 返回错误码
        }

        // 将标准输入输出重定向到文件
        cin.rdbuf(infile.rdbuf());
        cout.rdbuf(outfile.rdbuf());
    #endif
    
    ll t = 1;
    cin >> t;
    while(t--) {
        solve();
    }

    #ifdef LOCAL
        // 关闭文件流
        infile.close();
        outfile.close();
    #endif
    return 0;
}