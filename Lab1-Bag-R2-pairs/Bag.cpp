#include "Bag.h"
#include "BagIterator.h"
#include <exception>
#include <iostream>
using namespace std;


Bag::Bag() {
    bagSize = 0;
    bagTotalCapacity = 32;
    mainArray = new TPair[bagTotalCapacity];

}


void Bag::add(TElem elem) {
	//resize
    if (bagTotalCapacity == bagSize) {
        bagTotalCapacity *= 2;
        TPair* tempArray = new TPair[bagTotalCapacity];
        int i = 0;
        while (i < bagSize) {
            tempArray[i] = mainArray[i];
            i++;
        }
        delete [] mainArray;
        mainArray = tempArray;
    }
    
    //add
    bool found = false;
    int i;
    for (i = 0; i < bagSize; i++) {
        if (mainArray[i].first == elem) {
            found = true;
            break;
        }
    }
    
    if (found) {
        mainArray[i].second++;
    } else {
        mainArray[bagSize].first = elem;
        mainArray[bagSize].second = 1;
        bagSize++;
    }
}


bool Bag::remove(TElem elem) {
    bool found = false;
    int i;
    for (i=0; i < bagSize; i++) {
        if (mainArray[i].first == elem) {
            found = true;
            break;
        }
    }
    if (found) {
        if (mainArray[i].second > 1)
        {
            mainArray[i].second--;
        } 
        else
        {
            mainArray[i] = mainArray[bagSize-1];
            bagSize--;
        }
        return true;
    }
	return false;
}


bool Bag::search(TElem elem) const {
    int i;
    for (i=0; i<bagSize; i++) {
        if (mainArray[i].first == elem) {
            return true;
        }
    }
	return false;
}

int Bag::nrOccurrences(TElem elem) const {
    for (int i=0; i<bagSize; i++) {
        if (mainArray[i].first == elem) {
            return mainArray[i].second;
        }
    }
	return 0;
}


int Bag::size() const {
    int totalSize=0;
    for (int i=0; i<bagSize; i++) {
        totalSize += mainArray[i].second;
    }
	return totalSize;
    //return bagSize;
}


bool Bag::isEmpty() const {
	//TODO - Implementation
	return bagSize==0;
}

BagIterator Bag::iterator() const {
	return BagIterator(*this);
}


Bag::~Bag() {
	//TODO - Implementation
    delete [] mainArray;
}
