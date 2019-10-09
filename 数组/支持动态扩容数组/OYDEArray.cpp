//
//  OYDEArray.cpp
//  DynamicExpansionArray
//
//  Created by 欧阳铨 on 2019/10/9.
//  Copyright © 2019 com.OYQ. All rights reserved.
//

#include "OYDEArray.hpp"
#include <iostream>

#define OYArraySize 10  //每次扩容的数组大小，每次增加10

using namespace std;

template<typename T> bool OYArray<T>::init(){
    base = (T *)malloc(OYArraySize*sizeof(T));
    if (!base) {
        return false;
    }
    size = OYArraySize;
    length = 0;
    return true;
}

template<typename T> bool OYArray<T>::ensureCapcity(){
    if (length >= size) { //当前数组中元素数量大于等于数组大小
        T *newBase = (T *)realloc(base, OYArraySize * sizeof(T) + size);
        if (!newBase) {
            //扩容失败
            return false;
        }
        
        base = newBase;
        size += OYArraySize;
        newBase = nullptr;
    }
    return true;
}

template<typename T> bool OYArray<T>::add(T item){
    if (!ensureCapcity()) {
        //容量不足，并且没办法扩容，返回失败
        return false;
    }
    
    T *p = base + length;
    *p = item;
    length++;
    return true;
}

template<typename T> bool OYArray<T>::insert(int index, T item){
    if (!ensureCapcity()) {
        //容量不足，并且没办法扩容，返回失败
        return false;
    }
    
    if (index < 0 || index > length) {
        //超出区域
        return false;
    }
    
    T *q = base + length - 1;
    T *p = base + index;
    //数据搬移，往后移动一位
    while (q >= p) {
        *(q+1) = *q;
        q--;
    }
    *p = item;
    q = nullptr;
    p = nullptr;
    length++;
    return true;
}

template<typename T> T OYArray<T>::del(int index){
    if (index < 0 || index > length) {
        //超出区域
        return NULL;
    }
    
    //数据搬移，用后面的数据覆盖前一位
    T *q = base + length - 1;
    T *p = base + index;
    T temp = *p;
    
    while (p < q) {
        *p = *(p+1);
        p++;
    }
    
    p = nullptr;
    q = nullptr;
    length--;
    return temp;
}

template<typename T> T OYArray<T>::objectAt(int index){
    if (index < 0 || index > length) {
        //超出区域
        return NULL;
    }
    
    return *(base + index);
}

template<typename T> void OYArray<T>::display(){
    T *q = base;
    T *p = base + length - 1;
    while (q<=p) {
        cout << *(q++) << "";
    }
    q = nullptr;
    p = nullptr;
    cout << endl;
}


