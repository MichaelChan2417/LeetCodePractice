// CALCULATOR 1
// with the function of +, -, *, /, and in reverse order [2,1,+,3,*] = (2+1)*3;
int CalculatorI(vector<string>& tokens) {
	vector<int> stk;
	int ans;
	string ope = "+-*/";

	for (int i = 0; i < tokens.size(); i++) {
		if (ope.find(tokens[i]) != string::npos) {
			int num2 = stk.back();
			stk.pop_back();
			int num1 = stk.back();
			stk.pop_back();

			if (tokens[i] == "+") {
				stk.push_back(num1 + num2);
			}
			else if (tokens[i] == "-") {
				stk.push_back(num1 - num2);
			}
			else if (tokens[i] == "*") {
				stk.push_back(num1 * num2);
			}
			else {
				stk.push_back(num1 / num2);
			}

		}
		else {
			// now the input is number
			stk.push_back(stoi(tokens[i]));
		}
	}
	return stk.back();
}


// CALCULATOR 2
// now we just consider + and -, but the input string is in the correct order
// like 3+5-2+5 = 11 ... return the correct ans
int CalculatorII(string& s) {
	stack<int> nums;
	stack<char> ope;
	nums.push(0);
	ope.push('+');
	int last,temp;
	char opera;

	for (int i = 0; i < s.size(); i++) {
		// we have two situations here, one is num; another is ope
		if (s[i]>='0' && s[i]<='9') {
			last = nums.top()*10;
			last += int(s[i] - '0');
			nums.pop();
			nums.push(last);
		}
		else {
		// now it is the operator
			nums.push(0);
			ope.push(s[i]);
		}
	}

	// now the ope-stack and num-stack have been prepared, we need to make calculation
	int ans = 0;
	while (!ope.empty()) {
		temp = nums.top();
		nums.pop();
		opera = ope.top();
		ope.pop();

		ans = opera == '+' ? ans + temp : ans - temp;
	}

	return ans;
}


// CALCULATOR 3
// implement with +-*/ in order
// like 3+2*4-5 = 3+8-5 = 6
int CalculatorIII(string& s) {
	// it is almost the same as before but now, I need to calculate with * and / first
	stack<int> nums;
	stack<char> ope;
	nums.push(0);
	ope.push('+');
	int temp;
	char ope_temp;

	s = s + "+0";
	for (int i = 0; i < s.size(); i++) {
		// number's situation
		if (s[i] >= '0' && s[i] <= '9') {
			temp = nums.top() * 10;
			temp += int(s[i] - '0');
			nums.pop();
			nums.push(temp);
		}
		// the second situation is the * and /
		else if (s[i] == '*' || s[i] == '/') {
			ope.push(s[i]);
			nums.push(0);
		}
		else {
			// now the input opera is + or - but we need calculate * and / first;
			if (ope.top() == '*' || ope.top() == '/') {
				ope_temp = ope.top();
				ope.pop();

				int num2 = nums.top();
				nums.pop();
				int num1 = nums.top();
				nums.pop();

				temp = ope_temp == '*' ? num1 * num2 : num1 / num2;
				nums.push(temp);
				nums.push(0);

				ope.push(s[i]);
			}
			else {
				ope.push(s[i]);
				nums.push(0);
			}
		}
	}

	int ans = 0;
	while (!ope.empty()) {
		temp = nums.top();
		nums.pop();
		ope_temp = ope.top();
		ope.pop();

		ans = ope_temp == '+' ? ans + temp : ans - temp;
	}

	return ans;
}
