//
//  reverse_sentences.cpp
//  TEHPROGA 2.2
//
//  Created by Артем Шарапов on 21.11.2019.
//  Copyright © 2019 Артем Шарапов. All rights reserved.
//

#include "reverse_sentences.hpp"

using namespace std;

void reverse_sentences(ifstream &init){
    stringstream ss;
    string line;
    if(!init.is_open())
        init.open("/Users/frez2zerovshik/Documents/Универ/Третий курс/Проекты xCode/TEHPROGA 2.2/TEHPROGA 2.2/input_text.txt");
    while(getline(init,line))
        ss << line;
    
    init.close();
}
