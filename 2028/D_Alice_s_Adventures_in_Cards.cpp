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
bool end_flag = false;
vector<int> cur_max(3);
vector<int> tar(3);
int vis[3][MA];
stack<pair<int, int>> st;
stack<pair<int, int>> ans;
 
char to_c(int a){
    if (a == 0) return 'q';
    if (a == 1) return 'k';
    if (a == 2) return 'j';
    return 'a';
}
 
void dfs(int usr, int cur){
    cout << "dfs(" << usr << "," << cur << ")" << endl;
    if (end_flag) return;
    if (vis[usr][cur] == 1) return;
    vis[usr][cur] = 1;

    if (dat[usr][cur] > tar[usr]){
        st.push(make_pair(usr, n));
        ans = st;
        end_flag = true;
        return;
    }

    int cur_data = dat[usr][cur];
    if (cur_data < cur_max[usr])
        return;
    

    for (int i = cur_max[usr] + 1; i < cur_data; i++){
        int index = ind[usr][i];
        if (index < cur) continue;
        for (int j = 0; j < 3; j++){
            if (j == usr) continue;
            st.push(make_pair(usr, index));
            dfs(j, index);
            st.pop();
        }
    }

    cur_max[usr] = cur_data;

    /*
    for (int i = 0; i < 3; i++){
        // cout << "cur = " << cur << " i = " << i << endl;
        if (dat[i][cur] <= ccur_max[i]) continue;
        // cout << "cur = " << cur << " i = " << i << endl;
        for (int j = ccur_max[i] + 1; j < dat[i][cur]; j++){
            int index = ind[i][j];
            if (index < cur) continue;
            st.push(make_pair(i, index));
            // cout << "i = " << i << "index = " << index << endl;
            dfs(index);
            st.pop();
        }
        cur_max[i] = max(dat[i][cur], cur_max[i]);
    }
    */
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

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < n; j++)
             vis[i][j] = 0;
    for (int i = 0; i < 3; i++) cur_max[i] = -1;
    for (int i = 0; i < 3; i++) tar[i] = dat[i][n - 1];

    dfs(0, 0);
    dfs(1, 0);
    dfs(2, 0);

    if (end_flag){
        cout << "YES" << endl;
        vector<pair<int, int>> st_r;
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

    #ifdef LOCAL
        cout << std::filesystem::current_path()  << endl;
        // 本地调试时使用文件输入输出
        ifstream infile("../../io/data.in");
        ofstream outfile("../../io/data.out");
        cout << "hello in&out" << endl;
        // 检查文件是否成功打开
        if (!infile || !outfile) {
            cerr << "Unable to open input/output file." << endl;
            return 1; // 返回错误码
        }
        cout << "hello file" << endl;
        // 将标准输入输出重定向到文件
        cin.rdbuf(infile.rdbuf());
        cout.rdbuf(outfile.rdbuf());
        // cout << "hello out file" << endl;
    #else
        fast_cin();
    #endif

    ll t;
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