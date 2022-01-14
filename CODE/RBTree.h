#include "Tree.h"

#define BLACK 0
#define RED 1

template <class keyT, class valT>
class RBTree_t : public Tree_t<keyT, valT> {

    Node_t<keyT, valT>* root;

    size_t check_rb(Node_t<keyT, valT>* n) {
        // Checks RB tree property
        size_t b, br, bl;
        br = bl = b = 1;
        assert(n);
        if(n && n->right) {
            br = check_rb(n->right);
            assert(n->meta == BLACK || n->right->meta == BLACK);
        }
        if(n && n->left) {
            bl = check_rb(n->left);
            assert(n->meta == BLACK || n->left->meta == BLACK);
        }
        b = br;
        if(n == this->root && br != bl) {
            //dump_subtree(this->root);
        }
        assert(n != this->root || br == bl);
        b = br;
        if(n->meta == BLACK) b += 1;
        if(n == this->root) assert(n->meta == BLACK);

        return b;
    }

    // Optional private functions.
    // These are here to guide you, but you can just ignore these.
    Node_t<keyT, valT>* rrotation (Node_t<keyT, valT>* n){
        if (!n) return nullptr;
        Node_t<keyT, valT>* t = n->left;
        if (n == root){
			n->left = t->right;
			t->right = n;
			root = t;
            n->parent = root;
            return root;
        }
        else {  // n has a parent
                if (n == n->parent->left){  // n is the left child of parent
                    t->parent = n->parent;
                    n->parent->left = t;
					n->left = t->right;
					t->right = n;
                    n->parent = t;
                    return t;
			    }
                else {  // n is the right child of parent
                    t->parent = n->parent;
                    n->parent->right = t;
					n->left = t->right;
					t->right = n;
                    n->parent = t;
                    return t;
			    }
        } 
    }

    Node_t<keyT, valT>* lrotation (Node_t<keyT, valT>* n){
        if (!n) return nullptr;
        Node_t<keyT, valT>* t = n->right;
        if (n == root){		// n is root
            n->right = t->left;
			t->left = n;
			root = t;
            n->parent = root;
            return root;
        }
        else {  // n has a parent
                if (n == n->parent->left){  // n is the left child of parent
                    t->parent = n->parent;
                    n->parent->left = t;
                    n->right = t->left;
					t->left = n;
					n->parent = t;
                    return t;
                    }
                else {  // n is the right child of parent
                    t->parent = n->parent;
                    n->parent->right = t;
                    n->right = t->left;
					t->left = n;
					n->parent = t;
                    return t;
                    }
        }
    }
    Node_t<keyT, valT>* insert_internal(keyT key, valT value) {
        Node_t<keyT, valT>* ret = Tree_t<keyT,valT>::insert_internal(key,value);
        if (!ret->parent) ret->meta = BLACK; // ret is root 
        else {
            ret->meta = RED;
            balance(ret);
        }
        return ret;
    }
    
  void balance(Node_t<keyT, valT>* k) { 
    Node_t<keyT, valT>* t;
    while (k->parent->meta == 1) {
      if (k->parent == k->parent->parent->right) {
        // flip color
        t = k->parent->parent->left;
        if (t->meta == 1) {
          t->meta = 0;
          k->parent->meta = 0;
          k->parent->parent->meta = 1;
          k = k->parent->parent;
          }
        else {
          if (k == k->parent->left) {
            k = k->parent;
            rrotation(k);
          }
          k->parent->meta = 0;
          k->parent->parent->meta = 1;
          lrotation(k->parent->parent);
        }
      }
      // node is left
      else {
        t = k->parent->parent->right;

        if (t->meta == 1) {
          t->meta = 0;
          k->parent->meta = 0;
          k->parent->parent->meta = 1;
          k = k->parent->parent;
        } else {
          if (k == k->parent->right) {
            k = k->parent;
            lrotation(k);
          }
          k->parent->meta = 0;
          k->parent->parent->meta = 1;
          rrotation(k->parent->parent);
        }
      }
      if (k == root) {
        break;
      }
    }
    // set root color black
    root->meta = 0;
  }

    void flip(Node_t<keyT, valT>* n) {
        // Flip the color of this node and all children
    }

    void remove_node(Node_t<keyT, valT>* n) {
        // Helper function for remove()
    }
    


public:
    void insert(keyT key, valT value) {
        insert_internal(key, value);
    }


    bool remove(keyT key) {
        // Find the node that has the given key and remove that node.
    }

};
