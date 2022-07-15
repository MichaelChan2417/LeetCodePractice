#include <iostream>
#include <string>

using namespace std;

// regular expression match with the support of '.' and '*'
// here we use the recursion using pointer instead of the exact string
bool isMatch(string& a, string& b){
    const char* x = a.c_str();
    const char* y = b.c_str();
    return isMatch_handler(y,x);
}

bool isMatch_handler(const char* x, const char* y){
    // if empty char*
    if(*y == '\0') return *x == '\0';

    // now if the next ptr is not *, then we must have the one-by-one match
    if(*(y+1)!='*'){
        if(*x==*y || (*y=='.' && *x!='\0')){
            return isMatch_handler(x+1,y+1);
        }
        else return false;
    }
    // now the next character is *
    else{
        while(*x==*y || (*y=='.' && *x!='\0')){
            if(isMatch_handler(x,y+2)) return true;
            x++;
        }
        return(isMatch_handler(x,y+2));
    }

}

