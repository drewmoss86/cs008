/******************************************
 * Name: Andrew Moss
 *
 * Date: 10/15/2018
 *
 * Class: CS 008
 *
 * Assignment: Priority Queue
 *
 ******************************************/
#include <iostream>
#include <iostream>
#include <random>
#include "heap.h"
#include <fstream>
//#include "info.h"

using namespace std;
//proto
//void test_info_struct(info<int> i, info<int> x);
void test_heap_func(Heap<int> h);
void test_pQ_func(PQueue<int> p);


int main()
{

    PQueue<int> pQ;

    test_pQ_func(pQ);

    return 0;
}

void test_pQ_func(PQueue<int> pq)
{

    ofstream outFile;
    outFile.open("heapOutput.txt");
    outFile<< "/******************************************" << endl;
    outFile<< "* Name: Andrew Moss" << endl;
    outFile<< "*" << endl;
    outFile<< "* Date: 10/15/2018" << endl;
    outFile<< "*" << endl;
    outFile<< "* Class: CS 008" << endl;
    outFile<< "*" << endl;
    outFile<< "* Assignment: Priority Queue" << endl;
    outFile<< "*" << endl;
    outFile<< "******************************************/" << endl;

    PQueue<int> pq_copy;

    for (int i = 0; i<100; i++){
        pq.insert(rand()%1000, rand()%10);
    }

    outFile << "Print Tree" << endl;
    outFile << pq;

//    pq_copy = pq;

//    cout << pq_copy;

    outFile << "Testing pq.Pop(): " << endl;
    for (int i = 0; i<pq.size(); i++){
        outFile << pq.Pop() << endl;
    }

    cout << "Done" << endl;

    outFile.close();


}
