//
//  findPath.cpp
//  FindPath
//
//  Created by ArthurHsieh on 2018/10/4.
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

using namespace std;

int FindPath::firstMethod(string ifn, string ofn)
{
    inFile1.open(ifn.c_str());
    outFileFirstMethod.open(ofn.c_str());
    
    //get width and height from input file
    getline(inFile1, s_width);
    getline(inFile1, s_height);
    
    //convert string to int
    width   = stoi(s_width);
    height  = stoi(s_height);
    
    //stack stores coordinate and direction
    stack<pair<pair<int, int>, direct>> stack;
    
    int maze[width][height];        //maze stores the whole maze
    int mark[width][height];        //mark stores the path you went before
    
    //four directions (E, S, W, N)
    move[E].a = 1;
    move[E].b = 0;
    move[S].a = 0;
    move[S].b = 1;
    move[W].a = -1;
    move[W].b = 0;
    move[N].a = 0;
    move[N].b = -1;
    
    //iterate through each element in input file and store into maze array
    for (n=0; n<height; ++n){
        for (m=0; m<width; ++m){
            
            inFile1 >> s_input;
            
            if (s_input == "S"){
                start_g = m;
                start_h = n;
                maze[m][n] = 2;
                mark[m][n] = 1;
            }
            else if (s_input == "E"){
                exit_g = m;
                exit_h = n;
                maze[m][n] = 2;
                mark[m][n] = 1;
            }
            else{
                input = stoi(s_input);
                maze[m][n] = input;
                mark[m][n] = input;
            }
        }
    }
    
    //initialize stack to the maze entrance coordinates and direction east
    stack.push(make_pair(make_pair(start_g, start_h), E));
    
    int i, j;   //(i,j) represents coordinates deleted from top of stack
    int g, h;   //(g,h) represents coordinates of next move
    direct dir = E;
    
    while (!stack.empty()) {
        i = stack.top().first.first;
        j = stack.top().first.second;
        dir = stack.top().second;
        
        while (dir<=N) {
            g = i + move[dir].a;
            h = j + move[dir].b;
            
            if ((g==exit_g) && (h==exit_h)) {
                cout << "GOAL" << endl;
                stack.push(make_pair(make_pair(i, j), dir));
                
                //mark path as 1 in maze array
                int row, col;
                int stackSize = static_cast<int>(stack.size());
                
                for (int i=0; i<stackSize; ++i){
                    col = stack.top().first.first;
                    row = stack.top().first.second;
                    maze[col][row] = 1;
                    stack.pop();
                }
                
                //output maze array to output file
                for (n=0; n<height; ++n){
                    for (m=0; m<width; ++m){
                        
                        if ((m==start_g) && (n==start_h)){
                            outFileFirstMethod << "S" << " ";
                        }
                        else if ((m==exit_g) && (n==exit_h)){
                            outFileFirstMethod << "E" << " ";
                        }
                        else{
                            outFileFirstMethod << maze[m][n] << " ";
                        }
                    }
                    outFileFirstMethod << "\n";
                }
                
                return 0;
            }
            //if the move is valid
            else if ((!maze[g][h]) && (!mark[g][h])) {
                mark[g][h] = 1;
                dir = static_cast<direct>(dir+1);
                stack.push(make_pair(make_pair(i, j), dir));    //stack stores the next possible move
                i   = g;
                j   = h;
                dir = E;
            }
            else{
                dir = static_cast<direct>(dir + 1);
            }
        }
        stack.pop();
    }
    return 0;
}

