#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool check(char open,char close){
    if(open=='(' && close==')') return true;
    else if(open=='{' && close=='}') return true;
    else if(open=='[' && close==']') return true;
    return false;
}
bool checkBracket(string str){
    stack<char> s;
    for(int i=0;i<str.length();i++){
        if(str[i]=='['||str[i]=='{'||str[i]=='(') s.push(str[i]);
        else if(str[i]==']'||str[i]=='}'||str[i]==')') {
            if(s.empty() || check(s.top(),str[i])) return false;
            else s.pop();
        }
    }
    return s.empty() ? true:false;
}
int main(){
    string str;
    cout<<"Enter the expression\n";
    cin>>str;
    if(checkBracket(str)) cout<<"Balanced\n";
    else cout<<"Not Balanced\n";
}