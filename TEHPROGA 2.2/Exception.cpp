//
//  Exception.cpp
//  TEHPROGA 2.2
//
//  Created by Артем Шарапов on 20.11.2019.
//  Copyright © 2019 Артем Шарапов. All rights reserved.
//

#include "Exception.hpp"
#include <iostream>

using namespace std;

int Exception::not_found_exc(){
    cout << "Объект не найден в массиве" << endl;
    return 0;
}
int Exception::empty_exc(){
    cout<<"Массив пуст, искать негде, заполните массив"<<endl;
    return 0;
}
int Exception::object_doesnt_exist_exc(){
    cout<<"Такого объекта не существует"<<endl;
    return 0;
}
int Exception::trouble_with_log_file(){
    cout<<"Проблемы с лог-файлом"<<endl;
    return 0;
}
