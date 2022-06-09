#include<bits/stdc++.h>
using namespace std;
int maxi=0;
int m,n;
int dfs(vector<vector<int>>& grid, int i,int j)
{
    
    int ans=0, temp=0;
    if(i>=grid.size() || i<0 || j<0 || j>=grid[0].size() || grid[i][j]==0) return 0;
    temp=grid[i][j];
    grid[i][j]=0;
    ans = max(ans,dfs(grid,i-1,j));
    ans = max(ans,dfs(grid,i+1,j));
    ans = max(ans,dfs(grid,i,j+1));
    ans = max(ans,dfs(grid,i,j-1));
    grid[i][j] = temp;
    return ans+temp;
}
void getgold(vector<vector<int>>&arr,int i,int j,vector<vector<bool>> &vis,vector<int>&bag){
    if(i<0 || j<0 || i>=m || j>=n ||vis[i][j] ||arr[i][j]==0){
        return;
    }
    vis[i][j]=true;
    bag.push_back(arr[i][j]);
    getgold(arr,i-1,j,vis,bag);
    getgold(arr,i,j+1,vis,bag);
    getgold(arr,i,j-1,vis,bag);
    getgold(arr,i+1,j,vis,bag);
     

}
 int getMaximumGold(vector<vector<int>>& grid){
        
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]>0){
                    ans = max(ans,dfs(grid,i,j));
                }
            }
        }
        return ans;
    }
void getmaxgold(vector<vector<int>> arr){
    vector<vector<bool>> vis(m,vector<bool>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(!vis[i][j] || arr[i][j]!=0){
            vector<int>bag;
            getgold(arr,i,j,vis,bag);
            int sum=0;
            for(int i:bag){
                sum+=i;
            }
            if(sum>maxi){
                maxi=sum;
            }
            }
        }
    }
}
int main(){
    
    cin>>m>>n;
    vector<vector<int>> arr(m,vector<int>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
     getmaxgold(arr);
     cout<<maxi;
}