//
//  displayArray.cpp
//  MergeSortedArray
//
//  Created by 欧阳铨 on 2019/10/12.
//  Copyright © 2019 com.OYQ. All rights reserved.
//

#include <iostream>

using namespace std;

template<typename T> void displayArray(T array[], int size){
    for (int i = 0; i < size; i++) {
        cout << array[i] << "";
    }
    cout << endl;
}
