#include<bits/stdc++.h>
using namespace std;
void xoapt(int a[], int &n, int k){
    for(int i=k-1;i<n-1;i++){
        a[i]=a[i+1];
    }
    --n;
}

void chenpt(int a[], int &n, int h, int b){
    for(int i=n;i>=h;i--){
        a[i]=a[i-1];
    }
    a[h-1]=b;
    ++n;

}
int main(){
    int a[10000];
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int k;
    cin>>k;
    int h, b;
    cin>>h>>b;
    xoapt(a, n, k);
    chenpt(a,n,h,b);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}
//Time: O(N)
//Memory: O(1)