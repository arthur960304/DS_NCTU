//
//  binarysearchtree.h
//  BinarySearchTree
//
//  Created by ArthurHsieh on 2018/11/26.
//  Copyright © 2018 ArthurHsieh. All rights reserved.
//

#ifndef binarysearchtree_h
#define binarysearchtree_h

using namespace std;

class BST;

class TreeNode {
private:
    int val;
    int level;  //level of the node
    
public:
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;

    //constructors
    TreeNode():left(0),right(0),parent(0),val(0),level(0){};
    TreeNode(int a):left(0),right(0),parent(0),val(a),level(0){};
    TreeNode(int a, int b):left(0),right(0),parent(0),val(a),level(b){};
    
    //access funciton
    int GetVal(){return val;}
    int GetLev(){return level;}
    
    friend class BST;
};

class BST {
private:
    TreeNode *root;
    TreeNode* LeftMost(TreeNode *current);   //return the biggest node in the left sub tree
    
public:
    BST():root(0){};
    TreeNode* Search(int val);
    void SearchByRank(TreeNode *ptr, int rank, int &counter, int &value, int &level);
    void Insert(int val);
    void Delete(int val);
    void PreOrder(TreeNode* current);
    
    //access funcitons
    TreeNode* GetRoot(){return root;}
};

#endif /* binarysearchtree_h */
