#include "Stack.h"
#include "Stack.cpp"
#include "Queue.h"
#include "Queue.cpp"

#include <cstdlib>

void init(Queue<int> &q, Stack<int> &s);
void print(Queue<int> &q, Stack<int> &s);
void feed_students(Queue<int> &q, Stack<int> &s);

int main()
{
    srand(time(0));
    Queue<int> students;
    Stack<int> sandwiches;
    init(students, sandwiches);
    std::cout << "Students came to caffeteria\n";
    print(students, sandwiches);

    feed_students(students, sandwiches);

    print(students, sandwiches);

    return 0;
}

void init(Queue<int> &q, Stack<int> &s)
{
    for (int i = 0; i < 6; i++)
    {
        q.enqueue(rand() % 2);
        s.push(rand() % 2);
    }
}

void print(Queue<int> &q, Stack<int> &s)
{
    std::cout << "Stud: ";
    q.print();
    std::cout << "Sndw: ";
    s.print();
}

void feed_students(Queue<int> &stud, Stack<int> &sndw)
{
    unsigned int n = stud.size();
    int ctr = 0;

    while (!sndw.empty() && ctr < n) {
        if (stud.front() == sndw.top()) {
            stud.dequeue();
            sndw.pop();
            ctr = 0;
        } else {
            int pref = stud.front();
            stud.dequeue();
            stud.enqueue(pref);
            ctr++;
        }
    }

    std::cout << stud.size() << " Students could not be served" << std::endl;
}