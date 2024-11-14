#include <iostream>
#include<stack>
using namespace std;

class queue
{
  stack<int> s1;
  stack<int> s2;

public:
  void enqueue(int x)
  {
    if (!s2.empty())
    {
      while(!s2.empty()){
        s1.push(s2.top());
        s2.pop();
      }
    }

    s1.push(x);
  }

  void dequeue()
  {
    if(s1.empty() && s2.empty()){
      cout<<"queue is empty";
      return;
    }

    if(s2.empty()){
      while(!s1.empty()){
        s2.push(s1.top());
        s1.pop();
      }
    }

    s2.pop();

    return;
  }

  int peek()
  {
    if (s1.empty() && s2.empty())
    {
      cout << "queue is empty";
      return -1;
    }

    if (s2.empty())
    {
      while (!s1.empty())
      {
        s2.push(s1.top());
        s1.pop();
      }
    }

    int topval = s2.top();

    return topval;
  }

  bool empty()
  {
    if (s1.empty() && s2.empty())
    {
      return true;
    }
    return false;
  }
};

int main()
{
  queue q;
  int p, el;
  cin >> p;
  for (int i = 0; i < p; i++)
  {
    cin >> el;
    q.enqueue(el);
  }

  q.dequeue();
  cout << q.peek() << " ";
  q.dequeue();
  cout << q.peek() << " ";
  cout << q.empty();
  return 0;
}