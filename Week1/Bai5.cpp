#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[10000];
    int n;
    cin>>n;
    long long tong=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        tong+=a[i];
    }
    double tb=(double)tong/n;
    for(int i=0;i<n;i++){
        if(a[i]>=tb){
            cout<<a[i]<<" ";
        }
    }
}
//Time: O(N)
//Memory: O(1)