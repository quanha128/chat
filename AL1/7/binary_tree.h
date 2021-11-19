/* binary_tree.h */

typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
    struct Node* parent;
} Node;

Node* tree_construct(int value, Node* left, Node* right);
void tree_free(Node* tree);

int tree_depth(Node* node);
int tree_height(Node* node);

typedef void (*Visitfn)(int value);

void tree_preorder(Node* tree, Visitfn f);
void tree_inorder(Node* tree, Visitfn f);
void tree_postorder(Node* tree, Visitfn f);