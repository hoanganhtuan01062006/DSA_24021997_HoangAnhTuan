#include<bits/stdc++.h>
using namespace std;
void sapxep(int n, int a[]){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j]){
                swap(a[i],a[j]);
            }
        }
    }
}
int main(){
    int a[10000];
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sapxep(n, a);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    }
//Time: O(N*N)
//Memory: O(1)