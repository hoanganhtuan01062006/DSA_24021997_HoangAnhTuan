#include<bits/stdc++.h>
using namespace std;
int a[1000][1000];
long long tinhtong(int a[][1000],int n,int m){
    long long tong=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            tong+=a[i][j];
        }
    }
    return tong;
}

void xoadong(int a[][1000], int &n, int m, int r) {
    for (int row = r - 1; row < n - 1; row++){
        for (int col = 0; col < m; col++){
            a[row][col] = a[row + 1][col];
        }
    }
    --n;
}    
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    cout<<tinhtong(a,n,m)<<endl;
    int r;
    cin>>r;
    xoadong(a,n,m,r);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}
//Time: O(N)
//Memory: O(1)