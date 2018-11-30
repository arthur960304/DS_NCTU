//
//  binarysearchtree.cpp
//  BinarySearchTree
//
//  Created by ArthurHsieh on 2018/11/26.
//  Copyright © 2018 ArthurHsieh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "binarysearchtree.h"

//Find the biggest node in the left sub tree
TreeNode* BST::LeftMost(TreeNode *current){
    while (current->right != NULL){
        current = current->right;
    }
    return current;
}

//Insertion
void BST::Insert(int val){
    TreeNode *inserted = Search(val);
    
    //if the inserted node is not in the tree
    if(!inserted){
        TreeNode *insertNode = new TreeNode(val);
        TreeNode *dad = 0;
        TreeNode *curr = 0;
        
        //find appropriate position for the inserted node
        curr = root;
        while(curr != NULL){
            dad = curr;
            if (insertNode->val > curr->val) {
                curr = curr->right;
            }
            else curr = curr->left;
            insertNode->level = insertNode->level + 1;
        }
        //assign parent to the inserted node
        insertNode->parent = dad;
        
        //append node to the tree
        if (dad == NULL){
            this->root = insertNode;
        }
        else if (insertNode->val > dad->val){
            dad->right = insertNode;
        }
        else dad->left = insertNode;
    }
}

//Deletion
void BST::Delete(int val){
    TreeNode *deleteNode = Search(val);
    
    //if the node is in the tree
    if (deleteNode) {
        TreeNode *node = 0;
        TreeNode *child = 0;
        
        //after this if-else statement, we can ensure "node" has only 1 or no child
        if (deleteNode->left == NULL || deleteNode->right == NULL){
            node = deleteNode;
        }
        else node = LeftMost(deleteNode->left);  //find biggest node in the left sub tree
        
        //if deleted node at least one child
        if (node->left != NULL){
            child = node->left;
        }
        else child = node->right;       //child may be NULL
        
        //set parent
        if(child != NULL) child->parent = node->parent;
        
        if(node->parent == NULL){
            this->root = child;
        }
        else if(node == node->parent->left){
            node->parent->left = child;
        }
        else node->parent->right = child;
        
        //if node is the biggest node in the left sub tree
        //the value of this node should replace deleted node value
        if (node != deleteNode) {
            deleteNode->val = node->val;
        }
        
        delete node;
        node = 0;
    }
    
}

//Search
TreeNode* BST::Search(int VAL){
    TreeNode *current = root;
    
    while(current != NULL && current->val != VAL){
        if(current->val < VAL){
            current = current->right;
        }
        else current = current->left;
    }
    return current;
}

//Preorder traversal
void BST::PreOrder(TreeNode *current){
    if (current) {
        cout << current->val << " ";        // V
        BST::PreOrder(current->left);       // L
        BST::PreOrder(current->right);      // R
    }
}

//Search by rank
void BST::SearchByRank(TreeNode *ptr, int rank, int &counter, int &value, int &level){
    if (ptr==NULL || counter>rank) //leaf or the element was already found
        return;
    else
    {
        BST::SearchByRank(ptr->left, rank, counter, value, level);
        counter++; //visit
        if (counter == rank){
            value = ptr->GetVal();
            level = ptr->GetLev();
        }
        BST::SearchByRank(ptr->right, rank, counter, value, level);
    }
}
