//
//  arr.cpp
//  TEHPROGA 2.2
//
//  Created by Артем Шарапов on 18.11.2019.
//  Copyright © 2019 Артем Шарапов. All rights reserved.
//
#define LEN_UNDERSCORE 90
#include "arr.hpp"
#include <stdio.h>
#include <iostream>
#include <ctime>
using namespace std;
#pragma mark - constructors
arr :: arr(){
    mas = nullptr;
    _size= 0;
    time_t t =time(0);
    tm* now = localtime(&t);
    log.open("/Users/frez2zerovshik/Documents/Универ/Третий курс/Проекты xCode/TEHPROGA 2.2/TEHPROGA 2.2/log_arr.txt",std::ios::app);
    for(int i = 0;i<LEN_UNDERSCORE;++i) log<<"-";
    log<<endl<<endl;
    log<<"Constructor without params: "<< now->tm_hour<<"."<<now->tm_min<<"."<<now->tm_sec<<endl;
    for(int i = 0;i<LEN_UNDERSCORE;++i) log<<"-";
    log<<endl<<endl;
    log.close();
}
arr :: arr( const arr& init ){
    _size = init._size;
    mas = new Aeroflot[_size];
    for(int i = 0;i<init._size;++i)
        mas[i] = init.mas[i];
    time_t t =time(0);
    tm* now = localtime(&t);
    log.open("/Users/frez2zerovshik/Documents/Универ/Третий курс/Проекты xCode/TEHPROGA 2.2/TEHPROGA 2.2/log_arr.txt",std::ios::app);
    for(int i = 0;i<LEN_UNDERSCORE;++i) log<<"-";
    log<<endl<<endl;
    log<<"Constructor of copy: "<< now->tm_hour<<"."<<now->tm_min<<"."<<now->tm_sec<<endl;
    for(int i = 0;i<LEN_UNDERSCORE;++i) log<<"-";
    log<<endl<<endl;
    log.close();
}
arr :: arr( unsigned short _size ){
    this->_size = _size;
    mas = new Aeroflot[this->_size];
    time_t t =time(0);
    tm* now = localtime(&t);
    log.open("/Users/frez2zerovshik/Documents/Универ/Третий курс/Проекты xCode/TEHPROGA 2.2/TEHPROGA 2.2/log_arr.txt",std::ios::app);
    for(int i = 0;i<LEN_UNDERSCORE;++i) log<<"-";
    log<<endl<<endl;
    log<<"Constructor with params: "<< now->tm_hour<<"."<<now->tm_min<<"."<<now->tm_sec<<endl;
    for(int i = 0;i<LEN_UNDERSCORE;++i) log<<"-";
    log<<endl<<endl;
    log.close();
}
#pragma mark - destructor
arr::~arr(){
    delete [] mas;
    time_t t =time(0);
    tm* now = localtime(&t);
    log.open("/Users/frez2zerovshik/Documents/Универ/Третий курс/Проекты xCode/TEHPROGA 2.2/TEHPROGA 2.2/log_arr.txt",std::ios::app);
    for(int i = 0;i<LEN_UNDERSCORE;++i) log<<"-";
    log<<endl<<endl;
    log << "Destructor called: "<< now->tm_hour<<"."<<now->tm_min<<"."<<now->tm_sec<<endl<<endl;
    for(int i = 0;i<LEN_UNDERSCORE;++i) log<<"-";
    log<<endl<<endl;
    log.close();
}
#pragma mark - operators
Aeroflot& arr :: operator[](unsigned int index){
    return mas[ index ];
}
void arr :: operator+=(Aeroflot obj){
    if(isEmpty()){
        mas = new Aeroflot[1];
        mas[0] = obj;
        _size++;
        return;
    }
    _size++;
    Aeroflot* temporary = new Aeroflot [ _size ];
    for( int i = 0 ; i<_size -1; ++i )
        temporary[i] = mas[i];
    temporary[_size-1] = obj;
    delete[] mas;
    mas = temporary;
    return;
}
bool arr :: isEmpty(){
    if(_size == 0)
        return true;
    else
        return false;
}
void arr:: operator-=(Aeroflot obj){
    if(isEmpty())
        throw empty_exc();
    unsigned short index = this->search(obj);
    Aeroflot* temporary = new Aeroflot[_size];
    for (unsigned short i = 0; i < _size; ++i)
        temporary[i] = mas[i];
    delete[] mas;
    mas = new Aeroflot[_size-1];
    for (unsigned short i = 0, j = 0; i < _size; ++i, ++j)
        if (i != index) mas[j] = temporary[i];
        else
            --j;
    --_size;
    delete[] temporary;
    return;
}
#pragma mark - print
void arr :: print(){
    if(isEmpty())
        throw empty_exc();
    sort();
    for ( int i = 0; i < _size; ++i )
        mas[i].print();
}
void arr :: print(unsigned short index_of_needed_object){
    if(index_of_needed_object>=_size)
        throw object_doesnt_exist_exc();
    mas[index_of_needed_object].print();
}
#pragma mark - search
unsigned short arr :: search(Aeroflot obj){
    if(isEmpty())
        throw empty_exc();
    unsigned short res_index {};
    bool flag = false;
    for(unsigned short i = 0; i < _size ; ++i){
        if(mas[i] == obj){
            flag = true;
            res_index = i;
            return res_index;
        }
    }
    if(flag == false)
        throw not_found_exc();
    else return res_index;
}
unsigned short arr :: search(string quest){
    if(isEmpty())
        throw empty_exc();
    unsigned short res_index = NULL;
    bool flag  = false;
    for(unsigned short i = 0; i < _size ; i++){
        if(mas[i].getType().compare(quest)){
            res_index = i;
            flag = true;
        }
    }
    if(flag == false){
        throw not_found_exc();
    }
    else
        return res_index;
}
#pragma mark - size and sort
unsigned short arr::size(){
    return _size;
}
void arr::sort(){
    if(isEmpty())
        throw empty_exc();
    for ( int i = 0; i < _size - 1; i++)
        for ( int j = 0; j < _size -i- 1; j++)
        {
            if(strcmp(mas[j].getDestination().c_str(), mas[j+1].getDestination().c_str()) > 0)
            {
                Aeroflot temp;
                temp = mas[j];
                mas[j] = mas[j+1];
                mas[j+1] = temp;
            }
        }
}
