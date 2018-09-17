/*
 *   tree_node in merge_trees_test:
 * 
 *   struct tree_node {
 *       int value;
 *       tree_node* left_node;
 *       tree_node* right_node;
 *   };
 */

pair<tree_node*, pair<bool, bool> > common_ancestor_helper(tree_node* head, tree_node* node_a, tree_node* node_b) {
    bool found_a = false;
    bool found_b = false;
    tree_node* common = NULL;
    
    if (head == node_a) found_a = true;
    if (head == node_b) found_b = true;
    
    if (found_a && found_b) common = head;
    
    pair<tree_node*, pair<bool, bool> > left;
    if (head->left_node != NULL) {
        left = common_ancestor_helper(head->left_node, node_a, node_b);
        
        if (left.first != NULL) common = left.first;
        found_a = found_a || left.second.first;
        found_b = found_b || left.second.second;
    }
    
    pair<tree_node*, pair<bool, bool> > right;
    if (head->right_node != NULL) {
        right = common_ancestor_helper(head->right_node, node_a, node_b);
        
        if (right.first != NULL) common = right.first;
        found_a = found_a || right.second.first;
        found_b = found_b || right.second.second;
    }
    
    if (common == NULL && found_a && found_b) {
        common = head;
    } 
    
    return make_pair(common, make_pair(found_a, found_b));
}

/*
 * implement: common_ancestor(tree_node* head, tree_node* node_a, tree_node* node_b);
 *  which takes the heads of two balenced trees, and returns the head
 *  of a new, balenced merged tree with containing the nodes of both
 *  subtrees
 */
tree_node* common_ancestor(tree_node* head, tree_node* node_a, tree_node* node_b) {
    pair<tree_node*, pair<bool, bool> > val = common_ancestor_helper(head, node_a, node_b);
    return val.first;
}


