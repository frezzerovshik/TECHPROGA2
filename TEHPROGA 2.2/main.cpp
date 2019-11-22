//
//  main.cpp
//  TEHPROGA 2.2
//
//  Created by Артем Шарапов on 18.11.2019.
//  Copyright © 2019 Артем Шарапов. All rights reserved.
//

#include <iostream>
#include "arr.hpp"
#include "reverse_sentences.hpp"
#include <Curses.h>
using namespace std;

int main(int argc, const char * argv[]) {
    bool runtimeFlag = true;
    do{
    try{
        Exception except;
        char src_mode{};
        char src_aeroflot{};
        bool isWorking_Choice_mode = true;
        bool isWorking_Choice_aeroflot = true;
        arr keeper;
        do{
            cout<<"Выберите задание:"<<endl<<"[1] первое задание - стандартные потоки"<<endl<<"[2] второе задание - строковые и файловые потоки"<<endl<<"[3] выход из программы"<<endl;
            cin>>src_mode;
            switch (src_mode) {
                case '1':{
                    do{
                        cout<<"Выберите функцию:"<<endl<<"[1] Добавить элемент в базу"<<endl<<"[2] Удалить элемент из базы"<<endl<<"[3] Вывести базу на экран"<<endl<<"[4] Найти все данные по искомуму типу воздухоплавательного судна"<<endl<<"Нажмите любую клавишу кроме [1;4] для выхода из режима"<<endl;
                        cin>>src_aeroflot;
                        switch (src_aeroflot) {
                            case '1':{
                                system("clear");
                                string number;
                                stringstream ss;
                                int num;
                                cout<<"Сколько объектов желаете добавить?"<<endl;
                                //Защита от неправильного ввода
                                cin>>number;
                                ss<<number;
                                ss>>num;
                                for(int i = 0;i<num;++i){
                                    Aeroflot temp;
                                    temp.getDataFromKeyboard();
                                    cout<<"Созданный объект"<<endl;
                                    temp.print();
                                    keeper+=temp;
                                }
                                break;
                            }
                            case '2':{
                                system("clear");
                                cout<<"Текущее содержимое базы:"<<endl;
                                keeper.print();
                                int num;
                                cout<<"Введите индекс элемента, который хотите удалить"<<endl;
                                cin>>num;
                                keeper-=num;
                                cout<<"Состояние базы после удаления"<<endl;
                                keeper.print();
                                break;
                            }
                            case '3':{
                                system("clear");
                                cout<<"Вывод базы данных"<<endl;
                                keeper.print();
                                break;
                            }
                            case '4':{
                                system("clear");
                                cout<<"Введите запрос (поиск по типу воздухоплавательного средства)"<<endl;
                                string ask;
                                cin>>ask;
                                keeper.search(ask);
                                break;
                            }
                            default:{
                                isWorking_Choice_aeroflot = false;
                                break;
                            }
                        }
                    }while(isWorking_Choice_aeroflot);
                    break;
                }
                case '2':{
                    system("clear");
                    ifstream stream;
                    reverse_sentences(stream);
                    break;
                }
                case '3':{
                    isWorking_Choice_mode = false;
                    runtimeFlag = false;
                    break;
                }
                default:
                    throw except.false_mode_src();
                    break;
                }
            }while(isWorking_Choice_mode);
        }
    catch(...){}
    }while(runtimeFlag);
    return 0;
}
