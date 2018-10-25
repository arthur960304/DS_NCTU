//
//  main.cpp
//  Polynomial
//
//  Created by ArthurHsieh on 2018/10/23.
//  Copyright © 2018 ArthurHsieh. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include "polynomial.h"


int main(int argc, char *argv[]) {
    
    string ifn = argv[1];
    string ofn = argv[2];
    
    ifstream inFile;
    ofstream outFile;
    
    inFile.open(ifn.c_str());
    outFile.open(ofn.c_str());
    
    int numOfTerm;     //number of terms
    int coeff, exp;
    string s_numOfTerm, line, opr;
    
    Polynomial firstPoly, secondPoly, outputPoly;   //outputPoly = firstPoly + secondPoly
    Term term;
    
    //***************Get the first polynomial***************//
    getline(inFile, s_numOfTerm);
    numOfTerm = stoi(s_numOfTerm);                  //convert string to int
    
    for (int i=0; i<numOfTerm; ++i) {
        inFile >> coeff >> exp;                     //read coeffecient and exponent
        term.init(coeff, exp);                      //create a node
        firstPoly.poly.push_back(term);             //push to link list
        
        getline(inFile, line);                      //delete this line
    }
    getline(inFile, opr);                           //read operator
    
    if (!opr.empty() && opr[opr.size() - 1] == '\r')    //check for "\r"
        opr.erase(opr.size() - 1);
    //******************************************************//
    
    while (getline(inFile, s_numOfTerm)) {
        //get the second polynomial
        numOfTerm = stoi(s_numOfTerm);              //convert string to int
        
        for (int i=0; i<numOfTerm; ++i) {
            inFile >> coeff >> exp;                 //read coeffecient and exponent
            term.init(coeff, exp);                  //create a node
            secondPoly.poly.push_back(term);        //push to link list
            
            getline(inFile, line);                  //delete this line
        }
        
        if (opr=="+") {
            outputPoly = firstPoly + secondPoly;    //add 2 polynomials
        }
        else if (opr=="-") {
            outputPoly = firstPoly - secondPoly;    //minus 2 polynomials
        }
        else if (opr=="*") {
            outputPoly = firstPoly * secondPoly;    //multiply 2 polynomials
        }
        
        if (outputPoly.poly.size()==0){             //if outputPoly = 0
            term.init(0, 0);                        //create a node which is 0
            outputPoly.poly.push_back(term);
        }
        
        firstPoly.poly.clear();
        secondPoly.poly.clear();
        firstPoly = outputPoly;                     //let output poly be the next poly waited to be added
        
        getline(inFile, opr);                       //read operator
        if (!opr.empty() && opr[opr.size() - 1] == '\r')    //check for "\r"
            opr.erase(opr.size() - 1);
    }
    
    //*****************Write to output file*****************//
    unsigned long size = outputPoly.poly.size();
    outFile << size << endl;
    
    for (list <Term>::iterator it=outputPoly.poly.begin(); it!=outputPoly.poly.end(); ++it) {
        outFile << it->coeff << " " << it->exp << endl;
    }
    
    inFile.close();
    outFile.close();
    //******************************************************//
    
    return 0;
}
