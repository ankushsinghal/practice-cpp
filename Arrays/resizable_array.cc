/**
 *  @author       : Ankush Singhal [ankushsinghal1995@gmail.com]
 *  @date         : Sunday, 19th May, 2019
 *  @description  : Source file for Resizable Array Class
 *  @file         : resizable_array.cpp
 */

#include "resizable_array.h"

ResizableArray::ResizableArray(){
    this->size_ = 0;
    this->capacity_ = 16;
    this->arr_ = new int[16];
}

ResizableArray::~ResizableArray(){
    delete[] this->arr_;
}

int ResizableArray::size(){
    return this->size_;
}