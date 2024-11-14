#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 
ll MOD = 998244353;
double eps = 1e-12;

ofstream outfile;


std::vector<std::vector<int>> permute(int n) {
    std::vector<std::vector<int>> result;
    std::vector<int> nums;
    
    // 初始化数组 {1, 2, 3, ..., n}
    for (int i = 1; i <= n; ++i) {
        nums.push_back(i);
    }

    // 使用回溯法生成全排列
    std::function<void(int)> backtrack = [&](int start) {
        if (start == n) {
            result.push_back(nums);
            return;
        }
        for (int i = start; i < n; ++i) {
            std::swap(nums[start], nums[i]);
            backtrack(start + 1);
            std::swap(nums[start], nums[i]);  // 回溯
        }
    };

    backtrack(0);
    return result;
}

void output_vector(vector<int>& vec){
    for (auto& it: vec) outfile << it << ' ';
    outfile << endl;
}

void solve(){
    int cases = 24 * 24 * 24;
    outfile << cases << endl;

    vector<vector<int>> per1 = permute(4);
    for (auto& it1: per1){
        vector<vector<int>> per2 = permute(4);
        for (auto& it2: per2){
            vector<vector<int>> per3 = permute(4);
            for (auto& it3: per3){
                outfile << 4 << endl;
                output_vector(it1);
                output_vector(it2);
                output_vector(it3);
            }
        }
    }
    
}


int main()
{
    outfile = ofstream("./data.in");
    if (!outfile) {
        cerr << "Unable to open input/output file." << endl;
        return 1; // 返回错误码
    }
    fast_cin();
    ll t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
    outfile.close();
    return 0;
}