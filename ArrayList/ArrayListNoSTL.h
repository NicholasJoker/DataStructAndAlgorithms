//
// Created by Nicholas on 2023/9/15.
//

#ifndef DATASTRUCTANDALGORITHMS_ARRAYLISTNOSTL_H
#define DATASTRUCTANDALGORITHMS_ARRAYLISTNOSTL_H

#include "../linearList.h"
#include "../IllegalParaterValue/IllegalParaterValue.h"
template<class T>
class arrayListNoSTL:public linearList<T>
{
public:
    //容量
    arrayListNoSTL(int capacity=20);
    //传递一个数组的引用
    arrayListNoSTL(const arrayListNoSTL<T> &);
    //析构函数
    ~arrayListNoSTL();
    //判断数组为空
    bool empty(){
        return listSize<1;
    }
    //返回线性表元素个数
    int size();
    //容量
    int getCapacity();
    //获取索引
    int indexOf(const T& element);
    //插入元素
    int insert(int index,T& element);
    //删除元素
    void erase(int index);

    void output(ostream& out) const;

    void checkIndex(int index)const;

protected:
    T* array;
    //数组元素个数
    int listSize;
    //元素容量
    int capacity;
};

#endif //DATASTRUCTANDALGORITHMS_ARRAYLISTNOSTL_H
