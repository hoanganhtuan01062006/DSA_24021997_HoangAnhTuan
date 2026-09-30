#include<iostream>
using namespace std;
int main(){
    long long a[10000];
    long long n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    long long tong=0;
    for(int i=0;i<n;i++){
        tong+=a[i];
    }
    cout<<tong;
}
//Time: O(N)
//Memory: O(1)