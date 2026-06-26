#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// condition to run program
// 1.continuous manner distribution
// 2.all painter doing work
// 3 min possibble max time
bool Is_valid(vector <int>&painter,int n,int m,int mintime){
    int paint=1;int time=0;
    for(int i=0;i<n;i++){
        if(painter[i]>mintime){
            return false;
        }
        if(time+painter[i]<=mintime){
            time+=painter[i];
        }
        else{
            paint++;
            time=painter[i];
        }
    }
    return paint<=m?true:false;
}
int Min_Time(vector <int> &painter,int n, int m){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=painter[i];
    }
    int st=*max(painter.begin(),painter.end());int end=sum;
    int ans=-1;
    while (st<=end){
        int mid=st+(end-st)/2;
        if(Is_valid(painter,n,m,mid)){
              ans=mid;
              end=mid-1;
        }
        else{
            st=mid+1;
        }
    }
    return ans;
}
int main(){
    vector <int> painter={40,30,10,20};
    int n=painter.size();
    int m=2;
    cout<<Min_Time(painter,n,m);
    return 0;
}