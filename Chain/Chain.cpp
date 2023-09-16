//
// Created by Nicholas on 2023/9/15.
//
#include <sstream>
#include "Chain.h"
#include "../IllegalParaterValue/IllegalParaterValue.h"

template<class T>
chain<T>::chain(int initialCapacity){
    if (initialCapacity<1)
    {
        if(initialCapacity<1)
        {
            ostringstream s;
            s<<"initialCapacity = "<<initialCapacity<<"必须>0";
            throw illegalParameterValue(s.str());
        }
        firstNode = NULL;
        listSize = 0;
    }
}
//传引用
template<class T>
chain<T>::chain(chain<T>& e){
    listSize = e.listSize;
    //先判断长度
    if(listSize<1)
    {
        ostringstream s;
        s<<"listSize = "<<listSize<<"必须>0";
        firstNode = NULL;
        throw illegalParameterValue(s.str());
    }
    //定义一个节点 克隆一下e 的firstNode
    chainNode<T>* temp = e.firstNode;
    //构造firstNode 把头节点接上去
    firstNode = new chainNode<T>(temp->element);
    //让temp 指向下一个节点
    temp = temp->next;
    //构建一个后继节点   target (从头开始)
    chainNode<T>* target = firstNode;
    //相当于迭代器
    while (target!=NULL)
    {
        target->next = new chainNode<T>(temp->element);
        target = target->next;
        temp = temp->next;
    }
    //此时的temp 是尾节点
    temp->next = NULL;
}
template<class T>
chain<T>::~chain(){
    //从头开始删除
    while (firstNode!=NULL)
    {
        //先接收一下头节点的 后继
        chainNode<T>* s = firstNode->next;
        delete firstNode;
        //将后继节点复制给头节点
        firstNode = s;
    }
}
//判断是否为空
template<class T>
bool chain<T>::empty(){
    return listSize<1;
}
//链表长度
template<class T>
int chain<T>::size(){
    return listSize;
}
//获取索引
template<class T>
int chain<T>::indexOf(const T& element) const{
    //从头节点开始遍历
    chainNode<T>* temp = firstNode;
    int index = 0;
    while (temp!=NULL&&temp->element!=element)
    {
        temp = temp->next;
        index++;
    }
    return  index;
}
template<class  T>
T& chain<T>::get(int index) const{

    if(index<0)
    {
        ostringstream s;
        s<<"index = "<<index<<"必须>=0";
        firstNode = NULL;
        throw illegalParameterValue(s.str());
    }
    chainNode<T>* temp = firstNode;
    for (int i = 0; i < index; ++i) {
        temp = temp->next;
    }
    return temp->element;
}
//插入一个元素
template<class T>
void chain<T>::insert(int index,T& element)const{
    if(index<0||listSize<index)
    {
        ostringstream s;
        s<<"index = "<<index<<"必须>=0 and <=listSIze";
        firstNode = NULL;
        throw illegalParameterValue(s.str());
    }
    //刚好在头部
    if(index ==0)
    {
        //直接复制给头节点
        firstNode = new chainNode<T>(element);
    }
    else{
        //先找到这个位置的前驱 temp
        chainNode<T>* temp = firstNode;
        for (int i = 0; i < index-1; ++i) {
            temp = temp->next;
        }
        temp->next = new chainNode<T>(index,element);
    }
    chain<T>::listSize++;
}
//删除一个元素
template<class T>
void chain<T>::erase(int index){
    if(index<0)
    {
        ostringstream s;
        s<<"index = "<<index<<"必须>=0";
        firstNode = NULL;
        throw illegalParameterValue(s.str());
    }
    chainNode<T>* free;
    //要释放的节点刚好在头部
    if(index ==0)
    {
        //直接复制给头节点
        free = firstNode;
        firstNode = firstNode->next;
    }
    else{
        //先找到这个位置的前驱 temp
        chainNode<T>* temp = firstNode;
        for (int i = 0; i < index-1; ++i) {
            temp = temp->next;
        }
        free = temp->next;
        //需要删除的是temp的后继  先去拿到temp后继的后继节点。重新复制给temp的后继
        temp->next = temp->next->next;
    }
    delete free;
    chain<T>::listSize--;
}
//输出流
template<class T>
void chain<T>::output(ostream& out) const{
    for (chainNode<T>* temp = firstNode;temp!=NULL;temp = temp->next) {
        out<<"chainNode<T>"<<temp->element<<endl;
    }
}