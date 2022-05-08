
#ifndef BOMBERMAN_MOVABLEOBJECT_H
#define BOMBERMAN_MOVABLEOBJECT_H

#include <set>
#include "AbstractObject.h"

class MovableObject : public AbstractObject
{
public:
	MovableObject () = default;
	virtual ~MovableObject () {}
	virtual void addObject (const AbstractObject &obj) const = 0;
	virtual void renderObject () const = 0;
	virtual void updateObject () const = 0;
	virtual pair<size_t, size_t> getCoordinates () const = 0;
	virtual bool checkCollision (const AbstractObject &object) const = 0;

	virtual void move () const = 0;
//	virtual bool checkIfRendered (const AbstractObject &obj) const = 0;
private:
	set<AbstractObject> mov_obj_container;
	size_t velocity;

};

#endif //BOMBERMAN_MOVABLEOBJECT_H
