#include <iostream>
using namespace std;

template <typename T>
class Vector{
    private:
        int size;
        int capacity;
        T *array;
        void expand (int newCapacity);
    public:
        Vector(int initCapacity = 100);
        ~Vector();
        Vector<T>& operator=(Vector<T>& rhs); 
        int Size(); // ham tra ve kich thuoc
        bool empty(); // ham kiem tra vector giong
        T & operator[](int index);  // ham nap chong toan tu truy cap chi so vector
        void push_back(T newElement); // ham day phan tu vao cuoi vector
        T back(); //ham truy cap phan tu cuoi trong vector
        void pop_back();  //ham xoa phan tu cuoi vector
        void insert(int pos, T newElement); // ham them phan tu vao vi tri pos
        void erase(int pos); //ham xoa phan tu tai vi tri pos
        void clear(); // ham xoa tat ca cac phan tu vector	
        template <typename U>
        friend ostream& operator << (ostream&, const Vector<U>&);
};