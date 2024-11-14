#include <iostream>
using namespace std; 
class Queue
{
public:
    int front, rear, size;
    unsigned capacity;
    int *array;
};

Queue *create_queue(unsigned cap)
{
    Queue *queue = new Queue();
    queue->capacity = cap;
    queue->front = queue->size = 0;
    queue->rear = cap - 1;
    queue->array = new int[queue->capacity];
    return queue;
}
bool is_full(Queue *queue)
{
    return (queue->size == queue->capacity);
}
bool isempty(Queue *queue)
{
    bool ans = (queue->size == 0);
    return ans;
}
void enqueue(Queue *queue, int item)
{
    if (is_full(queue))
    {
        cout << "No space in queue!" << endl;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size++;
}
void dequeue(Queue *queue)
{
    if (isempty(queue))
    {
        cout << "Queue is empty!" << endl;
    }
    int n = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
}
void display_backward(Queue *queue)
{
    if (isempty(queue))
    {
        cout << "Nothing in queue!" << endl;
        return;
    }
    int i = queue->rear;
    while (i != queue->front)
    {
        cout << queue->array[i];
        i = (i - 1 + queue->capacity) % queue->capacity;
    }
    cout << queue->array[queue->front];                                
}
void display_forward(Queue *queue)
{
    if (isempty(queue))
    {
        cout << "Nothing in queue!" << endl;
        return;
    }
    int i = queue->front;
    while (i != queue->rear)
    {
        cout << queue->array[i];
        i = (i + 1 + queue->capacity) % queue->capacity;
    }
    cout << queue->array[queue->rear];
}

int main()
{
    Queue *queue = create_queue(7);
    for (int i = 0; i < 4; i++)
    {
        enqueue(queue, i * 10);
    }
    cout << endl;
}
