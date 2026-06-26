//max possible min distance
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool Is_Possible(vector<int>&arr,int n,int c,int mindis){
    int cow=1;int laststall=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]-laststall>=mindis){
            cow++;
            laststall=arr[i];
        }
        if(cow==c){
            return true;
        }
    }
    return false;
}
int Min_Dis(vector<int>&arr,int n, int c){
    sort(arr.begin(),arr.end());
    int st=arr[0];int end=arr[n-1]-arr[0];int ans=-1;
    while(st<=end){
        int mid=st+(end-st)/2;
        if(Is_Possible(arr, n, c,mid)){
            ans=mid;
            st=mid+1;
        }else{
            end=mid-1;
        }
    }
    return ans;
}
int main(){
    int n=5;int c=3;
    vector<int>arr={1,2,8,4,9};
    cout<<Min_Dis(arr,n,c);
    return 0;
}