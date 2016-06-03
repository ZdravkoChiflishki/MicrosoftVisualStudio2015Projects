#include<iostream>
#include<cstdlib>
using namespace std;
struct node {
	int info;
	struct node *next;
};
class Queue {
private:
	node *rear;
	node *front;
public:
	Queue();
	~Queue();
	void enqueue();
	void dequeue();
	void display();
};

Queue::Queue() {
	rear = NULL;
	front = NULL;
}

void Queue::enqueue() {
	int data;
	node *temp = new node;
	cout << "Enter the data to enqueue: ";
	cin >> data;
	temp->info = data;
	temp->next = NULL;
	if (front == NULL) {
		front = temp;
	}
	else {
		rear->next = temp;
	}
	rear = temp;
}
void Queue::dequeue() {
	node *temp = new node;

	if (front == NULL) {
		cout << "\nQueue is Emtpty\n";
	}
	else {
		temp = front;
		front = front->next;
		cout << "The data Dequeued is " << temp->info;
		delete temp;
	}
}
void Queue::display() {
	node *p = new node;
	p = front;
	if (front == NULL) {
		cout << "\nNothing to Display\n";
	}
	else {
		while (p != NULL) {
			cout << endl << p->info;
			p = p->next;
		}
	}
}
Queue::~Queue() {

}
int main() {
	Queue queue;
	int choice;
	while (true) {
		cout << "\n1.Enqueue\n2. Dequeue\n3. Display\n4.Quit";
		cout << "\nEnter your choice: ";
		cin >> choice;
		switch (choice) {
		case 1:
			queue.enqueue();
			break;
		case 2:
			queue.dequeue();
			break;
		case 3:
			queue.display();
			break;
		case 4:
			exit(0);
			break;
		default:
			cout << "\nInvalid Input. Try again! \n";
			break;
		}
	}
	return 0;

}