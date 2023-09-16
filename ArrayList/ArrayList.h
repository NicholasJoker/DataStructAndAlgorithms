//
// Created by Administrator on 2023/9/13.
//

#ifndef DATASTRUCTANDALGORITHMS_ARRAYLIST_H
#define DATASTRUCTANDALGORITHMS_ARRAYLIST_H


#include <sstream>
#include "../linearList.h"
#include "../IllegalParaterValue/IllegalParaterValue.h"
#include<algorithm>
template<class T>
class arrayList : public linearList<T>
{
public:
    //构造函数
    arrayList(int initialCapacity =20);
    //拷贝构造函数 (传递数组的引用)
    arrayList(const arrayList<T>&);
    //析构函数 会释放array指向的全部内存空间 逐一调用数组中元素的析构
    ~arrayList(){delete[] array;};
    //根据数组中元素的个数判断是否为空
    bool empty() const{
        return listSize==0;
    }
    //返回线性表元素的个数
    int size()const{
        return listSize;
    }
    //返回索引元素
    T& get(int theIndex)const;
    //返回元素索引
    int indexOf(const T& element) const;
    //删除元素
    void erase(int theIndex);
    //插入元素
    void insert(int index,const T& element);
    //输出流
    void output(std::ostream& out) const;
    //获取容量
    int getCapacity(){
        return capacity;
    }
protected:
    //线性表的初始容量
    int capacity;
    //数组的元素个数
    int listSize;
    //存储线性表元素的一维数组 (指针)
    T* array;
    //检测索引是否为空
    void checkIndex(int index)const;

};
#endif //DATASTRUCTANDALGORITHMS_ARRAYLIST_H