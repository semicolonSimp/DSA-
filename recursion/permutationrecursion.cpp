#include<iostream>
#include<vector>
using namespace std;
void Get_Permutation(vector<int>arr,int idx, vector<vector<int>>&ans){
    if(idx==arr.size()){
        ans.push_back(arr);
        return;
    }
    for(int i=idx;i<arr.size();i++){
        swap(arr[i],arr[idx]);
        Get_Permutation(arr,idx+1,ans);
        swap(arr[i],arr[idx]);
    }

}
vector<vector<int>> Permutation(vector<int>arr){
    vector<vector<int>>ans;
    Get_Permutation(arr,0,ans);
    return ans;
}
int main(){
    vector<int> arr={1,2,3};
    int n=arr.size();

    vector<vector<int>>result= Permutation(arr);
    for(int i=0;i<result.size();i++){
    cout<<"{ ";
        for(int j=0;j<result[i].size();j++){
            cout<<result[i][j];
        }
    cout<<" }"<<endl;
    }
}