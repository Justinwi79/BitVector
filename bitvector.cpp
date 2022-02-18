//Harold Justin Windham
//BitVector
//COP3330
//Dr. Gaitros

#include <iostream>
#include "bitvector.h"
using namespace std;

const int DEFAULTSIZE = 256;   // Permenantly set default size of
                               //  array to 256

//************************************************
//* Default constructors to set default values   *
//* Referenced from Dr. Gaitros class and        *
//*  our course book Absolute C++                *
//************************************************
BitVector::BitVector()
{
    size = DEFAULTSIZE/32 + 1;
    bvect = new int[size];
}
BitVector::BitVector(size_t bits)
{
    size = bits / 32 + 1;
    bvect = new int[size];
    bitlocations = 0;
}

//******************************************
//*  Test function from                    *
//*  Dr. Gaitros office hours  2/10/21     *
//*  Checks bit value                      *
//******************************************
bool BitVector::Test(size_t index) const
{
    int mask = 1;
    mask = mask << (index % 32);
    int status = 0;
    status = bvect[index / 32] & mask;
    if(status != 0)
        return true;
    else return false;
}

//********************************************************
//* Set and Unset functions referenced from Dr. Gaitros  *
//*  class meetings and from cplusplus.com               *
//* Sets index bit to one, then all bits to one.         *
//* Sets index bit to zero, then all bits to zero.       *
//********************************************************
void BitVector::Set(const size_t index)
{
    int mask = 1;
    mask = mask << (index % 32);
    bvect[index / 32] = bvect[index / 32] | mask;
}

void BitVector::Set()
{
    for(int i=0; i<size; i++)
        bvect[i]=-1;
}

void BitVector::Unset(const size_t index)
{
    for(int i = 0; i < 32 * size; i++)
    {
        if(Test(i)==true)
            Flip(i);
    }
}
void BitVector::Unset()
{
    for(int i = 0; i < size; i++)
    bvect[i] = 0;
}

//**************************************************
//* Flip functions referenced from Dr. Gaitros     *
//*  class 2/11/21                                 *
//*  reverses all bits from off or on.             *
//**************************************************
void BitVector::Flip(const size_t index)
{
    int mask = 1;
    mask = mask << (index % 32);
    bvect[index / 32] = bvect[index / 32] ^ mask;
}

void BitVector::Flip()
{
    for(int i = 0; i < 32 * size; i++)
        Flip(i);
}

size_t BitVector::Size() const   // Returns vector size
{
    return size; 
}

BitVector::~BitVector()     // Destructor erases array
{
    delete [] bvect;
}

//**********************************************************
//* Assignment operator contributed by Christopher Freytes *
//*  during office hours 2/8/21                            *
//* Initializes bvect to be equal to bv.bvect              *
//**********************************************************
BitVector::BitVector(const BitVector& bv)
{
    size = bv.size;
    bvect = new int[size];
    for(size_t i = 0; i < size; ++i)
    {
        bvect[i] = bv.bvect[i];
    }
}

//****************************************************************
//* Assignment operator from John Wu of University of California *
//*  via github                                                  *
//* Returns size of bvect equal to bv.bvect                      *
//****************************************************************
BitVector& BitVector::operator=(const BitVector& bv)
{
    if(size == bv.size)
    {
        for(int i = 0; i < size; i++)
        bvect[i] = bv.bvect[i];
    }
    return *this;
        
}


void BitVector::Print()    // Prints vector by checking if bit is on or off.
{

    for(int index=0; index<32; index++)
        if(Test(index) == true) cout << "Index " << index << " is on." << endl;
        else cout << "Index " << index << " is off." << endl; 
    
}
