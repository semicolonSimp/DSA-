//In this ques we discuss the mountain array peak element 
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int PeakElement(vector <int> &peak,int n){
    int st=1;int end=n-2;
    while(st<=end){
        int mid=st+(end-st)/2;
        if(peak[mid-1]<peak[mid]&&peak[mid]>peak[mid+1]){
            return mid;
        }else if(peak[mid-1]<peak[mid]){
            st=mid+1;
        }else{
            end=mid-1;
        }
    }
    return -1;
}
int main(){
    vector <int> peak={3,6,7,9,5,4,1};
    int n=peak.size();
    int result=PeakElement(peak,n);
    cout<<result;
    return 0;
}