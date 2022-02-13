#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <typeinfo>

using namespace std;

// Palindrome detect; ignoring "space", "numbers"; and all to lower
bool isPalindrome(string s) {
	string temp=s;
	transform(s.begin(), s.end(), temp.begin(), ::tolower);
	auto l = temp.begin();
	auto r = prev(temp.end());
	
	while (l < r) {
		if (!::isalnum(*l)) {
			l++;
		}
		else if (!::isalnum(*r)) {
			r--;
		}
		else if (*l != *r) {
			return false;
		}
		else {
			l++;
			r--;
		}
	}
	return true;

	return 1;
}


// implement strStr find the occurrence of the sub list
int strofStr(const string& hay, const string& needle) {
	int N = hay.size();
	int n = needle.size();

	for (int i = 0; i < N - n + 1; i++) {
		int j = i;
		int k = 0;
		while (j < N && k < n && hay[j] == needle[k]) {
			j++; 
			k++;
		}
		if (k == n) {
			return i;
		}
	}
	return -1;	
}
// Now using KMP algorithm
vector<int> findNext(string s) {
	vector<int> ans = {0};
	int now = 0;
	int x = 1;
	while (x < s.size()) {
		if (s[x] == s[now]) {
			now++;
			x++;
			ans.push_back(now);
		}
		else if (now != 0) {
			now = ans[now - 1];
		}
		else {
			ans.push_back(0);
			x++;
		}
	}
	return ans;
}
int strofStrI(const string& hay, const string& needle) {
	vector<int> nextlist = findNext(needle);
	int N = hay.size();
	int n = needle.size();
	int i = 0;
	int j = 0;
	while (i < n && j < N) {
		if (needle[i] == hay[j]) {
			i++;
			j++;
		}
		else if (i == 0) {
			j++;
		}
		else {
			i = nextlist[i-1];
		}
	}
	if (i == n) {
		return j-i;
	}
	else {
		return -1;
	}
}


// Add Binary
string AddBinary(string& a, string& b) {
	int la = a.size();
	int lb = b.size();
	// always keep string "a" to be the longer one
	if (la < lb) return AddBinary(b, a);
	string res;

	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	int carry = 0;
	for (int i = 0; i <= la; i++) {
		int ia = i < la ? a[i] - '0' : 0;
		int ib = i < lb ? b[i] - '0' : 0;
		int ans = (ia + ib + carry) % 2;
		carry = (ia + ib + carry >= 2) ? 1 : 0;
		res = to_string(ans) + res;
	}

	if (res[0] == '1') {
		return res;
	}
	else {
		return res.substr(1);
	}

}


// Longest Palindromic Substring -- Brute Force but cannot deal with startign palindrome;
string LongPalinSubstr(string a) {
	auto ptr = next(a.begin());
	int max_length = 0;
	string result;

	while (ptr < prev(a.end())) {
		int temp_length = 0;
		string temp_res = "";
		temp_res.push_back(*ptr);
		auto left = prev(ptr);
		auto right = next(ptr);
		// from each node we seperate to find both sides if they're the same.
		while ((left > a.begin()) && (right < a.end())){
			if (*left == *right) {
				temp_length++;
				temp_res = *left + temp_res + *right;
				left--;
				right++;
			}
			else {
				break;
			}
		}
		if (temp_length > max_length) {
			max_length = temp_length;
			result = temp_res;
		}

		ptr++;
	}
	return result;

}
// dp f(i,j) to represent whether [i,j] is palindrome or not;
// if i==j: true
// if j == i+1: S[i]==S[j]
// if j > i+1: S[i]==S[j] and dp(i+1,j-1)
string LongPalinSubstrdp(string S) {
	const int n = S.size();
	bool** f = new bool* [n];
	for (int i = 0; i < n; i++) {
		f[i] = new bool[n];
	}

	int max_len = 1, start = 0;
	// we need to fill out the table
	for (int j = 0; j < n; j++) {
		f[j][j] = 1;
		for (int i = 0; i < j; i++) {
			if (j - i > 1) {
				f[j][i] = (f[j-1][i+1]) && (S[i]==S[j]);
			}
			else {
				f[j][i] = (S[i] == S[j]);
			}
			if (f[j][i] && max_len < (j - i + 1)) {
				start = i;
				max_len = j - i + 1;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		delete[] f[i];
	}
	delete[] f;

	return S.substr(start, max_len);
}



// Regular Expression Matching
