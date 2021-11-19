#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <sstream>
#include <cstdlib>
#include "stack.h"
#include "queue.h"

using namespace std;

/*
 * Recursive binary tree structure for building expression tree
 *
 * Constructors: Tree(char, Tree*, Tree*) and Tree(string, Tree*, Tree*)
 *      pointers will be automatically set to NULL if omitted
 *
 * Destructor: recursively destruct whole tree
 *
 */

struct Tree {
    string expr;
    Tree* left;
    Tree* right;

    explicit Tree(char h, Tree* l = NULL, Tree* r = NULL) {
        expr = string(1, h);
        left = l;
        right = r;
    }

    explicit Tree(const string& h = string(), Tree* l = NULL, Tree* r = NULL) {
        expr = h;
        left = l;
        right = r;
    }

    ~Tree() {
        delete left;
        delete right;
    }

    int size() {
        int size = 1;
        if (left != NULL) { size += left->size(); }
        if (right != NULL) { size += right->size(); }
        return size;
    }

    void print();

    double eval();
};

// -------- implement below --------

int depth(Tree* curr, string s)
{
    if (curr == NULL){
    	return -1;
	}
    int dep = -1;
    if (s.compare(curr->expr) == 0)
		return dep + 1;
	else if (depth(curr->left, s) >= 0)
		return depth(curr->left, s) + 1;
	else if (depth(curr->right, s) >= 0){
    	return depth(curr->right, s) + 1;	
	}
    return dep;
}

int height(Tree* curr) {
    if (curr == NULL) 
		return 0;
    else {
        int h_left = height(curr->left);
        int h_right = height(curr->right);
        if (h_right >= h_left) return h_right + 1;
        else 
			return h_left + 1;
    }
}

void Tree::print() {
Tree* root = this;	
if (root == NULL){
	cout << "()";
}
else {
	Queue<Tree*> q;
    q.push(root);
	string s;
	s += "(";
	int hei = height(root);
    while (q.empty() == false) {
        Tree* curr = q.front();
		if (curr->expr.compare("null")==0) {
			s += curr->expr + ",";
			q.pop();
			continue;
		}
        else {
			s += curr->expr + ",";
        	q.pop();
		}
        if (curr->left != NULL) {
            q.push(curr->left);
		} 
		else {
			if (depth(root, curr->expr) < hei-1) {
				Tree* temp = new Tree("null", NULL, NULL);
				q.push(temp);
			}
		}
        if (curr->right != NULL) {
            q.push(curr->right);
		} 
		else {
			if (depth(root, curr->expr) < hei-1) {
				Tree* temp = new Tree("null", NULL, NULL);
				q.push(temp);
			}
		}
    }
    s.erase(s.end() - 1);
    s += ")";
    cout << s << endl;
    cout << hei << endl;
	}
}

double stringtoDouble(const string& s){
	double x = 0.0;
	stringstream ss;
	ss << s;
	ss >> x;
	return x;
}	
	
double Tree::eval() {
	Tree *curr = this;
	if (curr == NULL){
		return 0;
	}
	else {
		if (curr->left == NULL && curr->right == NULL){
			return stringtoDouble(curr->expr);
		}
		double eval_l = curr->left->eval();
		double eval_r = curr->right->eval();
		if (curr->expr == "+"){
			return eval_l+eval_r;
		}
		else if (curr->expr == "-"){
			return eval_l-eval_r;
		}
		else if (curr->expr == "*"){
			return eval_l*eval_r;
		}
		else if (curr->expr == "/"){
			return eval_l/eval_r;
		}
	}
}

int isOp(char c){
	if (c == '*' || c == '/' || c == '+' || c == '-'){
		return 1;
	}
	else if (c == ' ' || c == '\0'){
		return 2;
	}
	else
		return 0;
}

Tree* build_expression_tree(const string& postfix) {
	Stack<Tree *> s;
	Tree *t;
	string ss;
	for(int i=0; i < postfix.length(); i++){
		if (isOp(postfix[i]) == 1 && isOp(postfix[i+1]) != 2){	// Unary minus
			ss += postfix[i];
		}
		else if (isOp(postfix[i]) == 0){		// Operand
			ss += postfix[i];
			if (postfix[i+1] == ' '){
				t = new Tree(ss);
				s.push(t);
				ss = "";
			}
		}
		else if (isOp(postfix[i]) == 1 && isOp(postfix[i+1]) == 2){		// is Operator
			t = new Tree(postfix[i]);
			t->right = s.top();
			s.pop();
			t->left = s.top();
			s.pop();
			s.push(t);
		}
	}
	t = s.top();
	s.pop();
	return t;

}

#endif //TREE_H
