#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

// Include only '(' and ')'; detect the longest valid substring
int LongestValidParen(string& s) {
	stack<int> stk;
	int n = s.size();
	vector<int> cont(n,0);

	for (int i = 0; i < n; i++) {
		// unmatched ')' set 1 on vector
		if (s[i] == ')') {
			if (stk.empty()) {
				cont[i] = 1;
				continue;
			}
			else {
				stk.pop();
				continue;
			}
		}
		// now the input is '('
		else{
			stk.push(i);
		}
	}
	while (!stk.empty()) {
		cont[stk.top()] = 1;
		stk.pop();
	}

	int max_l = 0;
	int temp_l = 0;
	for (int i = 0; i < n; i++) {
		if (cont[i]) {
			max_l = max(temp_l, max_l);
			temp_l = 0;
		}
		else {
			temp_l++;
		}
	}
	max_l = max(temp_l, max_l);
	return max_l;
}




// However it is kind of slow
// we make a revise
int LongestValidParentheses(string s){
  stack<int> stk;
  vector<bool> mark(s.length());
  int len = 0;
  for(int i=0; i<s.size(); i++){
    // the loop part is almost the same
    if(s[i] == '(') st.push(i);
    else{
      // now considering the useless ')'
      if(stk.empty()) mark[i] = 1;
      else st.pop();
    }
  }
  while(!stk.empty()){
    mark[st.top()] = 1;
    st.pop();
  }
  
  // now find the max length
  for(int i=0; i<s.size(); i++){
    if(mark[i]){
      len = 0;
      continue;
    }
    len++;
    ans = max(ans,len);
  }
  return ans;
}
