#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;
string Reverse_Word(string s){
    reverse(s.begin(),s.end());
    string str="";
    int n=s.size();
    for(int i=0;i<n;i++){
        string word="";
        while(i<n&&s[i]!=' '){
            word+=s[i];
            i++;
        }
        reverse(word.begin(),word.end());
        str=str+" "+word;
    }
    return str.substr(1);
    
}
int main(){
    string s="The pen is blue";
    string result=Reverse_Word(s);
    cout<<result;
    return 0;
}