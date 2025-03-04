# Stack Implementation Using Linked List

## **Goal**
Design a stack that supports the following operations in **O(1) time** and **O(n) space**:

- `push(x)`: Pushes element `x` onto the stack.
- `pop()`: Removes the top element of the stack.
- `top()`: Returns the top element **without removing** it.
- `getMin()`: Returns the **smallest** element in the stack.
- `getMax()`: Returns the **largest** element in the stack.

## **Overview**
This is a simple menu-driven program that allows you to manipulate stacks. The program begins by creating the head node of a stack using a linked list structure. Users can perform various stack operations such as push, pop, peek, getMin, getMax, and display.

## **Approach**
The stack is implemented using a **linked list**, allowing dynamic memory allocation and efficient element access. By maintaining additional tracking pointers or auxiliary variables, we ensure that `getMin()` and `getMax()` operations can be performed in constant time.

## **Understanding Stacks**
A **stack** is a linear data structure that follows the **LIFO (Last In, First Out)** principle. This means that the last element added to the stack is the first one to be removed. Common stack operations include:

- **Push**: Adding an element to the top of the stack.
- **Pop**: Removing the top element from the stack.
- **Top**: Viewing the top element without removing it.
- **minValue**: Returning the smallest element in the stack.
- **maxValue**: Returning the largest element in the stack.
- **Print**: Showing all elements in the stack.

## **Linked List Implementation of a Stack**
A stack can be implemented using a **linked list**, which consists of nodes where each node stores data and a pointer to the next node. This allows dynamic memory allocation, meaning the stack size can grow or shrink as needed without preallocating memory.

### **Key Components of a Linked List-Based Stack**
1. **Node Structure**: Each node has three parts:
   - Data (value of the node)
   - Pointer (reference to the next node)
   - Additional pointers or auxiliary stacks to track min/max values efficiently.
2. **Head (Top) Pointer**: Keeps track of the topmost node in the stack.
3. **Dynamic Memory Allocation**: New nodes are created and deleted as needed, making it more memory-efficient compared to an array-based stack.

### **Advantages of Using a Linked List for Stacks**
- **Dynamic size adjustment** (no need for a fixed-size array)
- **Efficient memory usage** (no unused slots as in arrays)
- **Fast insertion and deletion** (push and pop operations take O(1) time complexity)
- **Efficient min/max retrieval** with auxiliary data structures

### **Operations in a Linked List-Based Stack**
- **Push Operation**:
  - Create a new node.
  - Point its "next" to the current top.
  - Update the top to this new node.
  - Update min/max tracking variables.
- **Pop Operation**:
  - Check if the stack is empty.
  - Store the top node in a temporary variable.
  - Move the top pointer to the next node.
  - Update min/max tracking variable.
  - Delete the temporary node.
- **Top Operation**:
  - Return the data of the top node.
- **minValue Operation**:
  - Retrieve the minimum element in constant time using an auxiliary variable.
- **maxValue Operation**:
  - Retrieve the maximum element in constant time using an auxiliary variable.

## **Usage Instructions**
1. Run the program.
2. Choose an option from the menu to perform stack operations.
3. Continue until you decide to exit.

## **Conclusion**
This program provides a simple yet effective way to interact with stacks using a linked list, demonstrating dynamic memory allocation and stack operations. The additional tracking mechanism ensures `getMin()` and `getMax()` operations can be performed in **O(1) time**, making this stack implementation highly optimized.

