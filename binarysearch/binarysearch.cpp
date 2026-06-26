//use for reduce the time complexibility of the code 
//binary search conditions 
// 1.sort
// 2.use for target finding
//recursive function ke liye start and end aur lena hoga parameter me.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int binarysearch(vector <int> &nums,int n,int target){
    int st=0;int end=n-1;
    
    while(st<=end){
        int mid=st+(end-st)/2;
        if(nums[mid]<target){
            st=mid+1;
        }else if(nums[mid]>target){
            end=mid-1;
        }
        else{
            return mid;
        }
    }
    return -1;
}
int main(){
    vector <int> nums={1,5,7,4,3,0};
    int target;
    cin>>target;
    sort(nums.begin(),nums.end());
    int n=nums.size();
    int result=binarysearch(nums,n,target);
    cout<<"the result is"<<result;
    return 0;
}