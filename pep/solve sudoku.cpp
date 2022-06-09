#include<bits/stdc++.h>
using namespace std;

	
	 void display(vector<vector<int>>board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                cout<<board[i][j] <<" " ;
            }
            cout<<endl;
        }
    }
         bool isValid(vector<vector<int>>board,int po,int x,int y){
        for(int j = 0;j<board[0].size();j++)
            if(board[x][j]==po) return false;
        for(int i= 0;i<board.size();i++)
            if(board[i][y]==po) return false;
            
        int smi = (x/3)*3;
        int smj = (y/3)*3;
        
        for(int i = smi;i<smi+3;i++)
            for(int j = smj;j<smj+3;j++)
                if(board[i][j] == po) return false;
                
        return true;
            
    }

     void solveSudoku(vector<vector<int>>board, int i, int j) {
        if(i == board.size()){
            display(board);
            return;
        }
        int ni = 0, nj =  0;
        if(j == board.size()-1){
            ni = i+1;
            nj = 0;
        }else{
            ni = i;
            nj = j+1;
        }
        if(board[i][j] != 0) solveSudoku(board,ni,nj);
        else{
            for(int po = 1;po<=9;po++){
                if(isValid(board,po,i,j)){
                    board[i][j] = po;
                    solveSudoku(board,ni,nj);
                    board[i][j] = 0;
                }
            }
        }
    }
    



int main() {
		 
       vector<vector<int>>arr(9,vector<int>(9));
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                 cin>>arr[i][j]; 
            }
        }

        solveSudoku(arr, 0, 0);

	}