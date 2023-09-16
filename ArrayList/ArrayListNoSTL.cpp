//
// Created by Nicholas on 2023/9/15.
//
#include "ArrayListNoSTL.h"
#include <sstream>

using namespace std;
template <class T>
arrayListNoSTL<T>::arrayListNoSTL(int initialCapacity)
{

    if(initialCapacity<1)
    {
        ostringstream s;
        s<<"initialCapacity = "<<initialCapacity<<"必须>0";
        throw illegalParameterValue(s.str());
    }
    array = new T[initialCapacity];
    listSize = 0;
    capacity = initialCapacity;
}
template <class T>
arrayListNoSTL<T>::arrayListNoSTL(const arrayListNoSTL<T>& list){
    //
    listSize = list.listSize;
    //
    capacity = list.capacity;
    array = new T[capacity];
    //不使用copy函数 直接一个个复制
    for (int i = 0; i < list.listSize; ++i) {
        array[i] = list.array[i];
    }
}
template<class T>
arrayListNoSTL<T>::~arrayListNoSTL() {
    delete[] array;
}

//返回线性表元素个数
template<class T>
int arrayListNoSTL<T>::size()
{
    return  listSize;
};

//容量
template<class T>
int arrayListNoSTL<T>::getCapacity(){
    return capacity;
}
//获取索引
template<class T>
int arrayListNoSTL<T>::indexOf(const T& element) {
    for (int i = 0; i < listSize; ++i) {
        if(element == array[i])
        {
            return  i;
        }
    }
    return  -1;
}
template<class T>
void changeLength(T*& a,int oldLength,int newLength)
{
    if(newLength<0)
    {
        std::ostringstream s;
        s<<"newLength = "<<newLength<<"必须大于0";
        throw illegalParameterValue(s.str());
    }
    T* t = new T[newLength];
    int num = std::min(oldLength,newLength);
    copy(a,a+num,t);
    delete[]a;
    a = t;
}
//插入元素
template<class T>
int arrayListNoSTL<T>::insert(int index,T& element)
{
//    int _index = -1;
//    for (int i = 0; i < listSize; ++i) {
//        if(element == array[i])
//        {
//            _index = i;
//        }
//    }
    if(index<0||index>listSize)
    {
        ostringstream s;
        s<<"index = "<<index<<"size = "<<listSize;
        throw illegalParameterValue(s.str());
    }
    if(capacity<listSize+1)
    {
        changeLength(array,capacity,2*capacity);
        capacity*=2;
    }
    for (int i = listSize-1; i >=index; i--) {
        array[i] =array[i+1];
    }
    array[index] = element;
    listSize++;
}
//删除元素
template<class T>
void arrayListNoSTL<T>::erase(int index){
    checkIndex(index);
//    for (int i = index; i < listSize-1; ++i) {
//        array[index] = array[index+1];
//    }
//    array[--listSize].~T();
    for (int i = index+1; i < listSize; ++i) {
        array[i-1] = array[i];
    }
    array[--listSize].~T();
}
template <class T>
void arrayListNoSTL<T>::checkIndex(int index)const{
    if(index<0)
    {
        std::ostringstream s;
        s<<"index = "<<index<<"必须大于等于0";
        throw illegalParameterValue(s.str());
    }
}
template<class T>
void arrayListNoSTL<T>::output(ostream& out) const{
    std::copy(array,array+listSize,ostream_iterator<T>(std::cout," "));
}
//运算符重载
template<class T>
ostream & operator<<(ostream& out,const arrayListNoSTL<T>& x){
    x.outputStream(out);
    return out;
};
