
#ifndef BOMBERMAN_ENEMY_H
#define BOMBERMAN_ENEMY_H

#include<cstdio>

#include "MovableObject.h"
#include "EnemyType.h"

using namespace std;

class Enemy : public MovableObject
{
public:
	Enemy () = default;
	virtual ~Enemy () {}
	virtual void addObject (const AbstractObject &obj) const override ;
	virtual void renderObject () const override ;
	virtual void updateObject () const override ;
	virtual pair<size_t, size_t> getCoordinates () const override;
	EnemyType getEnemyType () ;//gets the type of the enemy
	virtual bool checkCollision (const AbstractObject &object) const override ;

	virtual void move () const override ;
private:
	EnemyType enemy_type;//type of the enemy
};

#endif //BOMBERMAN_ENEMY_H
