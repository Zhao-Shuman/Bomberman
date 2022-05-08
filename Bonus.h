//
// Created by User win 10 on 08.05.2022.
//

#ifndef BOMBERMAN_BONUS_H
#define BOMBERMAN_BONUS_H

#include "PhysicalObject.h"
#include "BonusType.h"

class Bonus : PhysicalObject
{
public:
	Bonus () {}
	virtual ~Bonus () {}
//func which adds object to the map of physical objects
	virtual void addObject (const AbstractObject &obj) const override {};
	virtual void renderObject () const override {};
	virtual void updateObject () const override {};
	virtual pair<size_t, size_t> getCoordinates () const override {};
	virtual bool checkCollision (const AbstractObject &object) const override {};

	BonusType getBonusType () {};

private:
	BonusType bonus_type;


};

#endif //BOMBERMAN_BONUS_H
