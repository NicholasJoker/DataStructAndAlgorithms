#include <sstream>
#include "iostream";
#include "stdlib.h";
class illegalParameterValue
{
public:
    illegalParameterValue():
    message("illegal Parameter Value"){}
    illegalParameterValue(char* theMeaage)
    {
        message = theMeaage;
    }
    void outputMessage(){
        std::cout<<message<<std::endl;
    }
private:
    std::string message;
};
//线性表
template<class T>
class linearList
{
public:
    virtual ~linearList(){};
    //判断是否为空
    virtual bool empty()const = 0;
    //返回元素数量
    virtual int size() const =0;
    //返回索引元素
    virtual T& get(int theIndex) const = 0;
    //返回theElement第一次出现的索引
    virtual int indexOf(const T& theElement) const = 0;
    //删除索引元素
    virtual void erase(int index);
    //把元素插入到特定位置
    virtual void insert(int index,const T& element);
    //插入到输出流
    virtual void output(std::ostream& out)const = 0;
};

template<class T>
class arrayList:public linearList<T>
{
public:
    //构造函数 复制构造函数 析构函数
    arrayList(int initialCapacity=10);
    arrayList(const arrayList<T>&);
    ~arrayList(){delete [] element;}

    //ADT 方法
    //判断是否为空
    bool empty() const {return listSize == 0;}
    //获取长度
    int size() const{return listSize;};
    T& get(int theIndex) const;
    //索引
    int indexOf(const T& theElement) const;
    //删除索引元素
    void erase(int index);
    void insert(int index,const T& theElement);
    void output(std::ostream& out) const;
    int capacity() const{return arrayLength;};

protected:
    int arrayLength;
    int listSize;
    T* element;
    void checkIndex(int theIndex) const;
};
template<class T>
arrayList<T>::arrayList(int initialCapacity){
    //检测是否越界
    if(initialCapacity<1)
    {
        std::ostringstream s;
        s<<"capacity= "<<initialCapacity<<"must be >0";
        throw illegalParameterValue
    }
}



