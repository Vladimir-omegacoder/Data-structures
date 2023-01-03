#include "MyVector.h"




template<class T>
mds::MyVector<T>::MyVector() {

    size = 0;

    arr = nullptr;


#ifdef CONSTRUCTOR
    std::cout << "Constructor()\t\t" << arr << '\n';
#endif // CONSTRUCTOR


}

template<class T>
mds::MyVector<T>::MyVector(int size) {

    this->size = size;

    this->arr = new T[size]{};


#ifdef CONSTRUCTOR
    std::cout << "Constructor (size)\t" << arr << '\n';
#endif // CONSTRUCTOR


}

template<class T>
mds::MyVector<T>::MyVector(const std::initializer_list<T>& elements) {

    size = elements.size();

    arr = new T[size];

    int i = 0;
    for (auto j : elements) {

        arr[i] = j;
        ++i;

    }


#ifdef CONSTRUCTOR
    std::cout << "Constructor init_list\t" << arr << '\n';
#endif // CONSTRUCTOR


}

template <class T>
mds::MyVector<T>::MyVector(const MyVector<T>& vec) {

    size = vec.size;

    arr = new T[size];

    for (int i = 0; i < size; ++i) {

        arr[i] = vec[i];

    }


#ifdef COPY_CONSTRUCTOR
    std::cout << "Constructor COPY\t" << arr << '\n';
#endif // COPY_CONSTRUCTOR


}

template <class T>
mds::MyVector<T>::~MyVector() {

#ifdef DESTRUCTOR
    std::cout << "Destructor\t\t" << arr << '\n';
#endif // DESTRUCTOR

    if (arr != nullptr) {
        delete[] this->arr;
    }

}





template <class T>
void mds::MyVector<T>::Erase() {

    this->size = 0;

    if (arr != nullptr) {

        delete[] this->arr;

    }

    arr = nullptr;

}


template <class T>
T mds::MyVector<T>::Max() {

    if (size == 0) {

        return NULL;

    }

    T max = arr[0];

    for (int i = 1; i < size; ++i) {

        if (arr[i] > max) {

            max = arr[i];

        }

    }

    return max;

}


template <class T>
void mds::MyVector<T>::Append(T element) {

    T* new_arr = new T[size + 1];

    for (int i = 0; i < size; ++i) {

        new_arr[i] = arr[i];

    }

    new_arr[size] = element;

    delete[] arr;

    arr = new_arr;

    ++size;

}





template <class T>
T& mds::MyVector<T>::operator [] (const int index) {

    return arr[index];

}


template <class T>
const T& mds::MyVector<T>::operator [] (const int index) const {

    return arr[index];

}


template <class T>
mds::MyVector<T>& mds::MyVector<T>::operator = (const MyVector<T>& vec) {

    if (this->arr == vec.arr) {

        return *this;

    }

    this->Erase();

    this->size = vec.size;

    this->arr = new T[size];

    for (int i = 0; i < size; ++i) {

        this->arr[i] = vec[i];

    }

    return *this;

}