//
// Created by Fantasy’s Mac on 2018/4/3.
//

#ifndef SMART_PTR_SHARED_PTR_H
#define SMART_PTR_SHARED_PTR_H

template<class T>
class shared_ptr {
private:
    int *count;     //reference count
    T *ptr;         //real pointer
public:
    shared_ptr(T *n);

    ~shared_ptr();

    T *get();

    shared_ptr(const shared_ptr &);

    shared_ptr &operator=(const shared_ptr &);

};

//get the real pointer
template<class T>
T *shared_ptr<T>::get() {
    return ptr;
}

//new from an object reference
template<class T>
shared_ptr<T>::shared_ptr(T *n):ptr(n) {
    count = new int(1);
    printf("Constructor called!\n");
}

//copy Constructor
template<class T>
shared_ptr<T>::shared_ptr(const shared_ptr<T> &p) {
    (*p.count)++;
    ptr = p.ptr;
    count = p.count;
}

//Destructor, destruct only if the reference count equals 0
template<class T>
shared_ptr<T>::~shared_ptr() {
    (*count)--;
    if (*count == 0) {
        delete count;
        delete ptr;
        count = nullptr;
        ptr = nullptr;
        printf("Destructor is called!\n");
    }
}

//=号操作符，返回自己，这样可以实现链式操作。等号左边的指针所指向的对象引用计数要先减一。
template<class T>
shared_ptr<T> &shared_ptr<T>::operator=(const shared_ptr &p) {
    (*count)--;
    if (*count == 0) {
        delete count;
        delete ptr;
        printf("Destroy the old object!\n");
    }
    (*p.count)++;
    count = p.count;
    ptr = p.ptr;
    return *this;
}

#endif //SMART_PTR_SHARED_PTR_H
