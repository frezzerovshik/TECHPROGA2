//
//  Exception.hpp
//  TEHPROGA 2.2
//
//  Created by Артем Шарапов on 20.11.2019.
//  Copyright © 2019 Артем Шарапов. All rights reserved.
//

#pragma once
class Exception{
public:
    int not_found_exc();
    int empty_exc();
    int object_doesnt_exist_exc();
    int trouble_with_log_file();
    int zero_lenght_string_exc();
    int no_sentences_exc();
    int false_mode_src();
};
