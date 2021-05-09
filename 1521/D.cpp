#include<iostream>
#include<unordered_set>
#include<unordered_map>
#include<set>
#include<map>
#include<vector>
#include<stack>
#include<queue>
#include<cmath>
#include<string>
#include<iomanip>
#define ll long long
using namespace std;
int main() {
	int t;
	cin >> t;
	for (int o = 0; o < t; o++) {
		int n;
		cin >> n;
		int x, y;
		vector<int> degree(n + 1, 0);
		vector<pair<int, int>> edges;

		for (int i = 0; i < n - 1; i++) {
			cin >> x >> y;
			degree[x]++;
			degree[y]++;
			edges.push_back(make_pair(x, y));
		}
		unordered_set<int> redun;
		for (int i = 1; i <= n; i++) {
			if (degree[i]> 2)redun.insert(i);
		}
		vector<pair<int, int>> redun_e;
        int edge_len=edges.size();
		for (int i=0;i<edge_len;i++) {
            auto edge=edges[i];
			if (redun.count(edge.first) && redun.count(edge.second) && 
                degree[edge.first] > 2 && degree[edge.second] > 2) {
				redun_e.push_back(edge);
				degree[edge.first]--;
				degree[edge.second]--;
                edges.erase(edges.begin()+i);
                edge_len--;
                i--;
			}
		}
		for (int i=0;i<edge_len;i++) {
            auto edge=edges[i];
			if (redun.count(edge.first) && degree[edge.first] > 2&&
                !redun.count(edge.second)) {
				redun_e.push_back(edge);
				degree[edge.first]--;
				degree[edge.second]--;
                edges.erase(edges.begin()+i);
                edge_len--;
                i--;
			}
            else if (redun.count(edge.second) && degree[edge.second] > 2&&
                !redun.count(edge.first)) {
				redun_e.push_back(edge);
				degree[edge.first]--;
				degree[edge.second]--;
                edges.erase(edges.begin()+i);
                edge_len--;
                i--;
			}
		}

		unordered_set<int> one;
		vector<int> zero;
		for (int i = 1; i <= n; i++) {
			if (degree[i] == 0)zero.push_back(i);
			else if (degree[i] == 1)one.insert(i);
		}

		vector<pair<int, int>> add_e;
		int len = redun_e.size();
		int zero_len = zero.size();
		int one_len = one.size();
		if (zero_len>1){
            for(int i=0;i<zero_len-1;i++){
                add_e.push_back(make_pair(zero[i],zero[i+1]));
				edges.push_back(make_pair(zero[i],zero[i+1]));
            }
            one.insert(zero[0]);
            one.insert(zero[zero_len-1]);
        }
        vector<vector<int>> adj(n+1);
        for(auto edge:edges){
            adj[edge.first].push_back(edge.second);
            adj[edge.second].push_back(edge.first);
        }
        int beg,en;
		beg=*one.begin();
        one.erase(one.begin());
		if (zero_len==1)add_e.push_back(make_pair(zero[0],beg));
		en=adj[beg][0];
		while(adj[en].size()>1){
			if (adj[en][0]==beg){beg=en;en=adj[en][1];}
			else {beg=en;en=adj[en][0];}
		}
		one.erase(en);
        while(one.size()>1){
            beg=*one.begin();
            one.erase(one.begin());
			add_e.push_back(make_pair(beg,en));
            en=adj[beg][0];
            while(adj[en].size()>1){
                if (adj[en][0]==beg){beg=en;en=adj[en][1];}
				else {beg=en;en=adj[en][0];}
            }
			one.erase(en);
        }
		int xlen = redun_e.size();
		cout << xlen << endl;
		for (int i=0;i<len;i++){
            cout<<redun_e[i].first<<" "<<redun_e[i].second<<" ";
            cout<<add_e[i].first<<" "<<add_e[i].second<<endl;
        }
	}
	return 0;
}
