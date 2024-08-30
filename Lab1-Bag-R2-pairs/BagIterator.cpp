#include <exception>
#include "BagIterator.h"
#include "Bag.h"

using namespace std;


BagIterator::BagIterator(const Bag& c): bag(c)
{
    currentPosition = 0;
    freqCount = 1;
}

void BagIterator::first() {
    currentPosition = 0;
    freqCount = 1;
}


void BagIterator::next() {
    //TODO - Implementation
    if (currentPosition == bag.bagSize) {
        throw exception();
    }
    freqCount++;
    if (freqCount > bag.mainArray[currentPosition].second) {
        currentPosition++;
        freqCount = 1;
    }
}


bool BagIterator::valid() const {
    //TODO - Implementation
    return currentPosition < bag.bagSize;
}



TElem BagIterator::getCurrent() const
{
    if (currentPosition == bag.bagSize) {
        throw exception();
    }
    return bag.mainArray[currentPosition].first;
}
