// Last Update:2014-03-19 11:24:53
/**
 * @file smart-pointer.h
 * @brief a simple smart pointer class
 * @author shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-03-18
 */
#ifndef SMART-POINTER_H
#define SMART-POINTER_H

#include <iostream>
#include <cassert>
using namespace std;

/*
 * smart pointer class
 * reference count
 * a utility class is needed for implementation
 */
class HasPtr{
public:
    HasPtr(int *p): ptr(new U_Ptr(p)){
    }

    ~HasPtr() {
        if(--ptr->n == 0) delete ptr;
    }

    // copy control
    HasPtr(const HasPtr& rhs)
    : ptr(rhs.ptr){
        ++ ptr->n;
    }

    HasPtr& operator=(const HasPtr& rhs){
        ++ rhs.ptr->n;
        if(-- ptr->n == 0) delete ptr;
        ptr = rhs.ptr;
        return *this;
    }

    // operator overload for * and ->
    int& operator*(){
        return *(ptr->p_);
    }
    const int& operator*() const{
        return *(ptr->p_);
    }
    int* operator->(){
        return ptr->p_;
    }
    const int* operator->() const{
        return ptr->p_;
    }
private:
    // utility class only for HasPtr
    class U_Ptr{
        friend class HasPtr;
        U_Ptr(int *p): p_(p), n(1) { } 
        ~U_Ptr() { delete p_; }

        size_t n;
        int *p_;
    };

    U_Ptr *ptr;
};


#endif  /*SMART-POINTER_H*/
