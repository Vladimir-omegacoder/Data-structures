#include "MyVector.h"


//#define CONSTRUCTOR
//#define DESTRUCTOR
//#define COPY_CONSTRUCTOR



template <class T>
mds::MyVector<T>::MyVector() {

    size = 0;
    capacity = 0;

    arr = nullptr;


#ifdef CONSTRUCTOR
    std::cout << "Constructor()\t\t" << arr << '\n';
#endif // CONSTRUCTOR


}

template<class T>
mds::MyVector<T>::MyVector(int size) {

    this->size = size;
    capacity = size;

    arr = new T[capacity]{};

#ifdef CONSTRUCTOR
    std::cout << "Constructor (size)\t" << arr << '\n';
#endif // CONSTRUCTOR


}

template<class T>
mds::MyVector<T>::MyVector(const std::initializer_list<T>& elements) {

    size = elements.size();
    capacity = size;

    arr = new T[capacity];

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
    capacity = vec.capacity;

    arr = new T[capacity];

    for (int i = 0; i < size; ++i) {

        arr[i] = vec[i];

    }


#ifdef COPY_CONSTRUCTOR
    std::cout << "Constructor COPY\t" << arr << '\n';
#endif // COPY_CONSTRUCTOR


}

template <class T>
mds::MyVector<T>::~MyVector() {

    if (arr != nullptr) {
        delete[] this->arr;
    }


#ifdef DESTRUCTOR
    std::cout << "Destructor\t\t" << arr << '\n';
#endif // DESTRUCTOR


}





template<class T>
mds::MyVector<T> mds::MyVector<T>::Select_sort()
{

    MyVector sorted_vector(this->size);
    sorted_vector.capacity = this->capacity;

    for (int i = 0; i < sorted_vector.Get_size(); ++i) {



    }

    return sorted_vector;

}


template <class T>
void mds::MyVector<T>::Pop_back() {

    --size;
    T* new_arr = new T[size];

    for (int i = 0; i < size; ++i) {

        new_arr[i] = arr[i];

    }

    delete[] arr;
    arr = new_arr;

}


template <class T>
void mds::MyVector<T>::Erase_all() {

    size = 0;
    capacity = 0;

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
T mds::MyVector<T>::Min() {

    if (size == 0) {

        return NULL;

    }

    T min = arr[0];

    for (int i = 1; i < size; ++i) {

        if (arr[i] < min) {

            min = arr[i];

        }

    }

    return min;

}


template <class T>
void mds::MyVector<T>::Append(T element) {

    if (size == capacity) {

        T* new_arr = new T[size + 1];

        for (int i = 0; i < size; ++i) {

            new_arr[i] = arr[i];

        }

        delete[] arr;

        arr = new_arr;

        capacity = size * 1.5;

    }

    arr[size] = element;

    ++size;

}





template <class T>
T& mds::MyVector<T>::operator [] (const int index) {

    if (index >= size) {
        throw;
    }
    else {
        return arr[index];
    }

}


template <class T>
const T& mds::MyVector<T>::operator [] (const int index) const {

    if (index >= size) {
        throw;
    }
    else {
        return arr[index];
    }

}


template <class T>
mds::MyVector<T>& mds::MyVector<T>::operator = (const MyVector<T>& vec) {

    if (this->arr == vec.arr) {

        return *this;

    }

    this->Erase_all();

    this->size = vec.size;

    this.capacity = vec.capacity;

    this->arr = new T[capacity];

    for (int i = 0; i < size; ++i) {

        this->arr[i] = vec[i];

    }

    return *this;

}