#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <cctype>
using namespace std;
//basice instruction
// only consider check alphanumeric character
//revese and check the string is palindrome or not 
bool alphanumeric(char ch){
    if(ch>='0' && ch<='9'||(tolower(ch)>='a'&&tolower(ch)<='z')){
        return true;
    }
    return false;
}
bool Reverse_String(string &str){
    int n=str.size();
    int st=0;int end=n-1;
    while(st<end){
        if(!isalnum(str[st])){
            st++;continue;
        }
        if(!alphanumeric(str[end])){
            end--;continue;
        }
        if(tolower(str[st])!=tolower(str[end])){
            return false;
        }
        st++,end--; 
    }
    return true;
}
int main(){
    string str="Ac3?e4c&a";
    cout<<Reverse_String(str);
    return 0;
}