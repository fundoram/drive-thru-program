#ifndef EVENT_CPP
#define EVENT_CPP
#include "event.h"

event::event() : eType(' '), eTime(0), eTrans(0)
{
}
event::event(char etp, int etm, int etrn) : eType(etp), eTime(etm), eTrans(etrn)
{

}
void event::set(char etp, int etm, int etrn)
{
	eType = etp;
	eTime = etm;
	eTrans = etrn;
}
char event::getEType()
{
	return eType;
}
int event::getETime()
{
	return eTime;
}
int event::getETrans()
{
	return eTrans;
}
bool operator==(const event first, const event second)
{
	return first.eTime == second.eTime;
}
bool operator>(const event first, const event second)
{
	return first.eTime > second.eTime;
}

bool operator<(const event first, const event second)
{
	return first.eTime < second.eTime;
}
bool operator!=(const event first, const event second)
{
	return first.eTime != second.eTime;
}

#endif
