/*********************************************************************************
*
* Author:           Allyson Warren
* Email:            allywarren7@gmail.com
* Label:            P01
* Title:            Stack Upgrade
* Course:           2143
* Semester:         Fall 2020
*
* Description:
*       This program takes an Array-based stack and is given values to be
*       pushed and popped taken from an input file. The stack then
*       implements checks to prevent popping an empty Array-based stack or
*       causing any overflow. If overflow occurs then the stack is then
*       doubled to make space for new data.
*
* Usage:
*       None for now
*
* Files:
*       main.cpp        :  driver program
*       (Add text input file later)
*
*******************************************************************************/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/**
 * Stack
 *
 * Description:
 *      Integer array based stack implementation
 *
 * Public Methods:
 *      - Stack()
 *      - Stack(int)
 *      - void Push()
 *      - int Pop()
 *      - bool empty()
 *      - bool full()
 *      - void Print()
 *      - int getInitialSize()
 *      - int getMaxSize()
 *      - int getLastSize()
 *
 * Private Methods:
 *      - None
 *
 * Usage:
 *
 *  Stack S;
 *  S.Push(80);
 *  S.Push(90);
 *  S.Print();
 *  int x = S.Pop();
 *  S.getInitialSize();
 *  S.getMaxSize();
 *  S.getLastSize();
 *
 */
class Stack {
private:
    int* S;       //array pointer
    int capacity; //max stack size
    int top;      //current top (index)
    int size;     //current num items
    int MinSize;  //Minimum size of stack
    int MaxSize;  //Maximum size of array
public:
    /**
     * Stack:
     *    Default Constructor.
     * Params:
     *    void
     *
     * Returns:
     *     Void
     */
    Stack() {
        capacity = 10;          // set array size
        S = new int[capacity];  // allocate new memory
        top = -1;               // initialize top of stack
        size = 0;               // set stack to empty
        MinSize = capacity;     //Minimum size of array
        MaxSize = MinSize;      //Starting array is largest size initially
    }

    /**
     * Stack:
     *    Constructor.
     * Params:
     *    int : capacity
     *
     * Returns:
     *     Void
     */
    Stack(int cap) {
        capacity = cap;         // set array size      
        S = new int[capacity];  // allocate new memory
        top = -1;               // initialize top of stack
        size = 0;               // set stack to empty
        MinSize = capacity;     //Minimum size of array
        MaxSize = MinSize;      //Starting array is largest size initially
    }

    /**
     * Push:
     *    Push item onto stack.
     * Params:
     *    int : data
     *
     * Returns:
     *     Void
     */
    void Push(int data) {

        if (Full())                                         // Stack size is full
        {
            int* newStack = new int[capacity * 2];          // New stack with doubled size
            for (int x = 0; x < capacity; x++)
            {
                newStack[x] = S[x];                         // Fill new stack with current values
            }
            delete[] S;                                     // Delete previous stack
            S = newStack;                                   // point to new stack
                                                            // Print to screen the change in array size
            cout << "+ : " << capacity << " -> " << capacity * 2 << endl;       

            capacity *= 2;                                  // Double capacity for new stack size
            if (MaxSize < capacity)
                MaxSize = capacity;                         // Get the largest possible size of stack
        }
                                                            // Stack has space for data
        top++;                                              // Move top of stack up
        size++;                                             // Increment size
        S[top] = data;                                      // Add item to array

        if((capacity != MinSize) && (size < capacity/2))    // Shrink array if the number of value is less than half the size of the array
        {
            int* newStack = new int[capacity / 2];          // New stack with half previous size
            for (int x = 0; x < capacity / 2; x++)
            {
                newStack[x] = S[x];                         // Fill new stack with current values
            }
            delete[] S;                                     // Delete previous stack
            S = newStack;                                   // Point to new stack
                                                            // Print to screen change in array size
            cout << "- : " << capacity << " -> " << capacity / 2 << endl;

            capacity /= 2;                                  //Current capacity is half the size of before
        }
    }

    /**
     * Pop:
     *    remove item from stack.
     * Params:
     *    void
     *
     * Returns:
     *     int
     */
    int Pop() {

        if (Empty())                                    // Checks for empty stack
        {                                               // Cannot pop anything
            //cout << "Error: Stack empty!" << endl;    // Prints error message
            return -1;
        }
        // If stack is not empty
        int data = S[top];                              // Pull item from stack
        top--;                                          // Shrink the stack
        size--;                                         // Update our size
        return data;                                    // Send item back
    }

    /**
     * Empty:
     *    Checks for empty stack
     * Params:
     *    void
     *
     * Returns:
     *     bool : true == stack is empty
     */
    bool Empty() {
        return size == 0;
        //return top == -1;
    }

    /**
     * Full:
     *    Checks to see if stack is full
     * Params:
     *    void
     *
     * Returns:
     *     bool : true == stack is full
     */
    bool Full() {
        return top == capacity - 1;
    }

    /**
     * Print:
     *    Used so we can inspect our stack.
     * Params:
     *    void
     *
     * Returns:
     *     void
     */
    void Print() {
        for (int i = top; i >= 0; i--) {   // Prints last data value to the first
            cout << S[i] << endl;
        }
    }
    /**
     * getInitialSize:
     *    Returns the starting size of array
     * Params:
     *    void
     *
     * Returns:
     *     int  :   size of array
     */
    int getInitialSize()
    {
        return MinSize;     // Return starting size of array
    }
    /**
     * getMaxSize:
     *    Returns the largest size of array
     * Params:
     *    void
     *
     * Returns:
     *     int  :   size of array
     */
    int getMaxSize()
    {
        return MaxSize;     // Return biggest size of array
    }
    /**
     * getMaxSize:
     *    Returns the final size of array
     * Params:
     *    void
     *
     * Returns:
     *     int  :   size of array
     */
    int getLastSize()
    {
        return capacity;     // Return final size of array
    }
    /**
     * Overloaded ostream <<
     *    Lets us print a stack using cout
     * Params:
     *    ostream &os   : instance of ostream passed in by reference
     *    const Stack   : instance of stack passed in using const so
     *                    it cannot be changed
     *
     * Returns:
     *     ostream
     */
    friend ostream& operator<<(ostream& os, const Stack s) {
        for (int i = s.top; i >= 0; i--) {      // Print out values from stack at a certain index
            os << s.S[i] << endl;
        }
        return os;
    }
};

/**
    * Header:
    *    Returns a string containing student name, program #, and date
    * Params:
    *    void
    *
    * Returns:
    *     string : Header for both output file and screen
    */
string Header()     //Returns student information
{
    //Prints out name, program #, and date on separate lines
    return "Name: Allyson Warren \nProgram: PO1 \nDate: 15 Sep 2020\n\n";
}

int main() {

    cout << Header();                       //Prints student information to screen
    Stack S;                                //Create Stack Object
    ifstream infile;                        //Read from input.txt file
    infile.open("input.txt");
    ofstream outfile;                       //Make and open an output file to place data into
    outfile.open("output.txt");
    string MethodType;                      //Type of function to call: Push or Pop
    int data;                               //Value to put into stack
    while (infile >> MethodType)            //Read all data items in file
    {
        if (MethodType == "push")           // Add values from file to stack
        {
            infile >> data;                 // Get value from file
            S.Push(data);                   // Add to stack
        }
        if (MethodType == "pop")            // Remove values from stack
        {
            S.Pop();
        }
    }

    // Prints student information to output file
    outfile << Header();                    
    //Print out first, largest, and final sizes of stack S
    outfile << "Start Size: " << S.getInitialSize() << endl;
    outfile << "Max Size: " << S.getMaxSize() << endl;
    outfile << "Ending Size: " << S.getLastSize();

    infile.close();
    outfile.close();
    return 0;
}
