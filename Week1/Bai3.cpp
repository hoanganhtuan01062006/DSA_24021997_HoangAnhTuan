#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    long long gt=1;
    while(n>1){
        gt*=n;
        --n;
    }
    cout<<gt;
} 
//Time: O(N)
//Memory: O(1)