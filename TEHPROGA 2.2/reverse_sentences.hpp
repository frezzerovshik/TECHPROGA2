//
//  reverse_sentences.hpp
//  TEHPROGA 2.2
//
//  Created by Артем Шарапов on 21.11.2019.
//  Copyright © 2019 Артем Шарапов. All rights reserved.
//

#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

void reverse_sentences(std::ifstream &init);
std::string get_sentence(unsigned long start, unsigned long end,const char* str);
