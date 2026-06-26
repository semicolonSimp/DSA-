#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//conditions
//each row is sorting non decreasing order
//the first integer of each row is greater than the last integer of previous row
bool Search_Element(vector<vector<int>>&mat,int target,int midrow,int n){
    int st=0;int end=n-1;
    while(st<=end){
        int mid=st+(end-st)/2;
        if(mat[midrow][mid]==target){
            return true;
        }else if(mat[midrow][mid]<target){
            st=mid+1;
        }else{
            end=mid-1;
        }
    }
    return false;
}
bool Search_Matrics(vector<vector<int>>&mat,int target){
    int m=mat.size();
    int n=mat[0].size();
    int strow=0;int endrow=m-1;
    while(strow<=endrow){
        int midrow=strow+(endrow-strow)/2;
        if(target>=mat[midrow][0]&&target<=mat[midrow][n-1]){
            return Search_Element(mat,target,midrow,n);
        }else if(target<mat[midrow][0]){
            endrow=midrow-1;
        }else{
            strow=midrow+1;
        }
    }
    return false;
}
int main(){
    vector<vector<int>>mat={{1,3,5},{11,12,19},{31,67,89}};
    int target=67;
    cout<<Search_Matrics(mat,target);
}