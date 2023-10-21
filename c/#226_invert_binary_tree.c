/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/*shorter solution*/
struct TreeNode* invertTree(struct TreeNode* root) {
    /* Base case: If the node is NULL, return NULL.*/
    if (root == NULL) {
        return NULL;
    }

    /* Recursive step: Swap the left and right subtrees.*/
    struct TreeNode* temp = root->left;
    root->left = invertTree(root->right);
    root->right = invertTree(temp);

    return root;
}

/******************************************************************************/
/*original solution*/
void swapNodes(struct TreeNode** left, struct TreeNode** right){
    struct TreeNode* temp = *left;
    *left = *right;
    *right = temp;
}

void invertTreeRec(struct TreeNode* node){
    if (NULL == node){
        return;
    }

    invertTreeRec(node->left);
    invertTreeRec(node->right);

    swapNodes(&(node->left), &(node->right));
}

struct TreeNode* invertTree(struct TreeNode* root){
    if (NULL == root){
        return NULL;
    }

    invertTreeRec(root->left);
    invertTreeRec(root->right);

    swapNodes(&(root->left), &(root->right));

    return root;
}

