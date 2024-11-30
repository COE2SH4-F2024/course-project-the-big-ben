#include "objPosArrayList.h"

// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.

objPosArrayList::objPosArrayList() //initializing our arrayList
{
    arrayCapacity = ARRAY_MAX_CAP;
    listSize = 0;

    aList = new objPos[arrayCapacity];
    for(int i = 0; i<arrayCapacity; i++){
        aList[i] = objPos();
    }
}

objPosArrayList::~objPosArrayList()
{
    delete aList;
}

int objPosArrayList::getSize() const
{
    return listSize;
}


void objPosArrayList::insertHead(objPos thisPos)
{
    listSize++;

    objPos temp = thisPos;
    objPos prevVal;

    for(int i = 0; i<listSize; i++){
        prevVal = aList[i];
        aList[i] = temp;
        temp = prevVal;
    }
    
    
    

}

void objPosArrayList::insertTail(objPos thisPos)
{
    aList[listSize] = thisPos;
    listSize++;
}

void objPosArrayList::removeHead()
{
    listSize--;
    for(int i = 0; i<listSize; i++){
        aList[i] = aList[i+1];
    }
}

void objPosArrayList::removeTail()
{
    listSize--;
}

objPos objPosArrayList::getHeadElement() const
{
    return aList[0];
}

objPos objPosArrayList::getTailElement() const
{
    return aList[(listSize-1)];
}

objPos objPosArrayList::getElement(int index) const
{
    return aList[index];
}
