/**
 *  @author       : Ankush Singhal [ankushsinghal1995@gmail.com]
 *  @date         : Sunday, 19th May, 2019
 *  @description  : Header file for Resizable Array Class
 *  @file         : resizable_array.h
 */

#ifndef RESIZABLE_ARRAY_H
#define RESIZABLE_ARRAY_H

#include <stdio.h>
#include <malloc.h>

class ResizableArray{

private:
    
    int capacity_;
    int size_;
    int *arr_;

public:

    ResizableArray();
    ~ResizableArray();
    int size();
};

#endif // RESIZABLE_ARRAY_H