#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

#include "checkPrime.h"

using namespace std;

int main(int argc, char *argv[])
{
    int input;
    bool isPrime = false;
    
    ifstream inFile;
    ofstream outFile;
    
    string ifn = argv[1];
    string ofn = argv[2];
    
    inFile.open(ifn.c_str());
    outFile.open(ofn.c_str());

    //Iterate through each element in the file
    while (inFile >> input){
        isPrime = checkPrime(input);    //return true if x is a prime number, false otherwise
        //Write to the output file, 1 if prime, 0 if not prime
        if (isPrime){
            outFile << 1 <<"\n";
        }
        else{
            outFile << 0 << "\n";
        }
    }
    
    return 0;
}

