#include <iostream>
#include <vector>
#include <string>
#include <cctype>
using namespace std;
string Remove_Occurance(string s,string part){
    int len=s.size();
    int len1=part.size();
    while(len>0&&s.find(part)<len){
        s.erase(s.find(part),len1);
    }
    return s;

}
int main(){
    string s="daabcbaabcbc";
    string part="abc";
    string result=Remove_Occurance(s,part);
    cout <<result;
}