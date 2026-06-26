#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//merge two sorted array with sc 0 and tc o(n)
void Merge_Sorted_Array(vector <int> &arr1,int m, vector<int> &arr2,int n){
    int idx=m+n-1;int i=m-1;int j=n-1;
    while(i>=0&&j>=0){
        if(arr1[i]>arr2[j]){
            arr1[idx--]=arr1[i--];   
        }
        else if(arr2[j]>=arr1[i]){  
            arr1[idx--]=arr2[j--];   
        }
    } 
    while(j>=0){
        
        arr1[idx--]=arr2[j--];
        
    }
}
void Print_Vector(vector <int> &arr1){
    int x=arr1.size();
    for(int i=0;i<x;i++){
        cout<<arr1[i]<<" ";
    }
}

int main(){
    vector <int>arr1={1,2,3,0,0,0};
    int m=3;
    vector <int>arr2={2,5,6};
    int n=3;
    Merge_Sorted_Array(arr1,m,arr2,n);
    Print_Vector(arr1);
    return 0;

}