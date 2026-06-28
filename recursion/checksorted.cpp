#include<iostream>
#include<vector>
using namespace std;

bool Check_Array_Sorted(vector<int>arr,int n){
    if(n==0||n==1){
        return true;
    }
    return arr[n-1]>arr[n-2]&&Check_Array_Sorted(arr,n-1);

}
int main(){
    vector<int>arr={1,2,13,3,4,5};
    int n=arr.size();
    cout<<Check_Array_Sorted(arr,n);
}