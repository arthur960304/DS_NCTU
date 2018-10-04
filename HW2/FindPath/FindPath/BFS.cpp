//
//  BFS.cpp
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


//Breadth First Search
int FindPath::BFS(string ifn, string ofn)
{
    inFile2.open(ifn.c_str());
    outFileBFS.open(ofn.c_str());
    
    //get width and height from input file
    getline(inFile2, s_width);
    getline(inFile2, s_height);
    
    //convert string to int
    width   = stoi(s_width);
    height  = stoi(s_height);
    
    int i, j, g, h;
    int dis = 0;                    //distance between current and starting position
    int pathSize;                   //number of steps to the goal
    int lastCol = 0, lastRow = 0;   //last col and row number in the closequeue
    int colDiff, rowDiff;           //difference between last and second last
    int start_g = 0, start_h = 0, exit_g = 0, exit_h = 0;
    int maze[width][height];        //maze stores the whole maze
    
    deque<pair<pair<int, int>, int>> openQueue;     //dynamic queue
    deque<pair<pair<int, int>, int>> closeQueue;    //store every steps
    
    bool visited[width][height];    //true if visited before
    
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
    for (int n=0; n<height; ++n){
        for (int m=0; m<width; ++m){
            inFile2 >> s_input;
            
            if (s_input == "S"){
                start_g = m;
                start_h = n;
                maze[m][n] = 2;
            }
            else if (s_input == "E"){
                exit_g = m;
                exit_h = n;
                maze[m][n] = 2;
            }
            else{
                input = stoi(s_input);
                maze[m][n] = input;
            }
        }
    }
    
    //mark all as not visited
    for (int n=0; n<height; ++n){
        for (int m=0; m<width; ++m){
            visited[m][n] = false;
        }
    }
    //mark the starting and exit point and boundary as visited and enqueue it
    for (j=0; j<height; ++j){
        for (i=0; i<width; ++i){
            if(maze[i][j]==2){
                visited[i][j] = true;
            }
        }
    }
    visited[start_g][start_h] = true;
    visited[exit_g][exit_h] = true;
    
    openQueue.push_back(make_pair(make_pair(start_g, start_h), 0));
    closeQueue.push_back(make_pair(make_pair(start_g, start_h), 0));
    
    while (!openQueue.empty()) {
        i   = openQueue.front().first.first;
        j   = openQueue.front().first.second;
        dis = openQueue.front().second;
        dis = dis + 1;
        
        int wallCount = 0;  //stores the number of walls surrounding in this position
        for (int p=0; p<4; p++) {
            g = i + move[p].a;
            h = j + move[p].b;
            
            if ((g==exit_g) && (h==exit_h)){
                cout << "GOAL" << endl;
                pathSize = closeQueue.back().second - wallCount;  //path size should minus the number of walls calculated before
                
                int count = 0;
                // delete the position that is over the path size
                while (closeQueue.back().second!=pathSize){       // delete the position that is over the path size
                    closeQueue.pop_back();
                }
                //find the position before the goal and store to the variable lastCol and lastRow
                while((closeQueue.back().second == pathSize) && (count==0)){
                    if ((abs(exit_g-closeQueue.back().first.first)+abs(exit_h-closeQueue.back().first.second))<=1){
                        lastCol = closeQueue.back().first.first;
                        lastRow = closeQueue.back().first.second;
                        maze[lastCol][lastRow] = 1;
                        count = count + 1;
                    }
                    closeQueue.pop_back();
                }
                //Back trace the path
                while (!closeQueue.empty()) {
                    colDiff = abs(lastCol - closeQueue.back().first.first);
                    rowDiff = abs(lastRow - closeQueue.back().first.second);
                    
                    //if the path difference is less than 1
                    //it means this position is on the path
                    if(colDiff+rowDiff <= 1){
                        lastCol = closeQueue.back().first.first;
                        lastRow = closeQueue.back().first.second;
                        int d   = closeQueue.back().second;
                        
                        //mark path as 1 in maze array
                        maze[lastCol][lastRow] = 1;
                        
                        //delete other positions that has the same distance
                        for (int i=0; i<closeQueue.size(); ++i) {
                            if (closeQueue.back().second == d){
                                closeQueue.pop_back();
                            }
                        }
                    }
                    else{
                        closeQueue.pop_back();
                    }
                }
                
                //output maze array to output file
                for (int n=0; n<height; ++n){
                    for (int m=0; m<width; ++m){
                        
                        if ((m==start_g) && (n==start_h)){
                            outFileBFS << "S" << " ";
                        }
                        else if ((m==exit_g) && (n==exit_h)){
                            outFileBFS << "E" << " ";
                        }
                        else{
                            outFileBFS << maze[m][n] << " ";
                        }
                    }
                    outFileBFS << "\n";
                }
                return 0;
            }
            //if not visited before
            if (visited[g][h]==false) {
                openQueue.push_back(make_pair(make_pair(g, h), dis));
                closeQueue.push_back(make_pair(make_pair(g, h), dis));
                visited[g][h] = true;
                wallCount = wallCount + 1;
            }
        }
        openQueue.pop_front();
    }
    return 0;
}
