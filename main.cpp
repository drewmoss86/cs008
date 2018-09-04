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
    cout << "myQUEUE: testing push" << endl << endl;
//    for(int i = 0; i < 20; i++)
//    {
        myA.push(1);
        myA.push(2);
//    }

    cout << "myA: " << myA << endl << endl;

//    //Testing pop
//    for(int i = 10; i < 20; i++)
//    {
//        cout << "myA_pop: " << myA.pop() << endl;
//    }
//    cout << endl;

//    //recreating myA for testing Big Three
//    for(int i = 10; i < 20; i++)
//    {
//        myA.push(i);
//    }

//    myQueue<int> myB(myA);

//    cout << "myB: " << myB << endl << endl;



    return 0;
}
