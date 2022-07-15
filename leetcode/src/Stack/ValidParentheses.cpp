#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

// Valid Parentheses; with the input of '(', ')', '[', ']', '{', '}'
bool isValid(string const& s){
    string left = "([{";
    string right = ")]}";
    stack<char> stk;

    for(auto c:s){
        if(left.find(c) <3){ // should be in the range 0~2 but now it is the left part
            stk.push(c);
        }
        else{ // now it should be in the right
            if(stk.empty() || (stk.top() != left[right.find(c)])){ // two conditions, if is empty and if not paired
                return false;
            } 
            else{
                stk.pop();
            }
        }
        
    }
    return stk.empty();
}
