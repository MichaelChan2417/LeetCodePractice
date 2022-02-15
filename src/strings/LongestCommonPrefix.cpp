#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Longest Common Prefix
// write a function to find the longest common prefix string amongst an array of strings

string LongestCommonPrefix(vector<string>& strs){
    if(strs.empty()) return "";

    // traverse the whole strs in column using the idx of strs[0] to compare
    for(int idx=0; idx<strs[0].size(); idx++){
        for(int i=0; i<strs.size(); i++){
            if(strs[i][idx] != strs[0][idx]) return strs[0].substr(0,idx);
        }
    }
    // else the strs[0] have been all traversed and it is the shortest;
    return strs[0];
}
