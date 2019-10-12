//
//  MergeSortedArray.cpp
//  MergeSortedArray
//
//  Created by 欧阳铨 on 2019/10/12.
//  Copyright © 2019 com.OYQ. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

int * merge2SortedArray(int *array0, int array0Size,int *array1, int array1Size){
    if (array0Size <= 0) {
        return array1;
    }
    
    if (array1Size <= 0) {
        return array0;
    }
    
    int i = 0, j = 0, index = 0;
//    int temp[array1Size+array0Size];
    int *temp = (int *)malloc((array1Size+array0Size)*sizeof(int));
    
    while (i < array0Size && j < array1Size) {
//        if (array0[i] < array1[j]) {
//            temp[index] = array0[i];
//        }else{
//
//        }
        if (*(array0+i) <= *(array1+j)) {
            *(temp+index) = *(array0+i);
            i++;
        }else{
            *(temp+index) = *(array1+j);
            j++;
        }
        index++;
    }
    
    if (i < array0Size) {
        while (i < array0Size) {
            *(temp+index) = *(array0+i);
            i++;
            index++;
        }
    }
    
    if (j < array1Size) {
        while (j < array1Size) {
            *(temp+index) = *(array1+j);
            j++;
            index++;
        }
    }
    
    return temp;
}
