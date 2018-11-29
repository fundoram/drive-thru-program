#include <iostream>
#include "ArrayQueue.h"
#include <fstream>
#include "event.h"
#include <string>
using namespace std;

int main() {
	ArrayQueue<event> qA;
	ArrayQueue<event> qD;
	string filename = "time.txt";
	ifstream inFile;
	int time, trans, currentTime;

	double WaitTime = 0, Customers = 0;

	int NextDeparture = 0;

	cout << "**Taco Fry Drive In**";

	inFile.open(filename.c_str());
	getline(cin, filename);

	if (!inFile.fail()) {
		while (inFile >> time >> trans) {
			event * ptr = new event('A', time, trans);
			qA.enqueue(*ptr);
			Customers++;
			delete ptr;
		}
		cout << "Input File Completed." << endl << endl;
		inFile.close();
		while (!qA.isEmpty() || !qD.isEmpty()) {
			if (qD.isEmpty()) {
				event e = qA.peekFront();
				cout << e << endl;
				qA.dequeue();

				currentTime = e.getETime();

				event f;
				if (NextDeparture >= e.getETime()) {
					f = event('D', NextDeparture + e.getETrans(), NextDeparture - e.getETime());
					qD.enqueue(f);
				}
				else  {
					f = event('D', currentTime + e.getETrans(), 0);
					qD.enqueue(f);
				}
				NextDeparture = f.getETime();
			}
			else if (qA.isEmpty()) {
				while (!qD.isEmpty()) {
					event e = qD.peekFront();
					qD.dequeue();
					
					if (e.getETrans() > 0) {
						cout << "Customer who departed at " << e.getETime() << " had to wait " << e.getETrans() << endl;
						WaitTime += e.getETrans();
					}

					cout << e << endl;
				}
			}
			else if (qA.peekFront().getETime() <= qD.peekFront().getETime()) {
				event e = qA.peekFront();
				cout << e << endl;
				qA.dequeue();

				currentTime = e.getETime();

				event f;
				if (NextDeparture >= e.getETime()) {
					f = event('D', NextDeparture + e.getETrans(), NextDeparture - e.getETime());
					qD.enqueue(f);
				}
				else  {
					f = event('D', currentTime + e.getETrans(), 0);
					qD.enqueue(f);
				}
				NextDeparture = f.getETime();
			}
			else if (qD.peekFront().getETime() < qA.peekFront().getETime()) {
				event e = qD.peekFront();
				qD.dequeue();
				if (e.getETrans() > 0) {
					cout << "Customer who departed at " << e.getETime() << " had to wait " << e.getETrans() << endl;
					WaitTime += e.getETrans();
				}

				cout << e << endl;
			}
		}
	}
	else {
		cout << "\nCound not open file\n";
	}

	cout << endl << "Average Wait Time: " << WaitTime / Customers << endl << endl;

	system("pause");
	return 0;
}

