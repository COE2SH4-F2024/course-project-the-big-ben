#include "objPosArrayList.h"

objPosArrayList::objPosArrayList() //initializing our arrayList
{
    arrayCapacity = ARRAY_MAX_CAP;
    listSize = 0;

    aList = new objPos[arrayCapacity];
    for(int i = 0; i<arrayCapacity; i++){
        aList[i] = objPos();
    }
}

objPosArrayList::~objPosArrayList()     //destructor
{
    delete[] aList;
}

int objPosArrayList::getSize() const
{
    return listSize;
}

void objPosArrayList::insertHead(objPos thisPos)    //insert objPos at head of the list
{
    for (int i = listSize; i > 0; i--) {
        aList[i] = aList[i - 1];
    }
    aList[0] = thisPos;
    listSize++;
    
}

void objPosArrayList::insertTail(objPos thisPos)    //insert objPos at tail of the list
{
    aList[listSize] = thisPos;
    listSize++;
}

void objPosArrayList::removeHead()      //removes head objPos from list
{
    listSize--;
    for(int i = 0; i<listSize; i++){
        aList[i] = aList[i+1];
    }
    aList[listSize] = objPos();
}

void objPosArrayList::removeTail()      //remove tail objPos from list
{
      if(listSize >0){
        listSize--;
        aList[listSize] = objPos();
    }
}

//getter functions
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
