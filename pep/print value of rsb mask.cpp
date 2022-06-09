#include<bits/stdc++.h>
using namespace std;


void decToBinary(int n)
{
    // write your code here
    int binary[32];
    int i=0;
    while(n>0){
        binary[i]=n%2;

        n=n/2;
        i++;
    }
    for(int j=i-1;j>=0;j--){
        cout<<binary[j];
    }
}
int rightmostSetBit(int x)
{
    return x & -x;
}

int main(){
    
    
    int n;
    cin>>n;
    char buffer[33];
    //find n 's compliment 
    //then add 1 to it
    //take and with n
    //convert binary to decimal
    
    int k=(n&((~n)+1));
    decToBinary(k);
    
}