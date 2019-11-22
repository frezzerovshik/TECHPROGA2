//
//  reverse_sentences.cpp
//  TEHPROGA 2.2
//
//  Created by Артем Шарапов on 21.11.2019.
//  Copyright © 2019 Артем Шарапов. All rights reserved.
//

#include "reverse_sentences.hpp"
#include "Exception.hpp"
#include "check_funcs.h"
#define NUM_SENT 3
using namespace std;
string get_sentence(unsigned long start, unsigned long end,const char* str){
    stringstream ss;
    for(unsigned long i = start;i<end;++i){
        ss<<str[i];
    }
    return ss.str();
}
void reverse_sentences(ifstream &init){
    Exception exc;
    stringstream ss;
    string buffer;
    string line_temp;
    string sentences[NUM_SENT];
    int count_sentences = NUM_SENT-1;
    bool flag_highr = false;
    bool flag_dot = false;
    const char *c_process;
    string process;
    unsigned long start {};
    unsigned long end {};
    char c;
    int count_divide{};
    int count_highr{};
    int clk = 0;
    
    if(!init.is_open())
        init.open("/Users/frez2zerovshik/Documents/Универ/Третий курс/Проекты xCode/TEHPROGA 2.2/TEHPROGA 2.2/input_text.txt");
    while(getline(init,line_temp))
        ss << line_temp;
    process = ss.str();
    unsigned long lenght = process.length();
    if(lenght==0)
        throw exc.zero_lenght_string_exc();
    c_process = process.c_str();
    for(unsigned long i = 0;i<lenght;++i){
        c = c_process[i];
        if(flag_highr == false){
            if((flag_highr = check_highr(c))){
                start = i;
                count_highr++;
            }
        }
        if(flag_dot == false){
            if((flag_dot = check_dot(c))){
                end = i;
                count_divide++;
            }
        }
        if(clk<=NUM_SENT-1){
        if(isEqual(flag_highr, flag_dot)){
            buffer = get_sentence(start, end , c_process);
            sentences[count_sentences] = buffer;
            count_sentences--;
            flag_highr=flag_dot=false;
            clk++;
        }
        }
    }
    if(count_divide == 0 || count_highr==0){
        throw exc.no_sentences_exc();
    }
    cout<<"Результат"<<endl;
    for(int i = 0;i<NUM_SENT;++i)
        cout<<sentences[i]<<endl;
    init.close();
}
