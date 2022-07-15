#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <stack>

#include "SingleListNode.h"
using namespace std;


// largest rectangle in Histgram
int LargestRec(vector<int>& s) {
	stack<int> stk;
	int aera = 0;
	s.push_back(0);

	for (int i = 0; i < s.size();) {
		// while the stack is empty or the new height is higher, push into the stack
		if (stk.empty() || s[i] >= s[stk.top()]) {
			stk.push(i);
			i++;
		}
		else {
			// the input is lower than the top-stack height now
			int temp = stk.top();
			stk.pop();
			int width = (stk.empty()) ? i:i-stk.top()-1;
			aera = max(aera, s[temp]*width);
		}
	}
	return aera;
}
