#include <ostream>
#include "../linearList.h"
#include "ArrayList.h"
using namespace std;
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
void arrayList<T>::output(ostream& out) const{
    std::copy(array,array+listSize,ostream_iterator<T>(std::cout," "));
}
//运算符重载
template<class T>
ostream & operator<<(ostream& out,const arrayList<T>& x){
    x.outputStream(out);
    return out;
};
