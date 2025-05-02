//Name: Iqra Ashraf
//Roll number: 24K-0952

#include <iostream>
#include <exception>
using namespace std;

class QueueOverflowException : public exception {
};

class QueueUnderflowException : public exception {
};

template <typename T>
class Queue {
private:
    int front;
    int rear;
    int size;
    int capacity;
    T* data;

public:
    Queue(int cap) {
        capacity = cap;
        data = new T[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    ~Queue() {
        delete[] data;
    }

    void enqueue(T value) {
        if (size == capacity)
            throw QueueOverflowException();

        rear = (rear + 1) % capacity;
        data[rear] = value;
        size++;
    }

    T dequeue() {
        if (size == 0)
            throw QueueUnderflowException();

        T value = data[front];
        front = (front + 1) % capacity;
        size--;
        return value;
    }

    bool isEmpty() const {
        return size == 0;
    }

    bool isFull() const {
        return size == capacity;
    }
};

int main() {
    Queue<int> q(3);

    try {
        cout << "Attempting to enqueue to a full queue" << endl;
        q.enqueue(10);
        q.enqueue(20);
        q.enqueue(30);
        q.enqueue(40);
    }
    catch (const QueueOverflowException& ex) {
        cout << "Caught QueueOverflowException\n";
        cout << "what(): " << ex.what() << endl;
    }

    Queue<int> q2(2);
    try {
        cout << "Attempting to dequeue from an empty queue" << endl;
        q2.dequeue();
    }
    catch (const QueueUnderflowException& ex) {
        cout << "Caught QueueUnderflowException" << endl;
        cout << "what(): " << ex.what() << endl;
    }

    return 0;
}