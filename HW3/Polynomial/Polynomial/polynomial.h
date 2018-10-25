//
//  polynomial.h
//  Polynomial
//
//  Created by ArthurHsieh on 2018/10/25.
//  Copyright © 2018 ArthurHsieh. All rights reserved.
//

#ifndef polynomial_h
#define polynomial_h

using namespace std;

struct Term {
    int coeff;
    int exp;
    
    void init(int c, int e){
        coeff = c;
        exp   = e;
    }
};

class Polynomial {
public:
    //operator overloading
    friend Polynomial operator+(Polynomial&, Polynomial&);
    friend Polynomial operator-(Polynomial&, Polynomial&);
    friend Polynomial operator*(Polynomial&, Polynomial&);
    list <Term> poly;
    
};

#endif /* polynomial_h */
