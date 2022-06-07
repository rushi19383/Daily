    
#include<bits/stdc++.h>
using namespace std;

void dfs(int i,int k){
        if(i>k)
            return ;
        
        cout<<i<<endl;
        for(int j=0;j<10;j++){
            dfs(i*10+j,k);
        }
         
    }

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=9;i++){
        dfs(i,n);
    }
}