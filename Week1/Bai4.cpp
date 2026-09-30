#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b){
    while(b!=0){
        int tmp=b;
        b=a%b;
        a=tmp;
    }
    return a;
}

void rutgon(int &a,int &b){
    int tmp=a;
    a/=gcd(a,b);
    b/=gcd(tmp,b);
}
int main(){
    int a,b;
    cin>>a>>b;
    rutgon(a,b);
    cout<<a<<"/"<<b;
}
//Time: O(logN)
//Memory: O(1)