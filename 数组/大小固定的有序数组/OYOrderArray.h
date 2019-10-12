//
//  OYOrderArray.h
//  OrderedArray
//
//  Created by 欧阳铨 on 2019/10/12.
//  Copyright © 2019 com.OYQ. All rights reserved.
//

#ifndef OYOrderArray_h
#define OYOrderArray_h
class OYOrderArray{
private:
    int *base; //数组首地址
    int length; //当前数组中元素个数

public:
    int size; //数组大小

    bool init(int arraySize); //初始化数组
    bool add(int num); //插入元素
    bool del(int index); //删除坐标为index的元素
    bool replace(int index, int num); //将坐标为index的元素修改为num
    void display(); //打印数组
};

#endif /* OYOrderArray_h */
