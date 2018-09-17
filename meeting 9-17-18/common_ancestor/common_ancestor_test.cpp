#include<iostream>
#include<utility>
#include<stdlib.h>
#include<vector>

using namespace std;

/*
 * struct representing the binary tree
 */
struct tree_node {
    int value;
    tree_node* left_node;
    tree_node* right_node;
};

/*
 * common_ancestor.cpp is expected to contain the function 
 *
 * tree_node* common_ancestor(tree_node* head, tree_node* node_a, tree_node* node_b);
 *  which searches for the common ancestor between nodes a and b in tree with head head
 *  and returns a pointer to it 
 * 
 */
#include"common_ancestor.cpp"

/*
 * test_balenced checks if a given node is the heada of a balenced tree
 * the return values are:
 *  -1 - unbalenced
 * >-1 - depth of tree
 *   
 */
pair<int,bool> test_balenced(tree_node* head, int depth, bool complete) {
    pair<int,bool> left_return, right_return;
    
    if (head == NULL) return make_pair(depth, true);

    if (head->left_node == NULL) {
        left_return = make_pair(depth, true);
    } else {
        left_return = test_balenced(head->left_node, depth+1, complete);
    }
    
    if (head->right_node == NULL) {
        right_return = make_pair(depth, true);
    } else {
        right_return = test_balenced(head->right_node, depth+1, complete);
    }
    
    complete = left_return.second && right_return.second;
    
    if (left_return.first == right_return.first) {
        return left_return;
    } else if (left_return.first-1 == right_return.first && complete) {
        return make_pair(right_return.first, false);
    } else {
        return make_pair(-1, false);
    }
}

/*
 * simply print the tree in order with < and > to denote the hierarchy
 */
void print_tree(tree_node* head) {
    if (head == NULL) return;
    
    cout << "<";
    
    if (head->left_node != NULL) {
        print_tree(head->left_node);
    }
    
    cout << head->value << " ";
    
    if (head->right_node != NULL) {
        print_tree(head->right_node);
    }
    
    cout << ">";
}

/*
 * returns a tree beginning at start, and ending at end. it will 
 * make mistakes if it isn't a power of two minus one, but is only for testing anyway
 */
tree_node* build_tree(int start, int end) {
    int mid = (end+start)/2;
    
    tree_node* new_tree = new tree_node;

    if (start == mid) {
        new_tree->left_node = NULL;
        new_tree->right_node = NULL;
        new_tree->value = mid;
    } else {
        new_tree->left_node = build_tree(start,mid-1);
        new_tree->right_node = build_tree(mid+1,end);
        new_tree->value = mid;
    }
    
    return new_tree;
}

void contains_all_helper(tree_node* head, int n_vals, vector<int>& val_list) {
    if (head==NULL) return;
    
    val_list[head->value]++;
    contains_all_helper(head->left_node,  n_vals, val_list);
    contains_all_helper(head->right_node, n_vals, val_list);
}

bool contains_all(tree_node* head, int n_vals) {
    vector<int> val_list;
    
    for (int i=1; i<n_vals+2; i++) {
        val_list.push_back(0);
    }
    
    contains_all_helper(head, n_vals, val_list);
    
    for (int i=1; i<n_vals+1; i++) {
        //cout << i << " " << val_list[i] << "\n";
        if (val_list[i] != 1) return false;
    }
    
    return true;
}

tree_node* find(tree_node* head, int value) {
    if (head == NULL) return NULL;
    if (head->value == value) return head;
    
    tree_node* left = find(head->left_node, value);
    if (left != NULL) return left;
    
    tree_node* right = find(head->right_node, value);
    if (right != NULL) return right;
    
    return NULL;
}

bool run_test(int test_num, int searcha, int searchb, int expected) {
    tree_node* tree = build_tree(1,127);
    
    cout << "--TEST " << test_num << "--\n";
    cout << "seraching for common ancestor of: " << searcha << " and: " << searchb << "\n";
    
    tree_node* result = common_ancestor(tree, find(tree, searcha), find(tree, searchb));
    
    bool pass;
    
    cout << "expected: " << expected << "\n";
    if (result == NULL) {
        cout << "recieved a null node" << "\n";
        
        pass = false;
    } else {
        cout << "recieved: " << result->value << "\n";
        
        if (result->value == expected) {
            pass = true;
        } else {
            pass = false;
        }
    }

    cout << "\n";
    
    if (pass) {
        cout << "--PASS--\n\n";
        return true;
    } else {
        cout << "--FAIL--\n\n";
        return false;
    }
}

int main() {
    run_test(1,1,5,4);
    run_test(2,3,9,8);
    run_test(3,6,11,8);
}
