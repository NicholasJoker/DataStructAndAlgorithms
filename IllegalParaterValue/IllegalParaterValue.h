//
// Created by Administrator on 2023/9/12.
//

#ifndef DATASTRUCTANDALGORITHMS_ILLEGALPARATERVALUE_H
#define DATASTRUCTANDALGORITHMS_ILLEGALPARATERVALUE_H

#endif //DATASTRUCTANDALGORITHMS_ILLEGALPARATERVALUE_H
#include <string>
#include <iostream>
//#include "IllegalParameterValue.h"
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
    illegalParameterValue(std::string str)
    {
        message =str;
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