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
int nums[10000];
int main(){
    int t;
    cin>>t;
    for(int o=0;o<t;o++){
        int n,x;
        cin>>n;
        int pos=-1;
        int pos1=-1,pos2=-1;
        bool jud=true;
        for(int i=1;i<n;i+=2){
            cout<<"?"<<" "<<1<<" "<<i<<" "<<i+1<<" "<<n-1<<endl;
            cin>>x;
            if (x>=n-1){
                if (x==n){
                    pos=i+1;
                    break;
                }
                cout<<"?"<<" "<<1<<" "<<i+1<<" "<<i<<" "<<n-1<<endl;
                cin>>x;
                if (x==n){
                    pos=i;
                    break;
                }
            }
        }
        if (pos==-1) pos=n;
        nums[pos-1]=n;
        for(int i=1;i<=n;i++){
            if (i==pos)continue;
            cout<<"?"<<" "<<2<<" "<<i<<" "<<pos<<" "<<1<<endl;
            cin>>nums[i-1];
        }
        cout<<"! ";
        for(int i=0;i<n;i++)cout<<nums[i]<<" ";
        cout<<endl;
    }
    return 0;
}