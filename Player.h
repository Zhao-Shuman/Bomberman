#include <cstring>

#ifndef BOMBERMAN_PLAYER_H
#define BOMBERMAN_PLAYER_H

#include "MovableObject.h"

using namespace std;

class Player : public MovableObject
{
public:
	Player () = default;
	virtual ~Player () {}
	virtual void addObject (const AbstractObject &obj) const override ;
	virtual void renderObject () const override ;
	virtual void updateObject () const override ;
	virtual pair<size_t, size_t> getCoordinates () const override ;
	virtual bool checkCollision (const AbstractObject &object) const override ;
	virtual void move () const override ;

	void ifKeyPressed () ; //does smth if key was pressed
	void setVelocity (size_t); //for bonuses
	size_t getVelocity () ;
//	virtual bool checkIfRendered (const AbstractObject &obj) const override;
private:
	string player_name; //player`s name
	size_t bomb_cnt; //bomb counter
	size_t life_cnt; //lives of the player
};

#endif //BOMBERMAN_PLAYER_H
