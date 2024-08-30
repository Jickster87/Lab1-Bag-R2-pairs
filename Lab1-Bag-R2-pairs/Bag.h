#pragma once
#include <utility>
//DO NOT INCLUDE BAGITERATOR


//DO NOT CHANGE THIS PART
typedef int TElem;
typedef int TKey;
typedef int TFreq;
typedef std::pair<TKey, TFreq> TPair;
#define NULL_TPAIR pair<TKey, TFreq>(-111111, -111111);

#define NULL_TELEM -111111;


class BagIterator;
class Bag {

private:
	//TODO - Representation
    TPair* mainArray;
    int bagTotalCapacity;
    int bagSize;

	//DO NOT CHANGE THIS PART
	friend class BagIterator;
public:
	//constructor
	Bag();

	//adds an element to the bag
	void add(TElem e);

	//removes one occurence of an element from a bag
	//returns true if an element was removed, false otherwise (if e was not part of the bag)
	bool remove(TElem e);

	//checks if an element appearch is the bag
	bool search(TElem e) const;

	//returns the number of occurrences for an element in the bag
	int nrOccurrences(TElem e) const;

	//returns the number of elements from the bag
	int size() const;

	//returns an iterator for this bag
	BagIterator iterator() const;

	//checks if the bag is empty
	bool isEmpty() const;

	//destructor
	~Bag();
};
