/*
 * @lc app=leetcode id=622 lang=cpp
 *
 * [622] Design Circular Queue
 */

// @lc code=start

struct Node {
  int val{-1};
  Node* prev{};
  Node* next{};

  Node() = default;

  explicit Node(int aVal, Node* aPrev = nullptr, Node* aNext = nullptr)
      : val(aVal), prev(aPrev), next(aNext) {}
};

class DoubleLinkedList {
 public:
  DoubleLinkedList() {
    head = new Node;
    tail = new Node;
    // nullptr <- head <-> tail -> nullptr
    head->next = tail;
    tail->prev = head;
  }

  ~DoubleLinkedList() {
    while (Node* theNode = removeFront()) {
      delete theNode;
    }
    delete head;
    delete tail;
  }

  int size() {
    return size_;
  }

  bool empty() {
    // ? whether I can use size?
    return size() == 0;
  }

  Node* front() {
    if (empty()) return nullptr;
    return head->next;
  }

  Node* back() {
    if (empty()) return nullptr;
    return tail->prev;
  }

  void addLast(Node* aNode) {
    // 1 <-> tail -> nullptr
    // 1 <-> new <-> tail -> nullptr
    Node* theLast = tail->prev;
    theLast->next = aNode;
    aNode->prev = theLast;
    aNode->next = tail;
    tail->prev = aNode;
    size_++;
  }

  Node* removeFront() {
    if (empty()) return nullptr;
    // nullptr <- head <-> 1 <-> 2
    // nullptr <- head <-> 2
    return remove(head->next);
  }

  Node* remove(Node* aNode) {
    if (!aNode) return aNode;
    // 1 <-> 2 <-> 3
    // connect the previous node and the next node
    Node* thePrev = aNode->prev;
    Node* theNext = aNode->next;
    thePrev->next = theNext;
    theNext->prev = thePrev;
    // disconnet the Node
    aNode->next = nullptr;
    aNode->prev = nullptr;
    // update the size
    size_--;

    return aNode;
  }

 protected:
  Node* head{};
  Node* tail{};
  int size_{0};
};

class MyCircularQueue {
 public:
  explicit MyCircularQueue(int k)
  : capacity(k) {
  }

  bool enQueue(int value) {
    int theSize = list.size();
    if (theSize < capacity) {
      list.addLast(new Node(value));
      return true;
    }
    return false;
  }

  bool deQueue() {
    if (isEmpty()) return false;
    Node* theNode = list.removeFront();
    delete theNode;
    return true;
  }

  int Front() {
    if (isEmpty()) return -1;
    return list.front()->val;
  }

  int Rear() {
    if (isEmpty()) return -1;
    return list.back()->val;
  }

  bool isEmpty() {
    return list.empty();
  }

  bool isFull() {
    return list.size() == capacity;
  }

 protected:
  DoubleLinkedList list;
  int capacity;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
// @lc code=end
