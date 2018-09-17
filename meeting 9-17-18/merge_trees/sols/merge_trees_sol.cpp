/*
 *   tree_node in merge_trees_test:
 * 
 *   struct tree_node {
 *       int value;
 *       tree_node* left_node;
 *       tree_node* right_node;
 *   };
 */

/*
 * implement: tree_node* merge(tree_node*, tree_node*);
 *  which takes the heads of two balenced trees, and returns the head
 *  of a new, balenced merged tree with containing the nodes of both
 *  subtrees
 */
tree_node* merge(tree_node* head_a, tree_node* head_b) {
    tree_node* n_head = new tree_node;
    
    n_head->value = 0;
    n_head->left_node = head_a;
    n_head->right_node = head_b;
}
