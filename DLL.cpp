#include <iostream>
using namespace std;
struct Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data)
    {
        this->data = data;
        next = nullptr;
        prev = nullptr;
    }
};

class DLL
{
public:
    Node *head, *tail;

    DLL()
    {
        head = tail = nullptr;
    }

    void insertAtStart(int data)
    {
        Node *newnode;
        if (head == nullptr)
        {
            head = tail = new Node(data);
        }

        else
        {
            newnode = new Node(data);
            tail->prev = newnode;
            newnode->next = head;
            head->prev = nullptr;
            head = newnode;
        }
    }

    void deleteFromStart()
    {
        if (head == nullptr)
            return;

        Node *temp = head;
        head = head->next;
        if (head != nullptr)
            head->prev = nullptr;
        free(temp);
    }

    void printData()
    {
        Node *temp = head;
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != nullptr);

        cout << endl;
    }
};

int main()
{
    DLL d1;
    d1.insertAtStart(7);
    d1.insertAtStart(8);
    d1.insertAtStart(9);
    d1.insertAtStart(10);
    d1.printData();

    d1.deleteFromStart();
    d1.printData();
}