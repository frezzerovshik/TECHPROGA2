//
//  check_funcs.cpp
//  TEHPROGA 2.2
//
//  Created by Артем Шарапов on 22.11.2019.
//  Copyright © 2019 Артем Шарапов. All rights reserved.
//

#include "check_funcs.h"
bool isEqual(bool f1 , bool f2){
    if(f1 == true && f2 == true)
        return true;
    else
        return false;
}
bool check_highr(char c){
    if(c >=65 && c<=90)
        return true;
    else
        return false;
}
bool check_dot( char c){
    if(c == '.' || c == '?' || c == '!')
        return true;
    else
        return false;
}
bool is_sentence_found(bool fl_1,bool fl_2){
    if(fl_1 == true && fl_2 == true)
        return true;
    else
        return false;
}
