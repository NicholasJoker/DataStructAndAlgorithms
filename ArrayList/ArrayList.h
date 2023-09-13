//
// Created by Administrator on 2023/9/13.
//

#ifndef DATASTRUCTANDALGORITHMS_ARRAYLIST_H
#define DATASTRUCTANDALGORITHMS_ARRAYLIST_H


#include <sstream>
#include "../IllegalParaterValue/IllegalParaterValue.h"
#include "linearList.h"
//#include "stdlib.h"
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
    bool isEmpty() const{
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
    void outputStream(std::ostream& out) const;
    //获取容量
    int Capacity(){
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
template <class T>
arrayList<T>::arrayList(int initialCapacity) {
    if(initialCapacity<1)
    {
        ostringstream s;
        s<<"initialCapacity = "<<initialCapacity<<"必须>0";
        throw illegalParameterValue(s.str());
    }
    capacity = initialCapacity;
    //申请一段这么长的内存空间
    array = new T[capacity];
    //初始化数组元素的个数为零
    listSize = 0;
}
template <class T>
arrayList<T>::arrayList(const arrayList<T>& list){
    //容量
    capacity = list.capacity;
    //数组元素数量
    listSize = list.listSize;
    //数组
    array = new T(capacity);
    std::copy(list.array,list.array+listSize,array);
}
template <class T>
void arrayList<T>::checkIndex(int index)const{
    if(index<0)
    {
        std::ostringstream s;
        s<<"index = "<<index<<"必须大于等于0";
        throw illegalParameterValue(s.str());
    }
}
template <class T>
T& arrayList<T>::get(int theIndex)const{
    checkIndex(theIndex);
    return array[theIndex];
}
template <class T>
int arrayList<T>::indexOf(const T& element) const{
    int index = (int)(find(array,array+listSize,element)-array);
    //如果找到末尾还没有找到
    if(index == listSize)
    {
        return -1; //找不到
    }
    else{
        return index;
    }
}
template<class T>
void arrayList<T>::erase(int theIndex){
    //首先检测元素
    checkIndex(theIndex);
    //移动位置 从theIndex 的下一个位置开始移动 往前挪动 这样最后一个元素就空出来了
    copy(array+theIndex+1,array+listSize,array+listSize);
    //调用最后一个元素的析构函数
    array[--listSize].~T();
}
template<class T>
void changeLength(T& a,int oldLength,int newLength)
{
    if(newLength<0)
    {
        std::ostringstream s;
        s<<"newLength = "<<newLength<<"必须大于0";
        throw illegalParameterValue(s.str());
    }
    T* t = new T(newLength);
    int num = std::min(oldLength,newLength);
    copy(a,a+num,t);
    delete[]a;
    a = t;
}
template<class T>
void arrayList<T>::insert(int index, const T &element) {
    if(index<0||index>listSize)
    {
        ostringstream s;
        s<<"index = "<<index<<"size = "<<listSize;
        throw illegalParameterValue(s.str());
    }
    //先判断是否已经满了
    if(index ==capacity)
    {
        //扩容2
        changeLength(array,capacity,capacity*2);
        capacity *= 2;
    }
    //往后移动
    copy_backward(array+index,array+listSize,array+listSize+1);
    array[index] = element;
    listSize++;
}
template<class T>
void arrayList<T>::outputStream(ostream& out) const{
    std::copy(array,array+listSize,ostream_iterator<T>(std::cout," "));
}
//运算符重载
template<class T>
ostream & operator<<(ostream& out,const arrayList<T>& x){
    x.outputStream(out);
    return out;
};
#endif //DATASTRUCTANDALGORITHMS_ARRAYLIST_H