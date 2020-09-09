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
*       input.txt       :  text file containing values and whether to push or pop
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
 *
 */
class Stack {
private:
    int* S;       // Array pointer
    int capacity; // Max stack size
    int top;      // Current top (index)
    int size;     // Current num items
    int MinSize;  // Minimum size of stack
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
        capacity = 10;          // Set array size
        S = new int[capacity];  // Allocate new memory
        top = -1;               // Initialize top of stack
        size = 0;               // Set stack to empty
        MinSize = capacity;     // Minimum size of array
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
        capacity = cap;         // Set array size      
        S = new int[capacity];  // Allocate new memory
        top = -1;               // Initialize top of stack
        size = 0;               // Set stack to empty
        MinSize = capacity;     // Minimum size of array
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

        if (Full())                                      // Stack size is full
        {
            int* newStack = new int[capacity * 2];       // New stack with doubled size
            for (int x = 0; x < capacity; x++)
            {
                newStack[x] = S[x];                      // Fill new stack with current values
            }
            delete[] S;                                  // Delete previous stack
            S = newStack;                                // Point to new stack
            capacity *= 2;                               // Double capacity for new stack size
        }
                                                         // Stack has space for data
        top++;                                           // Move top of stack up
        size++;                                          // Increment size
        S[top] = data;                                   // Add item to array

        if((capacity != MinSize) && (size < capacity/2)) // Shrink array if the number of value is less than half the size of the array
        {
            int* newStack = new int[capacity / 2];       // New stack with half previous size
            for (int x = 0; x < capacity/2; x++)
            {
                newStack[x] = S[x];                      // Fill new stack with current values
            }
            delete[] S;                                  // Delete previous stack
            S = newStack;                                // Point to new stack
            capacity /= 2;                               // Current capacity is half the size of before
        }
    }

    /**
     * Pop:
     *    remove item from stack.
     * Params:
     *    void
     *
     * Returns:
     *     int  :   last value in stack
     */
    int Pop() {

        if (Empty())                                    // Checks for empty stack
        {                                               // Cannot pop anything
            cout << "Error: Stack empty!" << endl;      // Prints error message
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

int main() {

    Stack S;                                // Create Stack Object
    ifstream infile;                        // Read from input.txt file
    infile.open("input.txt");
    string MethodType;                      // Type of function to call: push or pop
    int data;                               // Value to put into stack if pushed
    while (infile >> MethodType)            // Read all data items in file
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
    S.Print();                              // Print out stack from last to first placed value
   
    infile.close();                         // Close input file
    return 0;
}
