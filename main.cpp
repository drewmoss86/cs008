#include <iostream>
#include "list.h"
#include "stack.h"
#include "myqueue.h"

using namespace std;

int main()
{
    //Starting test of Stack
    cout << "STARTING TEST OF STACK..." << endl;
    Stack<int> s;

    //Testing push
    cout << "STACK: testing push function" << endl;
    s.push(10);
    cout << s << endl;
    s.push(9);
    cout << s << endl << endl;

    cout << "STACK: testing push w/ loop + top function" << endl;
    for(int i = 0; i < 5; i++)
    {
        s.push(i);
    }

    cout << "S: " << s << endl;
    cout << "top: " << s.top() << endl << endl;

    for(int i = 5; i < 10; i++)
    {
        s.push(i);
    }

    cout << "S: " << s << endl;
    cout << "top: " << s.top() << endl << endl;


    //Testing pop
    cout << "STACK: testing pop" << endl;
    for(int i = 0; i < 5; i++)
    {
        cout << "Spop: " << s.pop() << endl;

    }

    cout << "\nS: " << s << endl;
    cout << "top: " << s.top() << endl << endl;

    //testing Big Three
    for(int i = 1; i < 10; i++)
    {
        s.push(i);
    }

    cout << "S: " << s << endl << endl;

    //testing copy constructor
    cout << "STACK: testing copy constructor" << endl << endl;
    Stack<int> t(s);

    cout << "T: " << t << endl << endl;

    //testing assignment operator
    cout << "STACK: testing assignment operator" << endl << endl;
    Stack<int> u;
    u = t;

    cout << "U: " << u << endl << endl;

    //testing self assignment
    cout << "STACK: testing self assignment" << endl << endl;
    u = u;

    cout << "U: " << u << endl << endl;

    Stack<int> v;

    for(int i = 0; i < 5; i++)
    {
        v.push(i);
    }

    cout << "V: " << v << endl << endl;

    //testing assignment operator with different size, non empty lists
    u = v;

    cout << "V: " << v << endl;
    cout << "U: " << u << endl << endl;

    //TESTING QUEUE
    myQueue<int> myA;

    //Testing push
    cout << "QUEUE: testing push" << endl;
    for(int i = 0; i < 20; i++)
    {
        myA.push(i);
    }

    cout << "myA: " << myA << endl;
    cout << "front: " << myA.front() << endl << endl;

    //Testing pop
    cout << "QUEUE: testing pop" << endl;
    for(int i = 0; i < 5; i++)
    {
        cout << "myA_pop: " << myA.pop() << endl;
    }

    cout << "\nmyA: " << myA << endl;
    cout << "front: " << myA.front() << endl << endl;

    //pop more times than nodes
    for(int i = 0; i < 20; i++)
    {
        cout << "myA_pop: " << myA.pop() << endl;
    }

    cout << "\nmyA: " << myA << endl;
    cout << "front: " << myA.front() << endl << endl;


    //testing Big Three
    for(int i = 10; i < 20; i++)
    {
        myA.push(i);
    }

    cout << "myA: " << myA << endl;
    cout << "front: " << myA.front() << endl << endl;

    //copy constructor
    cout << "QUEUE: testing copy constructor" << endl;
    myQueue<int> myB(myA);

    cout << "myB: " << myB << endl;
    cout << "front: " << myB.front() << endl << endl;

    //assignment operator
    cout << "QUEUE: testing assignment operator" << endl;
    myQueue<int> myC;
    myC = myB;

    cout << "myC: " << myC << endl;
    cout << "front: " << myC.front() << endl << endl;

    //testing self assignment
    cout << "QUEUE: testing self assignment" << endl;
    myC = myC;

    cout << "myC: " << myC << endl << endl;
    cout << "front: " << myC.front() << endl << endl;

    return 0;
}
