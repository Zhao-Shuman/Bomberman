
#ifndef BOMBERMAN_BOMB_H
#define BOMBERMAN_BOMB_H

#include "PhysicalObject.h"

class Bomb : public PhysicalObject
{
public:
	Bomb () {}
	virtual ~Bomb () {}
	virtual void addObject (const AbstractObject &obj) const override {};
	virtual void renderObject () const override {};
	virtual void updateObject () const override {};
	virtual pair<size_t, size_t> getCoordinates () const override {};
	virtual bool checkCollision (const AbstractObject &object) const override {};

	void BombExplode () {};//function for exploding a bomb after a certain time it was placed
	void setFlameSize (size_t size) {};//for bonuses
	size_t getFlameSize () const{}; //just a getter
private:
	size_t flame_size;
	const size_t BOMB_EXPLOSION_TIMER = 3;

};

#endif //BOMBERMAN_BOMB_H
