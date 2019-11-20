//
//  arr.hpp
//  TEHPROGA 2.2
//
//  Created by Артем Шарапов on 18.11.2019.
//  Copyright © 2019 Артем Шарапов. All rights reserved.
//

#include "Aeroflot.hpp"
#include "Exception.hpp"

class arr : public Exception{
    Aeroflot *mas;
    unsigned short _size;
    ofstream log;
public:
    arr();
    arr(const arr& init);
    arr(unsigned short lenght);
    ~arr();
    
    Aeroflot& operator[](unsigned int index);
    void operator+=(Aeroflot obj);
    void operator-=(Aeroflot obj);
    void sort();
    unsigned short search(Aeroflot obj);
    unsigned short search(string quest);
    void print();
    void print(unsigned short index_of_needed_object);
    unsigned short size();
    bool isEmpty();
};
