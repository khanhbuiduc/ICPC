// CPP code to illustrate Queue in
// Standard Template Library (STL)
#include <iostream>
#include <queue>

using namespace std;

// Print the queue
void showq(queue<int> gq)
{
    queue<int> g = gq;

    while (!g.empty())
    {
        cout << '\t' << g.front();
        g.pop();
    }
    cout << '\n';
}
void print_queue(queue<int> q)
{
    queue<int> temp = q;
    while (!temp.empty())
    {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << '\n';
}
// Driver Code
int main()
{
    queue<int> gquiz;
    gquiz.push(10);
    gquiz.push(20);
    gquiz.push(30);

    cout << "The queue gquiz is : ";
    showq(gquiz);

    cout << "\ngquiz.size() : " << gquiz.size();
    cout << "\ngquiz.front() : " << gquiz.front();
    cout << "\ngquiz.back() : " << gquiz.back();

    cout << "\ngquiz.pop() : ";
    gquiz.pop();
    showq(gquiz);
    //=====================================================>
    queue<int> q1;
    q1.push(1);
    q1.push(2);
    q1.push(3);

    cout << "The first queue is : ";
    print_queue(q1);

    queue<int> q2;
    q2.push(4);
    q2.push(5);
    q2.push(6);

    cout << "The second queue is : ";
    print_queue(q2);

    q1.swap(q2);

    cout << "After swapping, the first queue is : ";
    print_queue(q1);
    cout << "After swapping the second queue is : ";
    print_queue(q2);

    cout << q1.empty();
    return 0;
}