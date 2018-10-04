//
//  checkPrime.cpp
//  CheckPrime
//
//  Created by ArthurHsieh on 2018/9/29.
//  Copyright © 2018 ArthurHsieh. All rights reserved.
//

#include <stdio.h>
#include <cmath>

bool checkPrime(int number)
{
    int i;
    
    if (number == 1){
        return false;
    }
    else if (number < 4 && number > 1){
        return true;
    }
    else{
        for(i = 2; i <= sqrt(number); ++i){
            if (number % i == 0){
                return false;
                break;
            }
        }
        return true;
    }
}
