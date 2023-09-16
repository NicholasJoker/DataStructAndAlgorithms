//
// Created by Nicholas on 2023/9/12.
//
#include <iostream>
#include "linearList.h"
#include "ArrayList/ArrayList.h"
void TestArrayList()
{

    linearList<double> *x = new arrayList<double>(20);
//    linearList<double> *x = new arrayList<double>(20);
    arrayList<int> y(2), z;
//
//    // test capacity
    cout << "Capacity of x, y and z = "
         << ((arrayList<double>*) x)->getCapacity() << ", "
         << y.getCapacity() << ", "
         << z.getCapacity() << endl;
}
int main() {

    linearList<double> *x = new arrayList<double>(10);

    std::cout << "Hello, World!" << std::endl;
    TestArrayList();
    return 0;
}
