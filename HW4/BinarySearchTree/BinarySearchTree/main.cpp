//
//  main.cpp
//  BinarySearchTree
//
//  Created by ArthurHsieh on 2018/11/24.
//  Copyright © 2018 ArthurHsieh. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include "binarysearchtree.h"

int main(int argc, const char * argv[]) {
    
    string ifn = argv[1];
    string ofn = argv[2];
    
    ifstream inFile;
    ofstream outFile;
    
    inFile.open(ifn.c_str());
    outFile.open(ofn.c_str());
    
    int order;  //1-4 1: insertion, 2: deletion, 3: search, 4: search by rank
    int number; //value of node or rank
    
    BST Tree;
    TreeNode *current;
    
    while(inFile >> order >> number){
        switch (order) {
            case 1:
                Tree.Insert(number);
                break;
            case 2:
                Tree.Delete(number);
                break;
            case 3:
                current = Tree.Search(number);
                if(current) outFile << current->GetLev() << "\n";
                else outFile << -1 << "\n"; //the tree has no this key
                break;
            case 4:
                int value = 0, counter = 0, level = 0;
                Tree.SearchByRank(Tree.GetRoot(), number, counter, value, level);
                outFile << value << " " << level << "\n";
                break;
        }
    }
    //Tree.PreOrder(Tree.GetRoot());
    return 0;
}
