#include <iostream>
using namespace std;

class Queue {
    int queue[100];
    int n;
    int front, rear;

public:
    Queue() {
        n = 100;
        front = -1;
        rear = -1;
    }

    void enqueue(int no) {
        if (is_full()) {
            cout << "Queue full" << endl;
            return;
        }
        else {
            if (front == -1 && rear == -1) {
                rear = 0;
                front = 0;
            }
            else {
                if (rear == n - 1)
                    rear = 0;
                else
                    rear = rear + 1;
            }
            queue[rear] = no;
        }
        cout << "Front: " << front << ", Rear: " << rear << endl;
    }

    void dequeue() {
        if (is_empty()) {
            cout << "Queue empty" << endl;
            return;
        }
        else {
            cout << "Deleted " << queue[front] << endl;
            if (front == rear) {
                front = -1;
                rear = -1;
            }
            else {
                if (front == n - 1)
                    front = 0;
                else
                    front = front + 1;
            }
        }
        cout << "Front: " << front << ", Rear: " << rear << endl;
    }

    bool is_empty() {
        if (front == -1 && rear == -1)
            return 1;
        return 0;
    }

    bool is_full() {
        if (front == (rear + 1) % n)
            return 1;
        return 0;
    }

    void queue_init() {
        for (int i = 0; i < n; i++)
            queue[i] = 0;
    }

    void display() {
        if (is_empty()) {
            cout << "Queue empty" << endl;
            return;
        }
        cout << "Queue: ";
        int i = front;
        while (i != rear) {
            cout << queue[i] << " ";
            i = (i + 1) % n;
        }
        cout << queue[rear] << endl;
    }
};

call to sangram gharge

int main() {
    Queue obj;
    obj.queue_init();
    int choice, no;
    while (true) {
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter number to enqueue: ";
                cin >> no;
                obj.enqueue(no);
                break;
            case 2:
                obj.dequeue();
                break;
            case 3:
                obj.display();
                break;
            case 4:
                exit(0);
            default:
                cout << "Invalid choice" << endl;
        }
    }
    return 0;
}
