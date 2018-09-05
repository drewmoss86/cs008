#include <iostream>
#include "list.h"
#include "stack.h"
#include "myqueue.h"

void test_insert_after(node<int>* head, node<int>* tail, int item);


using namespace std;

int main()
{
    Stack<int> s;

    //Testing push
    cout << "STACK: single push" << endl << endl;
    s.push(10);
    cout << s << endl;
    s.push(9);
    cout << s << endl;

    cout << "STACK: testing push w/ loop" << endl << endl;
    for(int i = 0; i < 5; i++)
    {
        s.push(i);
    }

    cout << "S: " << s << endl << endl;

    //testing top function
    cout << "top: " << s.top() << endl << endl;

    //Testing pop
    cout << "STACK: testing pop" << endl << endl;
    for(int i = 0; i < 5; i++)
    {
        cout << "Spop: " << s.pop() << endl;

    }
    cout << endl;

    //Recreating s for testing Big Three
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

    //TESTING QUEUE
    myQueue<int> myA;

    //Testing push
    cout << "QUEUE: testing push" << endl << endl;
    for(int i = 0; i < 20; i++)
    {
        myA.push(i);
    }

    cout << "myA: " << myA << endl << endl;

    //testing front function
    cout << "QUEUE: testing front function" << endl << endl;

    cout << "front: " << myA.front() << endl << endl;

    //Testing pop
    for(int i = 10; i < 20; i++)
    {
        cout << "myA_pop: " << myA.pop() << endl;
    }

    cout << "myA: " << myA << endl << endl;

    //recreating myA for testing Big Three
    for(int i = 10; i < 20; i++)
    {
        myA.push(i);
    }

    cout << "myA: " << myA << endl << endl;

    //copy constructor
    cout << "QUEUE: testing copy constructor" << endl << endl;
    myQueue<int> myB(myA);

    cout << "myB: " << myB << endl << endl;

    //assignment operator
    cout << "QUEUE: testing assignment operator" << endl << endl;
    myQueue<int> myC;
    myC = myB;

    cout << "myC: " << myC << endl << endl;

    //testing self assignment
    cout << "QUEUE: testing self assignment" << endl << endl;
    myC = myC;

    cout << "myC: " << myC << endl << endl;

    return 0;
}
