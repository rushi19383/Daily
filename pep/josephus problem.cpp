
#include<bits/stdc++.h>
using namespace std;

int helper(int n,int k){
        if(n==1)
            return 0;
        return (helper(n-1,k) + k) % n;
    }

int main(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    cout<<helper(n,k);
}