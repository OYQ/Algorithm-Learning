//
//  OYDEArray.hpp
//  DynamicExpansionArray
//
//  Created by 欧阳铨 on 2019/10/9.
//  Copyright © 2019 com.OYQ. All rights reserved.
//

#ifndef OYDEArray_hpp
#define OYDEArray_hpp

//#include <stdio.h>

template <class T>

class OYArray{
private:
    T *base; //数组首地址
    int length; //当前数组中元素个数
    int size; //数组大小
    
public:
    bool init();//初始化
    bool ensureCapcity(); //判断是否需要扩容，如果需要，增加容量
    bool add(T item); //添加到队尾
    bool insert(int index, T item); //添加元素到某一个位置
    T del(int index); //删除指定位置元素
    T objectAt(int index); //返回指定位置元素
    void display(); //打印所有元素
    
};

#endif /* OYDEArray_hpp */
