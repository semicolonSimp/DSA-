//In this ques we discuss about distribute the page in such manner the maximum pages of the user minimum pages.
//min possible max pages
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool Is_Valid(vector <int>books,int n, int m, int maxpages){
        int stu=1;int pages=0;
        for(int i=0;i<n;i++){
            if(books[i]>maxpages){
                return false;
            }
            if(pages + books[i]<=maxpages){
                pages+=books[i];
            }
            else{
                stu++;
                pages=books[i];
            }
        }
        return stu>m?false:true;

    }
int Alocated_Books(vector<int> &books,int n,int m){
    
    if(m>n){
        return -1;
    }
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=books[i];
    }
    int st=0;int end=sum;
    int ans=1;
    while(st<=end){
        int mid=st+(end-st)/2;
        if(Is_Valid(books,n,m,mid)){
            ans=mid;
            end=mid-1;
        }else{
           st=mid+1;
        }
    }
    return ans;
}
   
int main(){
    vector <int> books={2,1,3,4};
    arr={15,17,20}
    n=3 m=2
    int n=4, m=2;
    cout<<Alocated_Books(books,n,m);
    return 0;
}