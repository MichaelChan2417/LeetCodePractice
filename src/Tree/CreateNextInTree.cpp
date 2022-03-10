class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

void connect_helper(Node* root){
    if(root == nullptr) return;
    Node dummy(-1);
    for(Node* cur=root, *prev=&dummy; cur; cur = cur->next){
        if(cur->left){
            prev->next = cur->left;
            prev = prev->next;
        }
        if(cur->right){
            prev->next = cur->right;
            prev = prev->next;
        }
    }
    connect_helper(dummy.next);
};

Node* connect(Node* root) {
    connect_helper(root);
    return root;
}
