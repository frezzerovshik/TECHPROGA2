//
//  Aeroflot.hpp
//  TEHPROGA 2.2
//
//  Created by Артем Шарапов on 18.11.2019.
//  Copyright © 2019 Артем Шарапов. All rights reserved.
//

#pragma once
/*1.
 Стандартные потоки
 Определить класс с именем АЕRОFLОТ, содержащий следующие поля:
 ● название пункта назначения рейса;
 ● номер рейса;
 ● тип самолета.
 Определить методы доступа к этим полям и перегруженные операции извлечения и вставки для объектов типа АЕRОFLОТ.
 Заранее число объектов не известно.
 Написать программу, выполняющую следующие действия:
 ● записи должны быть размещены в алфавитном порядке по названиям
 пунктов назначения;
 ● вывод на экран пунктов назначения и номеров рейсов,
 обслуживаемых самолетом, тип которого введен с клавиатуры;
 ● если таких рейсов нет, выдать на дисплей соответствующее
 сообщение.
 2. Файловые и строковые потоки
 С использованием файловых и строковых потоков написать программу, которая считывает из текстового файла три предложения и выводит их в обратном порядке.*/
#include <string>
#include <fstream>
#include "Exception.hpp"
using namespace std;
class Aeroflot:public Exception{
    string destination;
    string number;
    string type;
    ofstream log;
public:
    void setDestination(string init);
    void setNumber(string init);
    void setType(string init);
    
    string getDestination();
    string getNumber();
    string getType();
    
    void getDataFromKeyboard();
    
    Aeroflot();
    Aeroflot(const Aeroflot& init);
    Aeroflot (string dest,string num,string type);
    ~Aeroflot();
    
    Aeroflot& operator=(Aeroflot& op);
    bool operator==(Aeroflot obj);
    void print();
};
