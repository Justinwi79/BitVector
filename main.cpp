//Harold Justin Windham
//BitVector
//COP3330
//Dr. Gaitros

#include <iostream>
#include "bitvector.h"

using namespace std;
int main() {
    BitVector  DefaultVector;
    BitVector  BigVector(500);
    BitVector  CopyVector(DefaultVector);// Copy Constructor; 
    CopyVector = DefaultVector; 	// Assignment Overload 
    DefaultVector.Set(16); 		// Test set all bits to one. 
    DefaultVector.Print(); 
    DefaultVector.Unset(); 		// Unset all bits.
    DefaultVector.Print();  
    DefaultVector.Set(16); 		// Set one bit. 
    DefaultVector.Flip(16); 		// Flip the bit. 
    DefaultVector.Flip(); 		// Test flip all.
    DefaultVector.Unset(16); 		// Test Unset for a single bit.  
    cout<< "Test the call to Test()" << DefaultVector.Test(16) << endl; 
    cout<< "Test the call to Size()" << DefaultVector.Size() << endl; 
    
    DefaultVector.Print(); 
    return 0;
}