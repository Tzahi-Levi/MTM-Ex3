#ifndef MTMPARKINGLOT_UNIQUEARRAY_H
#define MTMPARKINGLOT_UNIQUEARRAY_H


template <class Element>
template <class Element, class Compare = std::equal_to<Element>>
class UniqueArray {
    unsigned int size;
    Element* data;
    bool* dataInfo;
    int nextIndex;
    int currentNumberOfElements;
public:

    UniqueArray(unsigned int size==1) : size(size), nextIndex(0), currentNumberOfElements(0) {
                                        dataInfo(new bool[size]),
                                        //TODO צריך להגדיר את הבנאי ככה שלא יסתמך על כך שיש בנאי ריק דיפולטיבי לאלמנט
                                        data(new Element[size]);
        for (int i=0; i<size ; i++){
            dataInfo[i] = false;
        }
    }
    UniqueArray(const UniqueArray& other) : size(other.size), nextIndex(other.nextIndex),
                                            currentNumberOfElements(other.currentNumberOfElements),
                                            dataInfo(new bool[other.size]),
                                            //TODO צריך להגדיר את הבנאי ככה שלא יסתמך על כך שיש בנאי ריק דיפולטיבי לאלמנט
                                            data(new Element[other.size]) {
        for (int i=0; i<nextIndex; i++){
            dataInfo[i] = other.dataInfo[i];
            //TODO מניחים שיש פה אופרטור השמה לאלמנט האם זה בסדר?
            data[i] = other.data[i];
        }
        for (int i=nextIndex; i<size; i++){
            dataInfo[i] = false;
    }
        ~UniqueArray(){
            delete [] dataInfo;
            delete[] data;
        }
    UniqueArray& operator=(const UniqueArray&) = delete;
    unsigned int insert(const Element& element){
        //TODO add Exception in case UniqueArray is full.

        for (unsigned int i=0; i<nextIndex; i++) {
            if (data[i] == elemet /*TODO יש פה הנחה שיש אופרטור השוואה*/) {
                return i;
            }
            if(dataInfo[i] == false){
                //TODO יש פה הנחה שיש אופרטור השמה
                data[i] = element;
                dataInfo[i] = true;
                currentNumberOfElements++
                return i;
            }
        }
        dataInfo[nextIndex] = true;
        currentNumberOfElements++;
        return nextIndex++;
    }
    bool getIndex(const Element& element, unsigned int& index) const;
    const Element* operator[] (const Element& element) const;
    bool remove(const Element& element);
    unsigned int getCount() const;
    unsigned int getSize() const;

    class Filter {
    public:
        virtual bool operator() (const Element&) const = 0;
    };
    UniqueArray filter(const Filter& f) const;

    class UniqueArrayIsFullException{};
    
};

#include "UniqueArrayImp.h"


#endif //MTMPARKINGLOT_UNIQUEARRAY_H
