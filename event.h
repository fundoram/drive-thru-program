#ifndef EVENT_H
#define EVENT_H

#include <iostream>
using std::ostream;


class event
{
private:
	char eType;
	int eTime;
	int eTrans;

public:
	event();
	event(char etp, int etm, int etrn);
	void set(char etp, int etm, int etrn);
	char getEType();
	int getETime();
	int getETrans();
	friend bool operator==(const event first, const event second);
	friend bool operator<(const event first, const event second);
	friend bool operator>(const event first, const event second);
	friend bool operator!=(const event first, const event second);
    friend ostream& operator<<(ostream& out, event& n){
        out<< n.eType << " " << n.eTime << " " << n.eTrans;
        return out;
    }
};

#endif
