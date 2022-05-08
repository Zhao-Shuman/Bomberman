
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cassert>
#include <cctype>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <set>
#include <list>
#include <map>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <functional>
#include <memory>
#include <numeric>
#include <optional>
#include <variant>

#include "AbstractObject.h"

#ifndef BOMBERMAN_PHYSICALOBJECT_H
#define BOMBERMAN_PHYSICALOBJECT_H

using namespace std;

class PhysicalObject : public AbstractObject
{
public:
	PhysicalObject () {}
	virtual ~PhysicalObject () {}
//func which adds object to the map of physical objects
	virtual void addObject (const AbstractObject &obj) const = 0;
	virtual void renderObject () const = 0;
	virtual void updateObject () const = 0;
	virtual pair<size_t, size_t> getCoordinates () const = 0;
	virtual bool checkCollision (const AbstractObject &object) const = 0;

private:
	set<PhysicalObject> phys_obj_container;//container for storing physical objects
};

#endif //BOMBERMAN_PHYSICALOBJECT_H
