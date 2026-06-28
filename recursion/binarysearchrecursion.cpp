#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int Find_Binary_Search(vector<int>arr,int n,int target,int st,int end){
    while(st<=end){
        int mid=st+(end-st)/2;
        if(arr[mid]==target){
            return mid;
        }
        else if(arr[mid]<target){
            return Find_Binary_Search(arr,n,target,mid+1,end);
        }else{
            return Find_Binary_Search(arr,n,target,st,mid-1);
        }
    }
}
int Binary_Search(vector<int>arr,int n,int target){
    return Find_Binary_Search(arr,n,target,0,n-1);
    
}
int main(){
    vector<int>arr={6,7,4,3,9};
    int target=6;
    int n=arr.size();
    sort(arr.begin(),arr.end());
    cout<<Binary_Search(arr,n,target);
}