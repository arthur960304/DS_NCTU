//
//  main.cpp
//  FindPath
//
//  Created by ArthurHsieh on 2018/10/2.
//  Copyright © 2018 ArthurHsieh. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <stack>
#include <deque>
#include <utility>
#include <iterator>
#include <string>
#include <stdlib.h>
#include "findPath.h"


int main(int argc, char *argv[]) {
    
    string ifn  = argv[1];
    string ofn1 = argv[2];
    string ofn2 = argv[3];
    
    FindPath Path;
    
    Path.firstMethod(ifn, ofn1);
    Path.BFS(ifn, ofn2);
    
    return 0;
}
