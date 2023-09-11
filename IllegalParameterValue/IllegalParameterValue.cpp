//
// Created by Nicholas on 2023/9/12.
//

#include "IllegalParameterValue.h"
//
// Created by Nicholas on 2023/9/11.
//
#include <string>
#include <iostream>
#include "IllegalParameterValue.h"
//
// Created by Administrator on 2023/9/7.
//
//异常类型
class illegalParameterValue{

public:
    //不带参数
    illegalParameterValue()
    {
        message = "illegal Parameter Value";
    };
    illegalParameterValue(char * str){
        message = str;
    }
    void outputMessage(){
        std::cout<<""<< std::endl;
    }
    //定义一个用于输出的字符串类型
private: std::string message;
};
