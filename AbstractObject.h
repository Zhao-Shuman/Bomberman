
#include <iostream>

#ifndef BOMBERMAN_ABSTRACTOBJECT_H
#define BOMBERMAN_ABSTRACTOBJECT_H

using namespace std;

class AbstractObject
{
public:
	AbstractObject () {}
	virtual ~AbstractObject () {}
	virtual void addObject (const AbstractObject &obj) const = 0; //creates new object
	virtual void renderObject () const = 0; //renders an object
	virtual void updateObject () const = 0;//updates an object
	virtual pair<size_t, size_t> getCoordinates () const = 0; //Return coordinates of the current object
	virtual bool checkCollision (const AbstractObject &object) const = 0; //collision checking
protected:
	pair<size_t, size_t> coordinates;
};


#endif //BOMBERMAN_ABSTRACTOBJECT_H
