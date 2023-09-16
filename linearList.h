//
// Created by Administrator on 2023/9/13.
//

#ifndef DATASTRUCTANDALGORITHMS_LINEARLIST_H
#define DATASTRUCTANDALGORITHMS_LINEARLIST_H

#include <iostream>
using namespace std;
//定义一个抽象的线性表
template<class T>
class linearList{
public:
    //析构函数
    virtual ~linearList(){};
    //判断是否为空
    virtual bool empty() const = 0;
    //返回线性表元素个数
    virtual int size() const = 0;
    //返回索引元素
    virtual T& get(int theIndex)const = 0;
    //返回元素第一次出现的索引
    virtual int indexOf(const T& element)const = 0;
    //删除索引为theIndex的元素
    virtual void erase(int theIndex) = 0;
    //将元素element 插入到index的位置
    virtual void insert(int index,const T& element) = 0;
    //将线性表插入输出流
    virtual void output(ostream& out) const = 0;
};
#endif;