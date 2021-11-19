#ifndef TO_POSTFIX_H
#define TO_POSTFIX_H

#include <iostream>
#include <sstream>
#include "stack.h"

using namespace std;

int icp (char c){
	if (c == '('){
		return 0;
	}
	else if (c == '!'){
		return 1;
	}
	else if (c == '*' || c == '/'){
		return 2;
	}
	else if (c == '+' || c == '-'){
		return 3;
	}
}

int isp (char c){
	if (c == '('){
		return 8;
	}
	else if (c == '!'){
		return 1;
	}
	else if (c == '*' || c == '/'){
		return 2;
	}
	else if (c == '+' || c == '-'){
		return 3;
	}
}

int isNumorPaorOp (char c){		// Check if character is Number or Parenthesis or Operator
	if (c == '.' || c == '!'){
		return 0;
	}
	else if (c >= 48 && c <= 57){
		return 1;
	}
	else if (c == ')'){
		return 2;
	}
	else if (c == '*' || c == '+' || c == '-' || c == '/' || c == '('){
		return 3;
	}
	else if (c == ' '){
		return 4;
	}
	else
		return -1;
}

string reSpace(const string& input){		// Remove all space in string
	string s;
	for (int i = 0; i < input.length(); i++){
		if (isNumorPaorOp(input[i]) >= 0 && isNumorPaorOp(input[i]) <= 3){
			s += input[i];
		}
	}
	return s;
}
string fix(const string& input){
	string s;
	for (int i = 0; i < input.length(); i++){
		if(input[i] == '-' && isNumorPaorOp(input[i-1]) != 1 && isNumorPaorOp(input[i-1]) != 2){
			s += '!';
			if (input[i+1] == '('){
				s += "1*";
			}
		}
		else
			s += input[i];
	}
	return s;
}

string to_postfix(const string& infix) {
	Stack<char> s;
	s.push('#');
	string input = fix(reSpace(infix));
	string post;
	for (int i = 0; i < input.length(); i++){
		int d = isNumorPaorOp(input[i]);
		if (d >= 0 ){
			if (d == 0){
				post += input[i];
			}
			else if (d == 1){
				post += input[i];
				if (isNumorPaorOp(input[i+1]) == 3 || isNumorPaorOp(input[i+1]) == 2 || input[i+1] == '\0'){
					post += ' ';
				}
			}
			else if (d == 2){
				while(s.top() != '(' && s.top() != '#'){
					post += s.top();
					s.pop();
					if (s.top() != '#'){
						post += ' ';
					}
				}
				s.pop();
			}
			else if (d == 3){
				while (isp(s.top()) <= icp(input[i])){
					post += s.top();
					post += ' ';
					s.pop();
				}
				s.push(input[i]);
			}
		}
	}
	while (s.top() != '#'){
		post += s.top();
		s.pop();
		if (s.top() != '#'){
			post += ' ';
		}
	}
	s.pop();
	for (int i = 0; i < post.length(); i++){
		if (post[i] == '!'){
			post[i] = '-';
		}
	}
	return post;
}

#endif //TO_POSTFIX_H
