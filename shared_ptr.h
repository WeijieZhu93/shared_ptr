//
// Created by Fantasy’s Mac on 2018/4/3.
//

#ifndef SMART_PTR_SHARED_PTR_H
#define SMART_PTR_SHARED_PTR_H

template<class T>
class shared_ptr {
private:
    int *count;
    T *ptr;
public:
    shared_ptr(T *n);

    ~shared_ptr();

    T* get();

    shared_ptr(const shared_ptr &);

    shared_ptr &operator=(const shared_ptr &);

};
template <class T>
T* shared_ptr<T>::get() {
    return ptr;
}
template<class T>
shared_ptr<T>::shared_ptr(T *n):ptr(n) {
    count = new int(1);
    printf("Constructor called!\n");
}

template<class T>
shared_ptr<T>::shared_ptr(const shared_ptr<T> &p) {
    (*p.count)++;
    ptr = p.ptr;
    count = p.count;
}

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
