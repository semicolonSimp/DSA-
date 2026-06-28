#include <iostream>
#include <vector>
using namespace std;
void helper(vector<vector<int>>&maze,string path,int row,int col,vector<string>&ans){
    int n=maze.size();
    if(row<0||col<0||row>=n||col>=n||maze[row][col]==0||maze[row][col]==-1){
        return;
    }
    
    if(row==n-1&&col==n-1){
        ans.push_back(path);
        return;
    }
    maze[row][col]=-1;
    helper(maze,path+'U',row-1,col,ans);
    helper(maze,path+'D',row+1,col,ans);
    helper(maze,path+'L',row,col-1,ans);
    helper(maze,path+'R',row,col+1,ans);
    maze[row][col]=1;
}
vector<string>Find_Path(vector<vector<int>>&maze){
    vector<string>ans;
    string path="";
    helper(maze,path,0,0,ans);
    return ans;
}

int main(){
    vector<vector<int>>maze={{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};
    vector<string>result=Find_Path(maze);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<endl;
    }
}