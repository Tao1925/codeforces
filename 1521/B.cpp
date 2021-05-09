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
int nums[100000];
int main(){
    int t;
    cin>>t;
    for(int o=0;o<t;o++){
        int n;
        cin>>n;
        for(int i=0;i<n;i++)cin>>nums[i];
        int pos=0;
        int maxn=INT_MAX;
        for(int i=0;i<n;i++){
            if (nums[i]<maxn){
                pos=i;
                maxn=nums[i];
            }
        }
        cout<<n-1<<endl;
        for(int i=0;i<pos;i++){
            cout<<pos+1<<" "<<i+1<<" "<<nums[pos]<<" "<<nums[pos]+pos-i<<endl;
        }
        for(int i=pos+1;i<n;i++){
            cout<<pos+1<<" "<<i+1<<" "<<nums[pos]<<" "<<nums[pos]+i-pos<<endl;
        }
    }
    return 0;
}