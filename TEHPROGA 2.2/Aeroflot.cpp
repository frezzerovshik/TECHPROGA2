//
//  Aeroflot.cpp
//  TEHPROGA 2.2
//
//  Created by Артем Шарапов on 20.11.2019.
//  Copyright © 2019 Артем Шарапов. All rights reserved.
//
#define LEN_UNDERSCORE 90
#include "Aeroflot.hpp"
#include <iostream>
#include <ctime>
using namespace std;
#pragma mark - constructor
Aeroflot::Aeroflot(){
    destination.erase();
    number.erase();
    type.erase();
    time_t t =time(0);
    tm* now = localtime(&t);
    log.open("/Users/frez2zerovshik/Documents/Универ/Третий курс/Проекты xCode/TEHPROGA 2.2/TEHPROGA 2.2/log_aeroflot.txt",std::ios::app);
    for(int i = 0;i<LEN_UNDERSCORE;++i) log<<"-";
    log<<endl<<endl;
    log<<"Constructor without params: " << now->tm_hour<<"."<<now->tm_min<<"."<<now->tm_sec<<endl;
    for(int i = 0;i<LEN_UNDERSCORE;++i) log<<"-";
    log<<endl<<endl;
    log.close();
}
Aeroflot:: Aeroflot(const Aeroflot& init){
    destination = init.destination;
    number = init.number;
    type = init.type;
    time_t t =time(0);
    tm* now = localtime(&t);
    log.open("/Users/frez2zerovshik/Documents/Универ/Третий курс/Проекты xCode/TEHPROGA 2.2/TEHPROGA 2.2/log_aeroflot.txt",std::ios::app);
    for(int i = 0;i<LEN_UNDERSCORE;++i) log<<"-";
    log<<endl<<endl;
    log<<"Constructor copy: "<< now->tm_hour<<"."<<now->tm_min<<"."<<now->tm_sec<<endl;
    for(int i = 0;i<LEN_UNDERSCORE;++i) log<<"-";
    log<<endl<<endl;
    log.close();
}
Aeroflot:: Aeroflot (string dest,string num,string type){
    setDestination(dest);
    setNumber(num);
    setType(type);
    time_t t =time(0);
    tm* now = localtime(&t);
    log.open("/Users/frez2zerovshik/Documents/Универ/Третий курс/Проекты xCode/TEHPROGA 2.2/TEHPROGA 2.2/log_aeroflot.txt",std::ios::app);
    for(int i = 0;i<LEN_UNDERSCORE;++i) log<<"-";
    log<<endl<<endl;
    log<<"Constructor with params: "<< now->tm_hour<<"."<<now->tm_min<<"."<<now->tm_sec<<endl;
    for(int i = 0;i<LEN_UNDERSCORE;++i) log<<"-";
    log<<endl<<endl;
    log.close();
}
#pragma mark - destructor
Aeroflot::~Aeroflot(){
    log.open("/Users/frez2zerovshik/Documents/Универ/Третий курс/Проекты xCode/TEHPROGA 2.2/TEHPROGA 2.2/log_aeroflot.txt",std::ios::app);
    time_t t =time(0);
    tm* now = localtime(&t);
    for(int i = 0;i<LEN_UNDERSCORE;++i) log<<"-";
    log<<endl<<endl;
    log<<"Destructor called: "<< now->tm_hour<<"."<<now->tm_min<<"."<<now->tm_sec<<endl;
    for(int i = 0;i<LEN_UNDERSCORE;++i) log<<"-";
    log<<endl<<endl;
    log.close();
}
#pragma mark - operators
Aeroflot& Aeroflot::operator=(Aeroflot &op){
    if(&op == this)
        return *this;
    destination = op.getDestination();
    number = op.getNumber();
    type = op.getType();
    return *this;
}
bool Aeroflot::operator==(Aeroflot obj){
    if((destination == obj.getDestination()) &&
       (number == obj.getNumber()) &&
       (this->type == obj.getType())
       )
        return true;
    else
        return false;
}
#pragma mark - getters
string Aeroflot::getDestination(){
    return destination;
}
string Aeroflot::getNumber(){
    return number;
}
string Aeroflot::getType(){
    return type;
}
#pragma mark - setters
void Aeroflot::setDestination(string init){
    destination = init;
}
void Aeroflot::setNumber(string init){
    number = init;
}
void Aeroflot::setType(string init){
    type = init;
}
#pragma mark - print
void Aeroflot:: print(){
    cout << "Пункт назначения рейса: " << destination << endl << "Номер рейса: " << number << endl << "Тип самолета: " << getType() << endl << endl;
}
