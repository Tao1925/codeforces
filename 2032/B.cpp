#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Node{
public:
    vector<int> lis = {0};
    Node* next;
    Node* jump;
    Node(int x){
        lis.push_back(x);
    }
};
Node* gen_node_circle(int lines){
    Node* start = new Node(1);
    Node* var = start;
    for (int i = 2; i <= lines; i++){
        Node* cur = new Node(i);
        var->next = cur;
        var->jump = cur;
        var = cur;
        if (i == lines){
            var->next = start;
            var->jump = start;
        }
    }
    return start;
}
void solve(){

    auto qry = [&](int x, int y) -> int {
        cout << "? " << x << " " << y << endl;
        int op;
        cin >> op;
        return op;
    };


    int n;
    cin >> n;
    int lines = 2;
    // cout << "start qry" <<endl;
    while(qry(1, lines)){
        // cout << "lines = " << lines << endl;
        lines++;
    }
    lines--;
    if (lines == 1){
        cout << "! ";
        for (int i = 0; i < n - 1; i++) cout << i << ' ';
        cout << endl;
        return;
    }
    Node* start = gen_node_circle(lines);
    Node* cur_node = start;
    cur_node->lis.push_back(lines + 1);
    int wait_in = lines + 2;
    int cur_max = 1;
    while(wait_in <= n - 1){
        while(true){
            while(cur_max > cur_node->jump->lis.back()){
                cur_node->jump = cur_node->jump->jump;
            }
            cur_node = cur_node->jump;
            if (!qry(cur_node->lis.back(), wait_in)){
                cur_max = max(cur_node->lis.back(), cur_max);
                cur_node->lis.push_back(wait_in);
                wait_in++;
                break;
            }
        }
    }
    vector<int> ans(n - 1, 0);
    for (int i = 0; i < lines; i++){
        int len = start->lis.size();
        vector<int> tv(start->lis);
        for (int j = 1; j < len; j++){
            ans[tv[j] - 1] = tv[j - 1];
        }
        start = start->next;
    }
    cout << "! ";
    for (int i = 0; i < n - 1; i++) cout << ans[i] << ' ';
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
