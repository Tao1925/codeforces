#include<iostream>
#define ll long long
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        ll a,b;
        cin>>a>>b;
        if (b==1){
            cout<<"NO"<<endl;
        }else {
            cout<<"YES"<<endl;
            cout<< a<<" "<<(2*b-1)*a<<" "<<2*b*a<<endl;
        }
    }
    return 0;
}