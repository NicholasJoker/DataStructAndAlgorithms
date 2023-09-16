//
// Created by Nicholas on 2023/9/15.
//

#ifndef DATASTRUCTANDALGORITHMS_CHAIN_H
#define DATASTRUCTANDALGORITHMS_CHAIN_H
#include <sstream>
#include "../linearList.h";
//先定义一个单链表的结构
template<class T>
struct chainNode{
    //数据域
    T element;
    //指针域
    chainNode<T>* next;
    //构造方法
    chainNode()
    {

    }
    //只包含数据域的构造
    chainNode(const T& element)
    {
        this->element = element;
    }
    //包含数据域和指针域的构造
    chainNode(T& element,chainNode<T>* node){
        this->element = element;
        this->next = node;
    }
};
template<class T>
class chain: public linearList<T>
{
public:
    chain(int initialCapacity);
    //传引用
    chain(chain<T>& e);
    ~chain();
    //判断是否为空
    bool empty();
    //链表长度
    int size();
    //获取索引
    int indexOf(const T& element)const;
    //获取索引指定节点的数据域
    T& get(int index)const;
    //插入一个元素
    void insert(int index,T& element)const;
    //删除一个元素
    void erase(int index);
    //输出流
    void output(ostream& out) const;

protected:
    //头节点 指向链表第一个节点的指针 不是第一个节点元素 而是指向第一个节点元素的地址
    chainNode<T>* firstNode;
    //链表长度
    int listSize;
    //检测索引是否为空
    void checkIndex(int index)const;
};


#endif //DATASTRUCTANDALGORITHMS_CHAIN_H


