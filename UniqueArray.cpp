#include <iostream>
using namespace std;

class UniqueArray {
    unsigned int size;
    int* data;
    int nextIndex;
    int currentNumberOfElements;

    UniqueArray(unsigned int size==1) : size(size), nextIndex(0), currentNumberOfElements(0) {
        data = new int[size];
        for (int i=0; i<size ; i++){
            data[i] = 0;
        }
    }

    UniqueArray(const UniqueArray& other) : size(other.size), nextIndex(other.nextIndex),
                                            currentNumberOfElements(other.currentNumberOfElements),
                                            data(new int[other.size]) {
        for (int i=0; i<nextIndex; i++){
            data[i] = other.data[i];
        }
    }

    ~UniqueArray(){
        delete[] data;
    }

    unsigned int insert(const Element& element){
        for (int i=0; i<nextIndex ; i++) {
            if (data[i] == elemet or data[i] == 0) {
                currentNumberOfElements++;
                return i;
            }
        }
            currentNumberOfElements++;
            return nextIndex++;
    }
    bool getIndex(const Element& element, unsigned int& index) const{
        for (int i=0; i<nextIndex ; i++) {
            if (data[i] == element) {
                index = i;
                return true;
            }
        }
            return false;
    }
    unsigned int count() const{
        return currentNumberOfElements;
    }
    unsigned int size() const{
        return size;
    }
};