//In This Ques We Discuss About The Topic Of Binary Search 
//All Element Present In The Array Exactly 2 Times One Element Occur At 1 So They Return The Output
//Single Element Present In The Sorted Array
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int CheckElement(vector <int> &nums,int n){
    int st=0;int end=n-1;
    while(st<=end){
        int mid=st+(end-st)/2;
        if (nums[mid-1]!=nums[mid]&&nums[mid+1]!=nums[mid]){
            return mid;
        }else if(mid %2==0){
            if(nums[mid]==nums[mid-1]){
                end=mid-1;
            }
            else{
                st=mid+1;
            }
        }else if(mid %2!=0){
            if(nums[mid]==nums[mid-1]){
                st=mid+1;
            }
            else{   
                end=mid-1;
            }
        }
    }
    return -1;
}
int main(){
    vector <int> nums={2,2,3,3,4,4,6,7,7};
    vector <int> nums1={4,4,5,6,6,9,9};
    int n=nums.size();
    int n1=nums1.size();
    int result=CheckElement(nums,n);
    cout<<result<<endl;
    
   
    return 0;
}