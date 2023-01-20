#pragma once

#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif // !IOSTREAM









namespace mds {

    template <class T>
    class MyVector {



    private:

        int size;
        int capacity;
        T* arr;


    public:


        MyVector();

        MyVector(int size);

        MyVector(const std::initializer_list<T>& elements);

        MyVector(const MyVector<T>& vec);

        ~MyVector();


        //TODO
        MyVector Select_sort();

        void Pop_back();

        void Erase_all();

        int Get_size() { return this->size; }

        int Get_capacity() { return this->capacity; }

        T Max();

        T Min();

        void Append(T element);





        //operator []
        T& operator [] (const int index);

        //operator const []
        const T& operator [] (const int index) const;

        //operator =
        MyVector<T>& operator = (const MyVector<T>& vec);


    };
    


}

#include "MyVector.inl"