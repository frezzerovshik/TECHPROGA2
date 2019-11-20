//
//  main.cpp
//  TEHPROGA 2.2
//
//  Created by Артем Шарапов on 18.11.2019.
//  Copyright © 2019 Артем Шарапов. All rights reserved.
//

#include <iostream>
#include "arr.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    try{
        int i =1;
        arr keeper;
        string test("h");
        Aeroflot clear;
        Aeroflot buf(test,test,test);
        clear = buf;
        while(i!=0){
            string temp;
            Aeroflot tmp;
            cout<<"Введите пункт назначения: "<<endl;cin>>temp;tmp.setDestination(temp);
            cout<<"Введите номер рейса: "<<endl;cin>>temp;tmp.setNumber(temp);
            cout<<"Введите тип самолета: "<<endl;cin>>temp;tmp.setType(temp);
            keeper+=tmp;
            cout<<"Продолжать?"<<endl;cin>>i;
        }
        keeper.print();
        cout<<"Элемент который необходимо уебать отсюда"<<endl;
        buf.print();
        keeper-=clear;
        keeper.print();
    }
    catch(...){}
    return 0;
}
