#include <iostream>
#include "stack.h"
#include "queue.h"
#include "tree.h"
#include "to_postfix.h"

int main() {
    // part 1: stack & queue
    Stack<int> s;
    for (int i = 0; i < 8; ++i) {
        s.push(i);
    }
    while (!s.empty()) {
        cout << s.top() << " "; // 7 6 5 4 3 2 1 0
        s.pop();
    }
    cout << endl <<s.size() <<endl;

    Queue<int> q;
    for (int i = 0; i < 8; ++i) {
        q.push(i);
    }
    while (!q.empty()) {
        cout << q.front() << " "; // 0 1 2 3 4 5 6 7
        q.pop();
    }
    cout << endl << q.size() << endl;

    // part 2: convert infix to postfix
    string infix = "((-35) - 97 / 97) * (-53 + 99.271) * (88.924)";//"((-35) - 97 / 97) * (-53 + 99.271) * (88.924)"; //"-1 * (2 + -3 * 4) / -2"; 
    cout << infix  << endl;
    string postfix = to_postfix(infix);
    cout << postfix << endl; // -1 2 -3 4 * + * -2 /
    
    // part 3: evaluate an expression tree
    Tree* postfix_tree = build_expression_tree("1 2 + 3 4 5 + * *");
	postfix_tree->print(); // (/,*,-2,-1,+,null,null,null,null,2,*,null,null,-3,4)

   cout << postfix_tree->eval() << endl; // -5

    delete postfix_tree;
    return 0;
    
}
