//
//  findPath.h
//  FindPath
//
//  Created by ArthurHsieh on 2018/10/4.
//  Copyright © 2018 ArthurHsieh. All rights reserved.
//

#ifndef Header_h
#define Header_h

using namespace std;

//a represents column and b represents row
struct offsets
{
    int a, b;
};

//four directions are available
enum direct
{
    E, S, W, N
};


class FindPath
{
private:
    int input, width, height;
    int start_g = 0, start_h = 0;   //starting col and row
    int exit_g = 0, exit_h = 0;     //ending col and row
    int i, j, g, h, m, n;           //unimportant factors
    
    string s_input, s_width, s_height;
    
    ifstream inFile1, inFile2;
    ofstream outFileFirstMethod, outFileBFS;
    
    offsets move[4];
    
public:
    int firstMethod(string, string);
    int BFS(string, string);
};



#endif /* Header_h */
