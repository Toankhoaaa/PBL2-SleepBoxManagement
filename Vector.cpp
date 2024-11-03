#include <iostream>
#include "Vector.h"

using namespace std;

template <typename T>
Vector<T>::Vector (int initCapacity){
    size=0;
    capacity = initCapacity;
    array = new T[capacity];
}

template <typename T>
Vector<T>::~Vector(){
    delete[] array;
}

template <typename T>
void Vector<T>::expand(int newCapacity){
    if (newCapacity <= size)
	        return;
	T * old = array;            
	array = new T[newCapacity]; 
	for (int i = 0; i < size; i++)
	    array[i] = old[i];      
	delete[] old;              
	capacity = newCapacity;  
}   

template <typename T>
Vector<T>& Vector<T>:: operator = (Vector& rhs){
	if (this != &rhs) {
	    delete[] array;          
	    size = rhs.size;         
	    capacity = rhs.capacity; 
	    array = new T[capacity]; 
	    
	    for (int i = 0; i < size; i++)
	        array[i] = rhs.array[i];
	}
	return *this; 
}

template <typename T>
int Vector<T>::Size(){
    return size;
}

template <typename T>
bool Vector<T>::empty(){
    return (size==0);
}
template <typename T>
T& Vector<T>::operator[] (int index){
   return array[index];
}
template <typename T>
void Vector<T>::push_back(T newElement){
    if (size == capacity)
	    expand(2 * size);
	array[size] = newElement;
	size++;
}
template <typename T>
T Vector<T>::back(){
	if (size > 0){
		return array[size-1];
	}
}
template <typename T>
void Vector<T>::pop_back(){
	if (size > 0){
		--size;
	}else{
		cout << "Vector khong hop le" << endl;
	}
	// for (int i=size-1; i>0 ;i--){
	// 	array[i+1] = array[i];
	// }
}
template <typename T>
void Vector<T>::insert(int pos, T newElement){
    if (size == capacity)
	        expand(2 * size);
	    
	    for (int i = size; i > pos; i--)
	        array[i] = array[i - 1];
	        
	    array[pos] = newElement;
	    
	    size++;
}
template <typename T>
void Vector<T>::erase(int pos){
    for (int i=pos;i<size-1;i++){
        array[i]= array[i+1];
    }
    size--;
}
template <typename T>
void Vector<T>::clear(){
    size==0;
}
template <typename T>
ostream& operator << (ostream& o, const Vector<T>& vt){
    for (int i=0;i< vt.size;i++){
        o << *(vt.array + i) << endl;
    }
	return o;
}