//
//  operator.cpp
//  Polynomial
//
//  Created by ArthurHsieh on 2018/10/25.
//  Copyright © 2018 ArthurHsieh. All rights reserved.
//

#include <stdio.h>
#include <list>
#include "polynomial.h"


Polynomial operator+(Polynomial& poly1, Polynomial& poly2){
    Term term;
    Polynomial poly3;
    list <Term>::iterator it1 = poly1.poly.begin();
    list <Term>::iterator it2 = poly2.poly.begin();
    list <Term>::iterator it;
    
    while (it1!=poly1.poly.end() || it2!=poly2.poly.end()){
        //if reach poly1's end, then add the rest of poly2 to output poly
        if (it1==poly1.poly.end()) {
            for (it=it2; it!=poly2.poly.end(); ++it) {
                if (it->coeff!=0){
                    poly3.poly.push_back(*it);
                }
            }
            it2 = it;   //set to end of poly
        }
        //if reach poly2's end, then add the rest of poly1 to output poly
        else if (it2==poly2.poly.end()) {
            for (it=it1; it!=poly1.poly.end(); ++it) {
                if (it->coeff!=0){
                    poly3.poly.push_back(*it);
                }
            }
            it1 = it;   //set to end of poly
        }
        //if poly1's term is greater than poly2's term
        //then add poly1's term to output poly
        else if (it1->exp > it2->exp) {
            poly3.poly.push_back(*it1);
            ++it1;  //jump to next term
        }
        //if poly2's term is greater than poly1's term
        //then add poly2's term to output poly
        else if (it1->exp < it2->exp){
            poly3.poly.push_back(*it2);
            ++it2;  //jump to next term
        }
        //if poly1's term is equal to poly2's term
        //add together and add to output poly
        else if (it1->exp == it2->exp){
            term.coeff = it1->coeff + it2->coeff;
            term.exp   = it1->exp;
            
            if (term.coeff!=0) {
                poly3.poly.push_back(term);
            }
            ++it1;
            ++it2;
        }
    }
    return poly3;
}

Polynomial operator-(Polynomial& poly1, Polynomial& poly2){
    Term term;
    Polynomial poly3;
    list <Term>::iterator it1 = poly1.poly.begin();
    list <Term>::iterator it2 = poly2.poly.begin();
    list <Term>::iterator it;
    
    while (it1!=poly1.poly.end() || it2!=poly2.poly.end()){
        //if reach poly1's end, then add the rest of poly2 to output poly
        if (it1==poly1.poly.end()) {
            for (it=it2; it!=poly2.poly.end(); ++it) {
                if (it->coeff!=0){
                    it->coeff = (it->coeff)*(-1);   //since it's negative sign
                    poly3.poly.push_back(*it);
                }
            }
            it2 = it;   //set to end of poly
        }
        //if reach poly2's end, then add the rest of poly1 to output poly
        else if (it2==poly2.poly.end()) {
            for (it=it1; it!=poly1.poly.end(); ++it) {
                if (it->coeff!=0){
                    it->coeff = (it->coeff);
                    poly3.poly.push_back(*it);
                }
            }
            it1 = it;   //set to end of poly
        }
        //if poly1's term is greater than poly2's term
        //then add poly1's term to output poly
        else if (it1->exp > it2->exp) {
            poly3.poly.push_back(*it1);
            ++it1;  //jump to next term
        }
        //if poly2's term is greater than poly1's term
        //then add poly2's term to output poly
        else if (it1->exp < it2->exp){
            it2->coeff = (it2->coeff)*(-1); //since it's negative sign
            poly3.poly.push_back(*it2);
            ++it2;  //jump to next term
        }
        //if poly1's term is equal to poly2's term
        //add together and add to output poly
        else if (it1->exp == it2->exp){
            term.coeff = it1->coeff - it2->coeff;
            term.exp   = it1->exp;
            
            if (term.coeff!=0) {
                poly3.poly.push_back(term);
            }
            ++it1;
            ++it2;
        }
    }
    return poly3;
}

Polynomial operator*(Polynomial& poly1, Polynomial& poly2){
    Term term;
    Polynomial poly3, temp1, temp2;
    list <Term>::iterator it1 = poly1.poly.begin();
    list <Term>::iterator it2 = poly2.poly.begin();
    list <Term>::iterator it;
    
    //for each term in poly1
    //multiply for every term in poly2
    while (it1!=poly1.poly.end()){
        while (it2!=poly2.poly.end()) {
            term.coeff = it1->coeff * it2->coeff;
            term.exp   = it1->exp + it2->exp;
            
            if (term.coeff!=0) {
                temp2.poly.push_back(term);
            }
            ++it2;
        }
        poly3 = temp1 + temp2;
        temp1 = poly3;
        temp2.poly.clear();
        
        it2 = poly2.poly.begin();
        ++it1;
    }
    return poly3;
}
