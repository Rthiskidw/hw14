#include <iostream>
#include "doublyList.h"
using namespace std;



//MAIN
int main(int argc, const char * argv[]) {
	
	//Part 1
	doublyList<int> myDoubly;
	
	myDoubly.addNode(1);
	myDoubly.addNode(2);
	myDoubly.addNode(3);
	myDoubly.addNode(4);
	myDoubly.addNode(5);
	
	cout << "Part 1: printing 5 nodes. \n";
	myDoubly.printList();
	
	//Part 2 testing copy constructor
	
	doublyList<int> yourDoubly(myDoubly);
	cout << "Part 2: testing copy constructor. \n";
	yourDoubly.printList();
	
	doublyList<int> thierDoubly;
	cout << "Part 2: testing assignment operator. \n";
	thierDoubly = yourDoubly;
	thierDoubly.printList();
	
	//Part 3 reversing the list
	cout << "Part 3: testing reverse function. \n";
	doublyList<int> reverseDoubly = thierDoubly.reverse();
	reverseDoubly.printList();
	
	//Part 4 deleting from the list
	cout << "Part 4 : deleting from the list. \n";
	thierDoubly.deleteNode(3);
	thierDoubly.printList();
	
	//deleting value not in list
	thierDoubly.deleteNode(-8);
	
	//emptying the list then trying to delete from it
	thierDoubly.deleteNode(1);
	thierDoubly.deleteNode(2);
	thierDoubly.deleteNode(4);
	thierDoubly.deleteNode(5);
	thierDoubly.deleteNode(5);
	
	//Part 5 adding node to the middle
	cout << "Part 5: inserting into the middle. \n";
	myDoubly.addNode(6);
	myDoubly.putInMiddle(99);
	myDoubly.printList();
	
	//Part 6 steps 1-4 with doubles
/*------------------------------------------------------------*/
	
	cout << "Part 6: steps 1-4 with doubles. \n";
	
	//Part 1
	doublyList<double> myDoublyDoubles;
	
	myDoublyDoubles.addNode(1.9);
	myDoublyDoubles.addNode(2.9);
	myDoublyDoubles.addNode(3.9);
	myDoublyDoubles.addNode(4.9);
	myDoublyDoubles.addNode(5.9);
	
	cout << "Part 1: printing 5 nodes. \n";
	myDoublyDoubles.printList();
	
	//Part 2 testing copy constructor
	
	doublyList<double> yourDoublyDoubles(myDoublyDoubles);
	cout << "Part 2: testing copy constructor. \n";
	yourDoublyDoubles.printList();
	
	doublyList<double> thierDoublyDoubles;
	cout << "Part 2: testing assignment operator. \n";
	thierDoublyDoubles = yourDoublyDoubles;
	thierDoubly.printList();
	
	//Part 3 reversing the list
	cout << "Part 3: testing reverse function. \n";
	doublyList<double> reverseDoublyDoubles = thierDoublyDoubles.reverse();
	reverseDoublyDoubles.printList();
	
	//Part 4 deleting from the list
	cout << "Part 4 : deleting from the list. \n";
	thierDoublyDoubles.deleteNode(3.9);
	thierDoublyDoubles.printList();
	
	//deleting value not in list
	thierDoublyDoubles.deleteNode(-8);
	
	//emptying the list then trying to delete from it
	thierDoublyDoubles.deleteNode(1.9);
	thierDoublyDoubles.deleteNode(2.9);
	thierDoublyDoubles.deleteNode(4.9);
	thierDoublyDoubles.deleteNode(5.9);
	thierDoublyDoubles.deleteNode(5.9);
	
	//Part 5 adding node to the middle
	cout << "Part 5: inserting into the middle. \n";
	myDoublyDoubles.addNode(6.9);
	myDoublyDoubles.putInMiddle(99);
	myDoublyDoubles.printList();
	
	return 0;
}


