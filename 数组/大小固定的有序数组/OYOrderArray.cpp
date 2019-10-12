//
//  OYOrderArray.cpp
//  OrderedArray
//
//  Created by 欧阳铨 on 2019/10/9.
//  Copyright © 2019 com.OYQ. All rights reserved.
//

#include "OYOrderArray.h"
#include <iostream>

using namespace std;

bool OYOrderArray::init(int arraySize){
    if (arraySize <= 0) {
        return false;
    }
    base = (int *)malloc(arraySize * sizeof(int));
    if (!base) {
        return false;
    }
    size = arraySize;
    length = 0;

    return true;
}

bool OYOrderArray::add(int num){
    if (length >= size) {
        return false;
    }

    //遍历数组，找到合适的位置插入
    int *p = base;
    int *q = base + length - 1;
    int *temp = p;
    while (p <= q) {
        if (*p <= num) {
            p++;
            temp = p;
        }else{
            break;
        }
    }

    //在此位置的数据往后移动
    while (q >= p) {
        *(q+1) = *q;
        q--;
    }
    
    *temp = num;
    length++;
    q = nullptr;
    p = nullptr;
    return true;
}

bool OYOrderArray::del(int index){
    if (index >= length) {
        return false;
    }
    //将index后的数据往前移
    int *p = base + index;
    int *q = base + length - 1;
    
    while (p <= q) {
        *p = *(p+1);
        p++;
    }
    length--;
    q = nullptr;
    p = nullptr;
    
    return true;
}

bool OYOrderArray::replace(int index, int num){
    return del(index) && add(num);
    return true;
}

void OYOrderArray::display(){
    int *q = base;
    int *p = base + length - 1;
    while (q <= p) {
        cout << *(q++) << "";
    }
    q = nullptr;
    p = nullptr;
    cout << endl;
}
