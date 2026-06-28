#include<iostream>
#include <vector>
using namespace std;
void per(vector<int>&nums,int idx,vector<vector<int>>&allpermutation){
    if(idx==nums.size()){
        allpermutation.push_back(nums);
        return;
    }
    for(int i=idx;i<nums.size();i++){
        swap(nums[idx],nums[i]);
        per(nums,idx+1,allpermutation);
        swap(nums[idx],nums[i]);
    }
}
vector<vector<int>>Permutation(vector <int> &nums){
    vector<vector<int>>allpermutation;
    per(nums,0,allpermutation);
    return allpermutation;
}
int main(){
    vector<int> nums={1,3,4};
    vector<vector<int>>Result=Permutation(nums);
    for(int i=0;i<Result.size();i++){
    cout<<"{ ";
        for(int j=0;j<Result[i].size();j++){
            cout <<Result[i][j];
        }
    cout<<" }"<<endl;
    }
}