#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 
ll MOD = 998244353;
double eps = 1e-12;
void solve(){
    cout << "hello world" << endl;
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