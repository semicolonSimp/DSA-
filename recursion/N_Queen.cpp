#include <iostream>
#include<vector>
#include <string>
using namespace std;
bool issafe(int n,vector<string>&board,int row,int col){
    //horizonal
    for(int j=0;j<n;j++){
        if(board[row][j]=='Q'){
            return false;
        }
    }
    //vertical
    for(int i=0;i<n;i++){
        if(board[i][col]=='Q'){
            return false;
        }
    }
    //left diagonals
    for(int i=row,j=col ; i>=0&&j>=0;i--,j--){
        if(board[i][j]=='Q'){
            return false;
        }
    }
    //right diagonals
    for(int i=row,j=col ; i>=0&&j<n;i--,j++){
        if(board[i][j]=='Q'){
            return false;
        }
    }
    return true;
}
void Queens(int n,vector<string>&board,int row,vector<vector<string>>&ans){
    if(row==n){
        ans.push_back(board);
        return;
    }
    for(int j=0;j<n;j++){
        if(issafe(n,board,row,j)){
            board[row][j]='Q';
            Queens(n,board,row+1,ans);    
            board[row][j]='.';
        }
    }
}
vector<vector<string>> N_Queen(int n){
    vector<string>board(n,string(n,'.'));
    vector<vector<string>>ans;
    Queens(n,board,0,ans);
    return ans;
        
}

int main(){
    int n;
    cout<<"Enter the chess board size";
    cin>>n;
    vector<vector<string>>result=N_Queen(n);
    for(int i=0;i<result.size();i++){
    cout<<"Solution "<<i+1<<endl;

    for(int j=0;j<result[i].size();j++){
        cout<<result[i][j]<<endl;
    }

    cout<<endl;
}
}