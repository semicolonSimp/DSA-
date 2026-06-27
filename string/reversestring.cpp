#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
//reverse string 2 type
void reverse_string(char s[]){
    int st=0;int end=strlen(s)-1;
    while(st<end){
        swap(s[st++],s[end--]);
    }
}
void print(char s[]){
    int n=strlen(s);
    for(int i=0;i<n;i++){
        cout<<s[i]<<" ";
    }
}
    
int main(){

    char s[]="hello";
    reverse_string(s);
    print(s);
}