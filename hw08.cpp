// hw08.cpp
// to illustrate pointers, pointer arithmetic & dynamic memory

/*************************************************************************
 * AUTHOR     : First Last
 * HW08       : pointers, pointer arithmetic & dynamic memory
 * CLASS      : CS 1C
 * SECTION    : Date & Time
*************************************************************************/

#include <iostream>

using namespace std;

// function definitions go into hw08.cpp:

// hw08.cpp

namespace hw08 {

const int ARRAY_SIZE = 5;
const int DYNAMIC_SIZE = 15;
const int TIC_TAC_TOE_SIZE = 3;

// function definitions:

//------------------------------------------------------------------------------

int  increment_value(int x)
    // pass a value, compute a new value by adding 5 to x and return it
{
    x += 5;
              // temp, replace when defining function
    return x; // included so that incomplete lab code will compile
}

void increment_pointer(int* p)
    // pass a pointer, increment value of p by 1
{
    *p += 1;
}      

void increment_reference(int& r)
    // pass a reference, increment value of r by 1
{
    r += 1;
}

//------------------------------------------------------------------------------

void print_2darray_subscript(double twoDD[][ARRAY_SIZE], int row, int col)
    // print array using subscripts
{
    for(int i=0;i<row;i++)
    {
        for(int j=0; j<col; j++) cout << twoDD[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

void print_2darray_pointer(double* twoDD, int row, int col)
    // print array using pointer arithmetic
{
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
            cout << *(twoDD + i * col + j) << " ";
        cout << endl;
    }
    cout << endl;
}

//------------------------------------------------------------------------------

void print_2darray_dynamic_subscript(int** twoDD, int row, int col)
    // print array using subscripts
{
    for(int i=0;i<row;i++)
    {
        for(int j=0; j<col; j++) 
            cout << twoDD[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

void print_2darray_dynamic_pointer(int** twoDD, int row, int col)
    // print array using pointer arithmetic
{
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
            cout << *(*(twoDD + i) + j) << " ";
        cout << endl;
    }
    cout << endl;
}

//------------------------------------------------------------------------------

double* dynamic_allocation_array_doubles(int array_size)
    // the caller is responsible for the memory allocated
{
    int* pi_array = new int[array_size];
    // function uses pi_array
    // function responsible for cleaning up (i.e. deleting) memory allocated for pi_array
    // do stuff here with pi_array
    for(int i = 0; i < array_size; i++)
        pi_array[i] = i*47;

    double* pd_array = new double[array_size];
    for(int i = 0; i < array_size; i++)
        pd_array[i] = pi_array[i];
    // ...    // dynamic memory allocated for pi_array not needed any longer, free it
    delete[] pi_array;
    return pd_array;
}

//------------------------------------------------------------------------------

} // hw08

//------------------------------------------------------------------------------

int main()
{
    // console header
	cout << endl;
	cout << "************************************** " << endl;
	cout << "*           Running HW08             * " << endl;
	cout << "*      Programmed by Nathan Milton   * " << endl;
	cout << "*      CS1C Tues/Thurs & 1:30pm      * " << endl;
	cout << "************************************** " << endl;
	cout << endl;

	// complete the following pointer examples
    // indicate if the requested operation is not allowed, why not?
	// Q#1 - pointer examples
    int x = 10;
    // ... // [1.1] variable p of type pointer to int points to x (i.e. int* p = ?;), use & to get the address of x
    // - valid - int pointer can store the address location of an int
    // ... // [1.2] variable q of type pointer to double is points to x
    // - invalid - double pointer can only point to a double object
    // ... // [1.3] update the value of p to 5, use * to assign to x through p
    // - invalid - that would dereference changing the pointer location to 5 
    // ... // [1.4] store the value of p in variable x2 of type int, use * to read x through p
    // - valid - dereference pointer to value of x
    // ... // [1.5] variable p2 of type pointer to int points to x2, use & to get a pointer to x2
    // - valid - & would be the value of the address location of x2 that is being pointed to
    // ... // [1.6] assign p to p2, p2 and p both point to x
    // - valid - both pointers point to the same location in memory
    // ... // [1.7] point p to x2, what does p2 point to now?
    // p and p2 both point to the same location in memory

	// complete the following reference examples
    // indicate if the requested operation is not allowed, why not?
	// Q#1 - reference examples
    int y = 50;
    int &r = y; // [1.8] variable r of type reference to int refers to y (i.e. int& r = ?;), nothing special to do here in the initializer
    // - valid - but r would be the memory location y. 
    //double &s = y; // [1.9] variable s of type reference to double refers to y
    // - invalid - references must have the same type as refered. 
    r = 10; // [1.10] update the value of r to 10, assign to y through r (notice * is not needed)
    // - valid - since & is not used its the value stored at the memory location.
    int y2 = r;// [1.11] store the value of r in variable y2 of type int, read y through r (notice * is not needed)
    // - valid - if r is of type int& than value can be stored. 
    int &r2 = y2; // [1.12] variable r2 of type reference to int refers to y2, get a reference to int y2
    // - valid - It will be the same as r2&.
    r2 = r; // [1.13] assign r to r2, the value of y is assigned to y2 
    r = y2; // [1.14] assign y2 to r, r2 and r both point to y2
    //int &r3; // [1.15] variable r3 of type reference to int is defined but not initialized (i.e. does not refer to an int)
    // - invalid - r3 needs to be intitalized before being used.

	// Q#1 - pointer vs reference: increment functions
    // implementation the function definitions for the following increment operations
    { // allows definition of variables within block scope avoiding redefinition errors
        int x = 100;
        int x2 = 25;
        int* p = &x2;
        int& r = x;

        cout << "increment pointer vs reference" << endl << endl;

        cout << x << endl;
        cout << hw08::increment_value(x) << endl; // x not changed when passed by value
        cout << x << endl;

        cout << x2 << endl;
        hw08::increment_pointer(p); // p points to x2, x2 updated
        cout << x2 << endl;

        cout << x << endl;
        hw08::increment_reference(r); // r refers to x, x updated
        cout << x << endl;
    }

	// complete the following pointer arithmetic examples
    // indicate if the requested operation is not allowed, why not?
	// Q#2 - pointer arithmetic
    double aDoubles[10];
    double aDoubles2[10];
    double* pd = &aDoubles[5]; // point to aDoubles[5]
    double* pd2 = &aDoubles[7]; // point to aDoubles[7]
    //double* pd3 = &aDoubles2[7]; // point to aDoubles[7]

    *pd = 3;
    pd[2] = 4;
    pd[-3] = 5;
    pd2[5] = 6;

    // pd + 3; // [2.1] move pd three elements to the right
    // pd - 6; // [2.2] move pd six elements to the left
    // pd += 1000;    // [2.3] // ... error explain
    // - causes pointer to go out of bounds of array.
    // double d = *pd;// [2.4] // ... error explain
    // - d not defined before being set to *pd. pd might be pointing to non double memory location. 
    // *pd = 12.34;   // [2.5] // ... error explain
    // - *pd not ititalized. memory location could be bad. 

    // int dif = pd - pd2; // [2.6] compute the number of elements between pd and pd2 by taking the difference between pd2 and pd
    // - difference = 2
    //int dif2 = pd + pd2; // [2.7] // ... error explain
    // - invalid operation for pointers. pointers need to be dereferenced.
    // int dif3 = pd2 - pd3;// [2.8] // ... error explain
    // - out of bounds of array. pointers need to be dereferenced. pd3 not declared. 

    cout << endl << "print array of doubles forward and backward" << endl << endl;

    // [2.9] print array going forwards
    // p starts at address aDoubles[0], ends at address &aDoubles[9], increment p, cout value pointed to by p
    for(double* p = &aDoubles[0]; p < &aDoubles[10]; p++) 
        cout << *p << '\n';
    cout << endl;

    // [2.10] print array going backwards
    // p starts at address aDoubles[9], ends at address &aDoubles[0], decrement p, cout value pointed to by p
    for (double* p = &aDoubles[9]; p >= &aDoubles[0]; p--) 
        cout << *p  << '\n';
    cout << endl;

    //double* pd4 = &aDoubles[0];
    //double* pd5 = aDoubles+5;
    double* pd6 = &aDoubles[5];
    double* pd7 = &aDoubles2[5];
    // [2.11] using the equality operator, compare pointers to array elements
    if (pd6 == pd7) 
        cout << "pointers point to the same element of the array" << endl;
    // [2.12] ... error explain
    // - arrays are different but they point to the same element.
    if (pd6 != pd7) 
        cout << "pointers point to the different elements of the array" << endl;

	// complete the following function implementations
	// Q#3 - pointer arithmetic, indexing multidimensional arrays
    double twoDDoubles[hw08::ARRAY_SIZE][hw08::ARRAY_SIZE] = {{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25}};
    
    cout << endl << "print 2d array of doubles" << endl << endl;

    // print 2ddoubles via subscript operator
    hw08::print_2darray_subscript(twoDDoubles, hw08::ARRAY_SIZE, hw08::ARRAY_SIZE);
    // print 2ddoubles via pointer arithmetic
    hw08::print_2darray_pointer((double*)twoDDoubles, hw08::ARRAY_SIZE, hw08::ARRAY_SIZE);

	// complete the following dynamic allocation examples
	// Q#4 - new, delete operator examples
    {
        int* pi = new int;                              // [4.1] allocate one int
        int* qi = new int[5];                           // [4.2] allocate five ints (an array of 5 ints)
        int& ri = *pi;
        int& ri2 = *qi;
        int*& ri3 = qi;
        ri = 100;
        ri2 = 200;

        double* pd = new double;                        // [4.3] allocate one double
        double* qd = new double[hw08::DYNAMIC_SIZE];    // [4.4] allocate DYNAMIC_SIZE doubles (an array of DYNAMIC_SIZE doubles)

        //pi = pd;  // [4.5] pi points to pd
                    // - int pointer being set to double pointer need to be of same type.  
        //pd = pi;  // [4.6] pd points to pi
                    // ... error explain
                    // - double pointer being set to an int pointer. Double pointer can not be converted to an int pointer.

        double x = *pd;       // read the (first) object pointed to by pd
        double y = qd[5];     // read the sixth object pointed to by qd
        double z = *(qd+10);  // read the tenth object pointed to by qd

        delete pd;
        delete [] qd;

        cout << endl << "ri, ri2, ri3 before delete" << endl << endl;

        cout << ri << endl;   // ri refers to *pi
        cout << ri2 << endl;  // ri2 refers to *qi
        cout << ri3 << endl;  // ri3 refers to qi

        delete pi;            // [4.7] how are the values of ri, ri2, ri3 affected by delete statement?
                              // - values are deleted from all but since ri3 already = a memory location it is unaffected.  
        delete [] ri3;        // [4.8] how are the values of ri, ri2, ri3 affected by delete statement?
                              // - r2 and r3 are now nullpointers - the original qi array is deleted because ri3 is a reference to the pointer to the address of *qi  

        cout << endl << "ri, ri2, ri3 after delete" << endl << endl;

        cout << ri << endl;
        cout << ri2 << endl;
        cout << ri3 << endl << endl;
    }

    double* array_of_doubles = hw08::dynamic_allocation_array_doubles(1000);
    // use array_of_doubles here
    for(int i = 0; i < 1000; i++)
        cout << array_of_doubles[i] << " ";
    cout << endl;
    delete array_of_doubles;
    delete[] array_of_doubles; // [4.9] free array, no longer needed

	// Q#5 - dynamic 2d arrays, indexing via subscript operator, pointer arithmetic

    // tic tac toe board is an array of int pointers
    // each int pointer in the board points to a row

    // declare a pointer to an array of int pointers (i.e. a pointer to a pointer of type int)
    int** p_p_tictactoe = new int*[hw08::TIC_TAC_TOE_SIZE]; //3
    // ...  // [5.1] row1: dynamically allocate int[TIC_TAC_TOE_SIZE], use initializer list to init to {1,0,0}
    p_p_tictactoe[0] = new int[hw08::TIC_TAC_TOE_SIZE] {1, 0, 0};
    // ...  // [5.2] row2: dynamically allocate int[TIC_TAC_TOE_SIZE], use initializer list to init to {0,1,0}
    p_p_tictactoe[1] = new int[hw08::TIC_TAC_TOE_SIZE] {0, 1, 0};
    // ...  // [5.3] row3: dynamically allocate int[TIC_TAC_TOE_SIZE], use initializer list to init to {0,0,1}
    p_p_tictactoe[2] = new int[hw08::TIC_TAC_TOE_SIZE] {0, 0, 1};

    // print 2dints via subscript operator
    hw08::print_2darray_dynamic_subscript(p_p_tictactoe, hw08::TIC_TAC_TOE_SIZE, hw08::TIC_TAC_TOE_SIZE);
    // print 2dints via pointer arithmetic
    hw08::print_2darray_dynamic_pointer(p_p_tictactoe, hw08::TIC_TAC_TOE_SIZE, hw08::TIC_TAC_TOE_SIZE);

    // clean up board, go in reverse order of declaration

    // [5.4] delete individual rows (i.e. rows are int arrays, use delete [])
    //for(// ...) // ...
    for(int i = 0; i < hw08::TIC_TAC_TOE_SIZE; i++)
        delete[] p_p_tictactoe[i]; 
    // [5.5] delete board (board is an array of int pointers, use delete [])
    delete[] p_p_tictactoe;

    return 0;
}

//------------------------------------------------------------------------------

// WRITTEN ANSWERS
// Q#1 - A pointer is a variable that equal to an address location that stores a value or variable and a reference is a alias for a variable that already exists. The difference between the two is that a pointer can be dereferenced to display the value at the address location that it is pointing to as well has change the location or value or varible that it is pointing to; a reference has neither of these functionalities.
// Another function that the pointer has is that it can be set to a null value. The refence can not be set to a null value.

// [1.1] - allowed because an int pointer can stores the address location of an int. & on a pointer returns address location.
// [1.2] - not allowed because a double pointer can only point to a double object.
// [1.3] - not allowed using the * would dereference the pointer and assign the value to the address location
// [1.4] - allowed deferencing the pointer to the value of x.
// [1.5] - allowed & would be the value of the address location of x2 that is being pointed to.
// [1.6] - allowed because both pointers point to the same location in memory.
// [1.7] - allowed. p and p2 would both point to the same location in memory.
//
// [1.8] - allowed. r refers to y using the same memory location.
// [1.9] - not allowed. reference need to be of the same type as refered. double != int.
// [1.10] - allowed. changes the value stored at shared memory location to 10.
// [1.11] - allowed. both of type int y2 store value stored at shared memory location of r and y,
// [1.12] - allowed. r2 and y2 share the same memory location.
// [1.13] - allowed.
// [1.14] - allowed. You explain 13 and 14 in main.
// [1.15] - not allowed. &r3 needs to be initalized before use.
//
// [2.3] - out of array bounds error.
// [2.4] - memory location not initalized before store data. *pd could be storing something other than double.
// [2.5] - *pd not initalized. Memory not allocated.
// [2.7] - out of array bounds when added.
// [2.8] - out of array bounds when substracted.

// Q#3 - The twoDDoubles array would be a contiguous block of memory. It is necessary to cast twoDDoubles as a double* because that is what the function protype was defined to expect. You need to pass the pointer value to use pointer arithmetic to mvoe throught the array. If the subscript operator was being used the double* cast could not be necessary becauset he [] would do the work of dereferencing.
//
// [4.5] - not allowed. Assigning an int pointer to a double pointer is not allowed. Could be type casting?
// [4.6] - not allowed. Double pointer can not be set to int pointer.
// [4.7] - values are deleted from the memory location. Since ri3 is already a memory location it is uneffected.
// [4.8] - allowed. r2 and r3 are now nullptr. The original qi array is deleted because ri3 is a reference to the pointer to the address of *qi.

//Q#5 - memory is non-contiguous because the three rows are allocated separately. A double pointer is passed to the print function because a double pointer with the subscript operator was used to allocate and declare the board. With the base double pointer that starts the array either pointer arithmetic or the subscript operator can be used to output the contents of the array in order.

