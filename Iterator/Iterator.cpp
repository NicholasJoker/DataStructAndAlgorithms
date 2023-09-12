//
// Created by Administrator on 2023/9/12.
//
//iterator是一种特殊的类型  检测容器内元素并遍历元素的数据类型

//value_type 类型指定 获取原类型  原生char*  int*  *it 获得原类型

#ifndef MYITERATOR_H
#define MYITERTOR_H

template<class T>
class Iterator{
public:
    typedef T value_type;
    //定义一个Iterator 类型
    Iterator(T* p=0):ptr_(p){};

    //运算符重载 重载& 实现解引用获取类型对象地址(指针)
    T& operator*()const{return *ptr_;};
    //重载-> 实现获取类型对象
    T* operator->()const(return ptr_;);

    //重载加法运算符
    //返回自增的地址 前缀++
    Iterator& operator++(){
        ptr_ = prt_+1;
        return *this;
    }
    //返回自增的对象 后缀++
    Iterator operator++(int){
        Iterator temp = *this;
        ++*this;
        return temp;
    }
    unsigned operator-(const Iterator &i)const
    {
        return ptr_-i.ptr;
    }
    Iterator operator-(const int &i)
    {
        Iterator temp = *this;
        temp.ptr_ = temp.prt_-i;
        return temp;
    }
    Iterator operator+(const int &i)
    {
        Iterator temp = *this;
        temp.prt_ = temp.prt_+i;
        return temp;
    }
    //判断地址是否相等
    bool operator == (const Iterator &i)const{
        return prt_ == i.prt_;
    }

    bool operator != (const Iterator &i)const{
        return prt_ != i.prt_;
    }
    //判断内容相等
    bool operator != (const T &i)const{
        return (*prt_)!=a;
    }
private:
    T*prt_;
};

//获取所指定类型
template<class It>
struct iterator_traits
{
    typedef typeName It::value_type value_Type;
};
template<class It>
struct iterator_traits<It*>
{
    typedef It value_type;
};