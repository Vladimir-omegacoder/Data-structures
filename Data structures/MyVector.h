#pragma once

#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif // !IOSTREAM









namespace mds {



//#define CONSTRUCTOR
//#define DESTRUCTOR
//#define COPY_CONSTRUCTOR



    template <class T>
    class MyVector {



    private:

        int size;
        T* arr;





    public:


        MyVector();

        MyVector(int size);

        MyVector(const std::initializer_list<T>& elements);

        MyVector(const MyVector<T>& vec);

        ~MyVector();





        //Delete all the elements in the vector
        void Erase();


        int Get_size() { return this->size; }


        T Max();


        void Append(T element);





        //operator []
        T& operator [] (const int index);

        //operator const []
        const T& operator [] (const int index) const;

        //operator =
        MyVector<T>& operator = (const MyVector<T>& vec);


    };

}
