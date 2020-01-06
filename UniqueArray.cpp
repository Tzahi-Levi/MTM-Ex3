#include <iostream>
using namespace std;

class UniqueArray {
    unsigned int size;
    int* data;
    int nextIndex;
    int currentNumberOfElements;

    //TODO Adjust the Constructor to a generic Element and not only for int.
    UniqueArray(unsigned int size==1) : size(size), nextIndex(0), currentNumberOfElements(0) {
        data = new int[size];
        for (int i=0; i<size ; i++){
            data[i] = 0;
        }
    }

    //TODO Adjust the Constructor to a generic Element and not only for int.
    UniqueArray(const UniqueArray& other) : size(other.size), nextIndex(other.nextIndex),
                                            currentNumberOfElements(other.currentNumberOfElements),
                                            data(new int[other.size]) {
        for (int i=0; i<nextIndex; i++){
            data[i] = other.data[i];
        }
    }

    //TODO Adjust the Destructor to a generic Element and not only for int.
    ~UniqueArray(){
        delete[] data;
    }

    unsigned int insert(const Element& element){
         //TODO add Exception in case UniqueArray is full.

        for (int i=0; i<nextIndex ; i++) {
            if (data[i] == elemet) {
                currentNumberOfElements++;
                return i;
            }
            if(data[i] == 0){

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

    const Element* operator[](const Element& element) const {
        int tempIndex;
        if(getIndex(element, tempIndex)){
            return *data[tempIndex];
        }
        return  NULL;
    }

    unsigned int count() const{
        return currentNumberOfElements;
    }

    unsigned int size() const{
        return size;
    }
};