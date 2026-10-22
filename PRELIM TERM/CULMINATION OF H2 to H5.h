#ifndef QUIZ_REVIEW_FULL_H              // header guard: only compile below if this hasn't been defined yet
#define QUIZ_REVIEW_FULL_H              // define it now, so a second #include of this file is skipped

#include <iostream>                     // needed for std::cout, std::endl
#include <string>                       // needed for std::string, used in Topic 1's demo class

// ================================================================
// TOPIC 1: MEMORY ALLOCATION BASICS
// ================================================================
namespace MemoryBasics {                // groups these names so they don't collide with other topics

    class DemoItem {                    // a small class used only to demonstrate the Big Four
    private:                            // members below are only accessible from inside this class
        std::string itemName;           // holds the name of this item
        int itemValue;                  // holds the numeric value of this item

    public:                             // members below are accessible from outside the class

        // CONSTRUCTOR -- runs automatically whenever a DemoItem object is created
        DemoItem(std::string name = "Unnamed", int value = 0) {   // default values let this be called with no arguments
            itemName = std::move(name);                            // std::move avoids copying the string unnecessarily
            itemValue = value;                                     // store the given value
            std::cout << "[Constructor] " << itemName << " created." << std::endl;   // confirm creation on screen
        }                                                           // closes the constructor

        // DESTRUCTOR -- runs automatically when this object is destroyed
        ~DemoItem() {                                               // takes no arguments, returns nothing
            std::cout << "[Destructor] " << itemName << " destroyed." << std::endl;  // confirm destruction on screen
        }                                                           // closes the destructor

        // COPY CONSTRUCTOR -- runs when a NEW object is built directly from an existing one
        DemoItem(const DemoItem &other) {                          // takes a const reference to avoid copying the source
            itemName = other.itemName;                             // copy the name from the source object
            itemValue = other.itemValue;                           // copy the value from the source object
            std::cout << "[Copy Constructor] " << itemName << " copied." << std::endl;  // confirm the copy on screen
        }                                                           // closes the copy constructor

        // COPY ASSIGNMENT OPERATOR -- runs when an ALREADY EXISTING object is reassigned
        DemoItem& operator=(const DemoItem &other) {                // returns a reference so a = b = c chains work
            std::cout << "[Copy Assignment] " << other.itemName << " assigned." << std::endl;  // confirm on screen
            if (this != &other) {                                   // guard: skip copying if assigning an object to itself
                itemName = other.itemName;                          // copy the name field
                itemValue = other.itemValue;                        // copy the value field
            }                                                       // closes the self-assignment guard
            return *this;                                           // return the current object by reference
        }                                                           // closes the copy assignment operator

        void display() const {                                     // const because this doesn't modify the object
            std::cout << itemName << " = " << itemValue << std::endl;   // print the name and value
        }                                                           // closes display
    };                                                              // closes the DemoItem class

    // demoStaticVsDynamic -- shows the difference between stack (static)
    // and heap (dynamic) allocation using the same class
    void demoStaticVsDynamic() {
        std::cout << "\n-- Static (stack) allocation --" << std::endl;   // section label
        DemoItem stackItem("StackItem", 10);                        // created directly, no 'new' -- lives on the stack
        stackItem.display();                                        // print its contents
        // no delete needed here -- the destructor fires automatically when stackItem goes out of scope

        std::cout << "\n-- Dynamic (heap) allocation --" << std::endl;   // section label
        DemoItem* heapItem = new DemoItem("HeapItem", 20);          // 'new' allocates on the heap, returns a pointer
        heapItem->display();                                        // print its contents through the pointer
        delete heapItem;                                            // manually free the heap memory, or it leaks
        std::cout << "-- heapItem was manually deleted --" << std::endl;  // confirm cleanup on screen
    }                                                                // closes demoStaticVsDynamic
}                                                                    // closes namespace MemoryBasics


// ================================================================
// TOPIC 2: SINGLY LINKED LIST -- one direction only (next)
// ================================================================
namespace SinglyLL {                    // groups these names so they don't collide with other topics

    template <typename T>               // makes SNode work with any data type
    class SNode {                       // one link in the chain
    public:
        T data;                         // the value stored in this node
        SNode<T>* next = nullptr;       // address of the next node, defaults to null
    };                                   // closes the SNode class

    // createNode -- allocates one node on the heap and fills it in
    template <typename T>
    SNode<T>* createNode(T value) {
        SNode<T>* node = new SNode<T>;  // allocate a new node on the heap
        node->data = value;             // store the given value inside it
        node->next = nullptr;           // it has no neighbor yet
        return node;                    // hand back the address of the new node
    }                                    // closes createNode

    // traverse -- prints every value from head to the end
    template <typename T>
    void traverse(SNode<T>* head) {
        while (head != nullptr) {       // keep going until we fall off the end
            std::cout << head->data << " ";   // print the current node's value
            head = head->next;          // step forward to the next node
        }                                // closes the while loop
        std::cout << std::endl;         // move to a new line after printing everything
    }                                    // closes traverse

    // insertHead -- needs a DOUBLE pointer, since it must change the
    // CALLER's own head variable, not just a local copy of it
    template <typename T>
    void insertHead(T value, SNode<T>** head) {
        SNode<T>* node = createNode(value);  // build the new node
        node->next = *head;                   // point it at whatever the current head is
        *head = node;                         // make the new node the actual head
    }                                          // closes insertHead

    // insertAfter -- general insertion; only needs a single pointer,
    // since it never has to change the head
    template <typename T>
    void insertAfter(T value, SNode<T>* prevNode) {
        if (prevNode == nullptr) {                     // can't insert after a node that doesn't exist
            std::cout << "Cannot insert after a null node." << std::endl;  // report the problem
            return;                                      // stop, nothing to do
        }                                                 // closes the null check
        SNode<T>* node = createNode(value);              // build the new node
        node->next = prevNode->next;                      // new node points to whatever prevNode used to point to
        prevNode->next = node;                             // prevNode now points to the new node
    }                                                       // closes insertAfter

    // insertEnd -- walks to the last node (next == nullptr), then attaches
    template <typename T>
    void insertEnd(T value, SNode<T>** head) {
        SNode<T>* node = createNode(value);   // build the new node
        if (*head == nullptr) {                // if the list is currently empty
            *head = node;                       // the new node simply becomes the head
            return;                             // done, nothing else to link
        }                                       // closes the empty-list check
        SNode<T>* current = *head;             // start walking from the head
        while (current->next != nullptr) {      // keep going until we reach the last node
            current = current->next;             // step forward
        }                                        // closes the walking loop
        current->next = node;                    // attach the new node after the last one
    }                                             // closes insertEnd

    // deleteValue -- searches for a value while tracking the previous
    // node, then relinks around whichever node matches
    template <typename T>
    void deleteValue(T value, SNode<T>** head) {
        if (*head == nullptr) return;             // nothing to delete from an empty list
        SNode<T>* current = *head;                // start searching from the head
        SNode<T>* prev = nullptr;                 // no previous node yet
        while (current != nullptr && current->data != value) {  // search until found or list ends
            prev = current;                        // remember this node as "previous" before moving on
            current = current->next;               // step forward
        }                                           // closes the search loop
        if (current == nullptr) return;            // value was never found, nothing to delete
        if (prev == nullptr) {                      // if the match was the head node itself
            *head = current->next;                   // move the head forward past it
        } else {                                     // otherwise the match is somewhere in the middle/end
            prev->next = current->next;               // skip over the matched node
        }                                             // closes the if/else
        delete current;                              // free the memory of the removed node
    }                                                  // closes deleteValue

    // deleteList -- frees every node in the list, one at a time
    template <typename T>
    void deleteList(SNode<T>** head) {
        while (*head != nullptr) {                 // keep going as long as nodes remain
            SNode<T>* temp = *head;                 // remember the current head before it's gone
            *head = (*head)->next;                  // move the head forward first
            delete temp;                            // now it's safe to free the old head
        }                                            // closes the while loop
    }                                                 // closes deleteList
}                                                     // closes namespace SinglyLL


// ================================================================
// TOPIC 3: DOUBLY LINKED LIST -- both directions (next AND prev)
// ================================================================
namespace DoublyLL {                    // groups these names so they don't collide with other topics

    template <typename T>
    class DNode {                       // one link in the chain, now with two neighbors
    public:
        T data;                         // the value stored in this node
        DNode<T>* next = nullptr;       // address of the node ahead, defaults to null
        DNode<T>* prev = nullptr;       // address of the node behind, defaults to null
    };                                   // closes the DNode class

    // createNode -- allocates one node and initializes both pointers to null
    template <typename T>
    DNode<T>* createNode(T value) {
        DNode<T>* node = new DNode<T>;  // allocate on the heap
        node->data = value;             // store the given value
        node->next = nullptr;           // no forward neighbor yet
        node->prev = nullptr;           // no backward neighbor yet
        return node;                    // hand back the address
    }                                    // closes createNode

    // traverse -- prints forward, then backward; the reverse pass
    // is only possible because prev exists
    template <typename T>
    void traverse(DNode<T>* head) {
        DNode<T>* tail = nullptr;                 // will end up pointing at the last node reached
        std::cout << "Forward: ";                 // label for the forward pass
        DNode<T>* current = head;                 // start at the head
        while (current != nullptr) {               // walk forward until the end
            std::cout << current->data << " ";      // print the current value
            tail = current;                         // remember this as the furthest node reached so far
            current = current->next;                // step forward
        }                                            // closes the forward loop
        std::cout << std::endl;                     // newline after the forward pass

        std::cout << "Reverse: ";                   // label for the reverse pass
        while (tail != nullptr) {                    // walk backward from wherever the forward pass ended
            std::cout << tail->data << " ";           // print the current value
            tail = tail->prev;                        // step backward
        }                                             // closes the reverse loop
        std::cout << std::endl;                      // newline after the reverse pass
    }                                                  // closes traverse

    // insertHead -- must also fix the OLD head's prev pointer,
    // since it's no longer the first node
    template <typename T>
    void insertHead(T value, DNode<T>** head) {
        DNode<T>* node = createNode(value);       // build the new node
        node->next = *head;                        // point it forward at the current head
        if (*head != nullptr) {                     // only touch the old head if one actually exists
            (*head)->prev = node;                    // relink the old head backward to the new node
        }                                            // closes the null check
        *head = node;                               // the new node is now the official head
    }                                                 // closes insertHead

    // insertEnd -- walks to the last node, then links both directions
    template <typename T>
    void insertEnd(T value, DNode<T>** head) {
        DNode<T>* node = createNode(value);       // build the new node
        if (*head == nullptr) {                     // if the list is currently empty
            *head = node;                            // the new node becomes the head
            return;                                  // nothing else to link
        }                                            // closes the empty-list check
        DNode<T>* current = *head;                  // start walking from the head
        while (current->next != nullptr) {           // walk until the last node (next == null)
            current = current->next;                  // step forward
        }                                             // closes the walking loop
        current->next = node;                         // old last node now points forward to the new node
        node->prev = current;                         // new node points backward to the old last node
    }                                                  // closes insertEnd

    // insertAfter -- general insertion; fixes the new node's own
    // links AND the neighbor's back-link
    template <typename T>
    void insertAfter(T value, DNode<T>* prevNode) {
        if (prevNode == nullptr) return;             // can't insert after a node that doesn't exist
        DNode<T>* node = createNode(value);          // build the new node
        node->next = prevNode->next;                  // new node points forward to whatever prevNode pointed to
        node->prev = prevNode;                         // new node points backward to prevNode
        if (prevNode->next != nullptr) {                // if there was already a node after prevNode
            prevNode->next->prev = node;                  // that node's prev now points back to the new node
        }                                                // closes the check
        prevNode->next = node;                           // prevNode now points forward to the new node
    }                                                     // closes insertAfter

    // deleteValue -- each node already knows both of its own
    // neighbors, so no separate "prev tracker" variable is needed
    template <typename T>
    void deleteValue(T value, DNode<T>** head) {
        if (*head == nullptr) return;                 // nothing to delete from an empty list
        DNode<T>* current = *head;                    // start searching from the head
        while (current != nullptr && current->data != value) {  // search until found or list ends
            current = current->next;                    // step forward
        }                                                // closes the search loop
        if (current == nullptr) return;                // value was never found
        if (current->prev != nullptr) {                  // if there's a node before the match
            current->prev->next = current->next;           // skip the match from the "before" side
        } else {                                          // otherwise the match is the head
            *head = current->next;                          // move the head forward past it
        }                                                  // closes the if/else
        if (current->next != nullptr) {                   // if there's a node after the match
            current->next->prev = current->prev;             // skip the match from the "after" side
        }                                                   // closes the check
        delete current;                                    // free the memory of the removed node
    }                                                        // closes deleteValue

    // deleteList -- frees every node, one at a time
    template <typename T>
    void deleteList(DNode<T>** head) {
        while (*head != nullptr) {                 // keep going as long as nodes remain
            DNode<T>* temp = *head;                 // remember the current head before it's gone
            *head = (*head)->next;                  // move the head forward first
            delete temp;                            // now safe to free the old head
        }                                            // closes the while loop
    }                                                 // closes deleteList
}                                                     // closes namespace DoublyLL


// ================================================================
// TOPIC 4: CIRCULAR DOUBLY LINKED LIST -- loops back, no nullptr end
// ================================================================
namespace CircularDLL {                 // groups these names so they don't collide with other topics

    template <typename T>
    class CNode {                       // one link in a circular chain
    public:
        T data;                         // the value stored in this node
        CNode<T>* next = nullptr;       // forward neighbor
        CNode<T>* prev = nullptr;       // backward neighbor
    };                                   // closes the CNode class

    // createNode -- a fresh node points to ITSELF for both next and
    // prev, since even a one-node list is still technically circular
    template <typename T>
    CNode<T>* createNode(T value) {
        CNode<T>* node = new CNode<T>;  // allocate on the heap
        node->data = value;             // store the given value
        node->next = node;              // points to itself for now
        node->prev = node;              // points to itself for now
        return node;                    // hand back the address
    }                                    // closes createNode

    // insertHead -- the tail is always head->prev in a circular list,
    // so no traversal is ever needed to find it
    template <typename T>
    void insertHead(T value, CNode<T>** head) {
        CNode<T>* node = createNode(value);   // build the new node
        if (*head == nullptr) {                // if the list is currently empty
            *head = node;                       // the new node becomes the whole circle by itself
            return;                             // nothing else to link
        }                                       // closes the empty-list check
        CNode<T>* tail = (*head)->prev;        // grab the current tail via the circular shortcut
        node->next = *head;                     // new node points forward to the current head
        node->prev = tail;                      // new node points backward to the tail
        tail->next = node;                      // tail now points forward to the new node
        (*head)->prev = node;                   // old head now points backward to the new node
        *head = node;                            // the new node is now the official head
    }                                            // closes insertHead

    // insertEnd -- same shortcut: attach right before the head,
    // since that position IS the end of the circle
    template <typename T>
    void insertEnd(T value, CNode<T>** head) {
        CNode<T>* node = createNode(value);   // build the new node
        if (*head == nullptr) {                // if the list is currently empty
            *head = node;                       // the new node becomes the whole circle by itself
            return;                             // nothing else to link
        }                                       // closes the empty-list check
        CNode<T>* tail = (*head)->prev;        // grab the current tail via the circular shortcut
        tail->next = node;                      // old tail now points forward to the new node
        node->prev = tail;                      // new node points backward to the old tail
        node->next = *head;                     // new node points forward back to the head, closing the loop
        (*head)->prev = node;                   // head now points backward to the new node
    }                                            // closes insertEnd

    // traverse -- do-while is required here: a circular list never
    // naturally reaches nullptr, so the loop instead stops once it
    // arrives back at the node it started from
    template <typename T>
    void traverse(CNode<T>* head) {
        if (head == nullptr) {                  // nothing to print if the list is empty
            std::cout << "(empty)" << std::endl;  // say so
            return;                              // stop here
        }                                        // closes the empty check
        CNode<T>* current = head;               // start at the head
        do {                                     // do-while guarantees this runs at least once
            std::cout << current->data << " ";    // print the current value
            current = current->next;              // step forward
        } while (current != head);               // stop once we're back where we started
        std::cout << std::endl;                  // newline after printing everything
    }                                             // closes traverse

    // find -- same do-while pattern, but searching for a specific value
    template <typename T>
    CNode<T>* find(T value, CNode<T>* head) {
        if (head == nullptr) return nullptr;    // nothing to find in an empty list
        CNode<T>* current = head;               // start at the head
        do {                                     // guarantee at least one check
            if (current->data == value) return current;  // found it, hand back this node's address
            current = current->next;              // otherwise step forward
        } while (current != head);               // stop once we're back where we started
        return nullptr;                          // walked the whole circle, never found it
    }                                             // closes find

    // deleteValue -- has a special case for a list with exactly one
    // node, since that node's next/prev both point to itself
    template <typename T>
    void deleteValue(T value, CNode<T>** head) {
        if (*head == nullptr) return;             // nothing to delete from an empty list
        CNode<T>* current = *head;                // start searching from the head

        if (current->next == current) {            // true only when there's exactly one node total
            if (current->data == value) {            // if that lone node is the one we want
                delete current;                        // free it
                *head = nullptr;                       // the list is now completely empty
            }                                          // closes the value check
            return;                                   // either way, nothing more to do
        }                                             // closes the one-node special case

        do {                                          // normal case: search the circle
            if (current->data == value) {               // found the node to remove
                current->prev->next = current->next;      // skip it from the "before" side
                current->next->prev = current->prev;      // skip it from the "after" side
                if (current == *head) {                   // if we just removed the head itself
                    *head = current->next;                   // move the head forward to the next node
                }                                          // closes the head check
                delete current;                            // free the removed node's memory
                return;                                    // done
            }                                            // closes the value check
            current = current->next;                     // otherwise keep searching, step forward
        } while (current != *head);                     // stop once we're back where we started
    }                                                     // closes deleteValue

    // deleteAll -- must BREAK the circle first (cut the last node's
    // next to nullptr), turning it into a straight line, otherwise a
    // normal delete loop would never stop
    template <typename T>
    void deleteAll(CNode<T>** head) {
        if (*head == nullptr) return;              // nothing to delete from an empty list
        CNode<T>* tail = (*head)->prev;            // grab the tail via the circular shortcut
        tail->next = nullptr;                       // cut the loop open here
        CNode<T>* current = *head;                 // now walk it like a normal straight list
        while (current != nullptr) {                 // keep going until we reach the (new) end
            CNode<T>* temp = current;                 // remember the current node before it's gone
            current = current->next;                  // step forward first
            delete temp;                              // now safe to free the old node
        }                                              // closes the while loop
        *head = nullptr;                              // the list is now completely empty
    }                                                   // closes deleteAll
}                                                       // closes namespace CircularDLL


// ================================================================
// TOPIC 5: STACKS -- Last In, First Out (LIFO)
// ================================================================

// -- A. Array-based: fixed size, an index tracks the top --
namespace StackArr {
    const size_t maxCap = 100;          // maximum number of elements this stack can ever hold
    int stack[maxCap];                  // the actual backing storage: a plain fixed-size array
    int top = -1;                       // index of the current top; -1 means the stack is empty

    bool isEmpty() {                    // true when nothing has been pushed yet
        return top == -1;                // top sitting at its starting value means no elements
    }                                    // closes isEmpty

    bool isFull() {                     // true when every slot is occupied
        return top == maxCap - 1;        // top sitting at the last valid index means it's full
    }                                    // closes isFull

    void push(int value) {              // adds a new value to the top
        if (isFull()) {                   // check for overflow before writing
            std::cout << "Stack Overflow!" << std::endl;   // report the problem
            return;                        // stop, nothing is pushed
        }                                  // closes the overflow check
        stack[++top] = value;             // move top forward first, then store the value there
    }                                      // closes push

    int pop() {                         // removes and returns the top value
        if (isEmpty()) {                  // check for underflow before reading
            std::cout << "Stack Underflow!" << std::endl;  // report the problem
            return -1;                     // sentinel value, since there's nothing real to return
        }                                  // closes the underflow check
        return stack[top--];              // read the value at top, then move top back afterward
    }                                      // closes pop
}                                          // closes namespace StackArr

// -- B. Linked-list-based: push = insert at head, pop = remove head --
namespace StackLL {
    template <typename T>
    class Node {                        // one link in the stack's chain
    public:
        T data;                          // the value stored in this node
        Node* next = nullptr;            // the node underneath this one, defaults to null
    };                                    // closes the Node class

    template <typename T>
    Node<T>* head = nullptr;             // pointer to whichever node is currently on top

    template <typename T>
    void push(T value) {                 // adds a new value to the top
        Node<T>* node = new Node<T>;      // allocate a new node
        node->data = value;               // store the given value
        node->next = head<T>;             // point it at whatever was previously on top
        head<T> = node;                    // it is now officially the top
    }                                      // closes push

    template <typename T>
    T pop() {                            // removes and returns the top value
        if (head<T> == nullptr) {          // check for underflow before removing
            std::cout << "Stack Underflow!" << std::endl;   // report the problem
            return T();                     // default-constructed sentinel value
        }                                   // closes the underflow check
        Node<T>* temp = head<T>;           // remember the current top node
        T val = temp->data;                // copy its value out before it's destroyed
        head<T> = head<T>->next;           // move the top pointer down to the next node
        delete temp;                       // free the memory of the removed node
        return val;                        // hand back the removed value
    }                                       // closes pop

    template <typename T>
    bool isEmpty() {                     // true when there is no top node at all
        return head<T> == nullptr;         // no node to point to means the stack is empty
    }                                       // closes isEmpty
}                                           // closes namespace StackLL

// -- C. STL: no custom code needed, std::stack from <stack> already
// does all of this; it is used directly wherever it's needed --


// ================================================================
// TOPIC 6: QUEUES -- First In, First Out (FIFO)
// ================================================================

// -- A. Array-based (circular queue / ring buffer) --
namespace QueueArr {
    template <typename T>
    class Queue {
    private:
        T* q_array;                       // pointer to the dynamically-allocated backing array
        int q_capacity;                   // maximum number of elements the array can hold
        int q_size;                       // current number of elements stored
        int q_front;                      // index of the front (next to be removed)
        int q_back;                       // index of the back (most recently added)

    public:
        Queue(int capacity = 10) {        // constructor -- builds an empty queue
            q_capacity = capacity;          // remember the requested capacity
            q_array = new T[q_capacity];    // allocate the backing array on the heap
            q_size = 0;                     // starts with zero elements
            q_front = 0;                    // front starts at index 0
            q_back = -1;                    // back starts before index 0, so the first Enqueue lands on 0
        }                                    // closes the constructor

        ~Queue() {                          // destructor -- frees the backing array
            delete[] q_array;                 // deallocate the whole array at once
        }                                    // closes the destructor

        Queue(const Queue& other) {         // copy constructor -- deep copy, since elements may wrap
            q_capacity = other.q_capacity;    // copy the capacity
            q_size = other.q_size;            // copy the current size
            q_front = other.q_front;          // copy the front index
            q_back = other.q_back;            // copy the back index
            q_array = new T[q_capacity];      // allocate a fresh array of the same size
            for (int i = 0; i < q_capacity; i++) {   // copy every slot, not just the "logical" elements
                q_array[i] = other.q_array[i];         // duplicate this slot's value
            }                                          // closes the copy loop
        }                                    // closes the copy constructor

        Queue& operator=(const Queue& other) {  // copy assignment operator
            if (this != &other) {                 // skip everything if assigning a queue to itself
                delete[] q_array;                    // free this queue's current array first
                q_capacity = other.q_capacity;       // copy the capacity
                q_size = other.q_size;               // copy the current size
                q_front = other.q_front;             // copy the front index
                q_back = other.q_back;               // copy the back index
                q_array = new T[q_capacity];         // allocate a fresh array
                for (int i = 0; i < q_capacity; i++) {  // copy every slot
                    q_array[i] = other.q_array[i];        // duplicate this slot's value
                }                                        // closes the copy loop
            }                                       // closes the self-assignment guard
            return *this;                          // return this object by reference
        }                                        // closes the copy assignment operator

        bool Empty() const {                 // true when nothing is currently stored
            return q_size == 0;                 // zero size means empty
        }                                      // closes Empty

        int Size() const {                   // current element count
            return q_size;                      // just return the tracked count
        }                                      // closes Size

        void Clear() {                       // resets bookkeeping WITHOUT touching the array or capacity
            q_size = 0;                          // no elements remain
            q_front = 0;                         // reset front to its starting index
            q_back = -1;                         // reset back to its starting index
        }                                       // closes Clear

        T Front() const {                    // the element that would be removed next
            if (Empty()) {                       // guard against reading an empty queue
                std::cout << "Queue is empty!\n";   // report the problem
                return T();                          // default value, nothing real to return
            }                                     // closes the empty check
            return q_array[q_front];             // read the value sitting at the front index
        }                                       // closes Front

        T Back() const {                     // the most recently added element
            if (Empty()) {                       // guard against reading an empty queue
                std::cout << "Queue is empty!\n";   // report the problem
                return T();                          // default value, nothing real to return
            }                                     // closes the empty check
            return q_array[q_back];              // read the value sitting at the back index
        }                                       // closes Back

        void Enqueue(T value) {              // inserts a new element at the back
            if (q_size == q_capacity) {           // guard against writing past capacity
                std::cout << "Queue Overflow!\n";    // report the problem
                return;                              // stop, nothing is enqueued
            }                                     // closes the overflow check
            q_back++;                            // move the back index forward
            if (q_back == q_capacity) {           // if it just ran past the end of the array
                q_back = 0;                          // wrap it back around to the start
            }                                     // closes the wraparound check
            q_array[q_back] = value;             // store the new value at the (possibly wrapped) back index
            q_size++;                            // one more element is now present
        }                                       // closes Enqueue

        T Dequeue() {                        // removes and returns the element at the front
            if (Empty()) {                       // guard against removing from an empty queue
                std::cout << "Queue Underflow!\n";   // report the problem
                return T();                          // default value, nothing real to return
            }                                     // closes the underflow check
            T removed = q_array[q_front];        // save the front value before its slot gets reused
            q_front++;                           // move the front index forward
            if (q_front == q_capacity) {          // if it just ran past the end of the array
                q_front = 0;                         // wrap it back around to the start
            }                                     // closes the wraparound check
            q_size--;                            // one fewer element is now present
            return removed;                      // hand back the value that was removed
        }                                       // closes Dequeue
    };                                        // closes the Queue class
}                                             // closes namespace QueueArr

// -- B. Linked-list-based: enqueue at the rear, dequeue from the front --
namespace QueueLL {
    template <typename T>
    class QNode {                        // one link in the queue's chain
    public:
        T data;                            // the value stored in this node
        QNode<T>* next = nullptr;          // the node behind this one in line, defaults to null
    };                                     // closes the QNode class

    template <typename T>
    class Queue {
    private:
        QNode<T>* q_front;                 // the node that will be removed next
        QNode<T>* q_rear;                  // the most recently added node
        int q_size;                        // current number of elements stored

    public:
        Queue() {                          // constructor -- builds an empty queue
            q_front = nullptr;               // no nodes yet
            q_rear = nullptr;                // no nodes yet
            q_size = 0;                      // zero elements
        }                                   // closes the constructor

        ~Queue() {                         // destructor -- frees every remaining node
            Clear();                         // reuse Clear() to do the actual freeing
        }                                   // closes the destructor

        Queue(const Queue& other) {        // copy constructor -- rebuilds the chain in the same order
            q_front = nullptr;               // start this queue empty
            q_rear = nullptr;                // start this queue empty
            q_size = 0;                      // start this queue empty
            QNode<T>* current = other.q_front;  // walk the SOURCE queue from its own front
            while (current != nullptr) {      // for every node in the source
                Enqueue(current->data);         // copy its value into this queue, preserving order
                current = current->next;        // step to the next source node
            }                                  // closes the copying loop
        }                                   // closes the copy constructor

        Queue& operator=(const Queue& other) {  // copy assignment operator
            if (this != &other) {                 // skip everything if assigning a queue to itself
                Clear();                            // empty out whatever this queue currently holds
                QNode<T>* current = other.q_front;  // walk the source queue from its own front
                while (current != nullptr) {         // for every node in the source
                    Enqueue(current->data);            // copy its value into this queue, preserving order
                    current = current->next;           // step to the next source node
                }                                     // closes the copying loop
            }                                      // closes the self-assignment guard
            return *this;                          // return this object by reference
        }                                        // closes the copy assignment operator

        bool Empty() const {                 // true when no jobs/elements are pending
            return q_size == 0;                 // zero size means empty
        }                                      // closes Empty

        int Size() const {                   // current element count
            return q_size;                      // just return the tracked count
        }                                      // closes Size

        void Clear() {                       // removes and frees every node
            while (q_front != nullptr) {          // keep going as long as nodes remain
                QNode<T>* temp = q_front;            // remember the current front before it's gone
                q_front = q_front->next;             // move the front pointer forward first
                delete temp;                         // now safe to free the old front node
            }                                      // closes the while loop
            q_rear = nullptr;                     // no nodes left, so rear must also be reset
            q_size = 0;                           // zero elements remain
        }                                       // closes Clear

        T Front() const {                    // the element that will be removed next
            if (Empty()) {                       // guard against reading an empty queue
                std::cout << "Queue is empty!\n";   // report the problem
                return T();                          // default value, nothing real to return
            }                                     // closes the empty check
            return q_front->data;                // read the value stored in the front node
        }                                       // closes Front

        T Back() const {                     // the most recently added element
            if (Empty()) {                       // guard against reading an empty queue
                std::cout << "Queue is empty!\n";   // report the problem
                return T();                          // default value, nothing real to return
            }                                     // closes the empty check
            return q_rear->data;                 // read the value stored in the rear node
        }                                       // closes Back

        void Enqueue(T value) {              // adds a new element to the back of the line
            QNode<T>* node = new QNode<T>;        // allocate a brand-new node
            node->data = value;                   // store the given value inside it
            node->next = nullptr;                 // it will be the new last node, so next is null
            if (q_rear == nullptr) {               // special case: the queue was completely empty
                q_front = node;                       // the new node is both the front...
                q_rear = node;                        // ...and the rear, since it's the only node
            } else {                               // otherwise there's already at least one node
                q_rear->next = node;                  // the old rear now points forward to the new node
                q_rear = node;                        // the new node is now the official rear
            }                                      // closes the if/else
            q_size++;                             // one more element is now present
        }                                       // closes Enqueue

        T Dequeue() {                        // removes and returns the element at the front
            if (Empty()) {                       // guard against removing from an empty queue
                std::cout << "Queue Underflow!\n";   // report the problem
                return T();                          // default value, nothing real to return
            }                                     // closes the underflow check
            QNode<T>* temp = q_front;            // remember the current front node
            T removed = temp->data;              // copy its value out before it's destroyed
            q_front = q_front->next;             // move the front pointer forward
            if (q_front == nullptr) {             // if that was the very last node
                q_rear = nullptr;                    // the queue is now empty, so reset rear too
            }                                     // closes the now-empty check
            delete temp;                         // free the memory of the removed node
            q_size--;                            // one fewer element is now present
            return removed;                      // hand back the value that was removed
        }                                       // closes Dequeue
    };                                        // closes the Queue class
}                                             // closes namespace QueueLL

#endif                                        // closes the header guard opened at the top of this file