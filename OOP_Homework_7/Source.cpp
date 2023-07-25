#include <iostream>
using namespace std;

#pragma region First
/*struct Node
{
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class Stack
{
public:
    Stack() : top(nullptr) {}
    bool isEmpty()
    {
        return top == nullptr;
    }
    void push(int val)
    {
        Node* newNode = new Node(val);
        newNode->next = top;
        top = newNode;
    }
    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty! Error: ";
            return -1;
        }
        int value = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return value;
    }
    int peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty! Error: ";
            return -1;
        }
        return top->data;
    }
    ~Stack()
    {
        while (!isEmpty())
        {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
private:
    Node* top;
};*/
#pragma endregion

#pragma region Second
template <typename T>
struct Node 
{
    T data;
    Node<T>* prev;
    Node<T>* next;
    Node(const T& val) : data(val), prev(nullptr), next(nullptr) {}
};

template <typename T>
class List
{
public:
    List() : head(nullptr), tail(nullptr), size(0) {}
    bool isEmpty() const 
    {
        return size == 0;
    }
    size_t getSize() const
    {
        return size;
    }
    void push_back(const T& val) 
    {
        Node<T>* newNode = new Node<T>(val);
        if (isEmpty())
            head = tail = newNode;
        else 
        {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }
    void pop_back()
    {
        if (!isEmpty()) 
        {
            Node<T>* temp = tail;
            if (head == tail)
                head = tail = nullptr;
            else 
            {
                tail = tail->prev;
                tail->next = nullptr;
            }
            delete temp;
            size--;
        }
    }
    T front() const 
    {
        if (!isEmpty())
            return head->data;
        else 
        {
            cerr << "List is empty! Error: ";
            return T();
        }
    }
    T back() const
    {
        if (!isEmpty())
            return tail->data;
        else
            cerr << "List is empty! Error: ";
            return T();
    }
    ~List()
    {
        while (!isEmpty()) 
        {
            pop_back();
        }
    }
private:
    Node<T>* head;
    Node<T>* tail;
    size_t size;
};
#pragma endregion


int main() 
{
    // FIRST

    /*Stack stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    cout << "Top of the stack: " << stack.peek() << endl;
    cout << "Deleting elements from the stack: ";
    while (!stack.isEmpty()) 
    {
        cout << stack.pop() << " ";
    }
    cout << endl;*/

    // SECOND

    List<int> list;

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    cout << "First element of the list: " << list.front() << endl;
    cout << "Last element of the list: " << list.back() << endl;
    cout << "Deleting elements from the list: ";
    while (!list.isEmpty())
    {
        cout << list.back() << " ";
        list.pop_back();
    }
    cout << endl;

    system("pause");

    return 0;
}
