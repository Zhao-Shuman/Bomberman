#pragma once

#ifndef BOMBERMAN_ENEMYGHOST_H
#define BOMBERMAN_ENEMYGHOST_H

#include "Enemy.h"

class EnemyGhost : public Enemy
{
public:
	EnemyGhost (const char *p_filename, int p_x, int p_y, string p_tag_obj) : Enemy(p_filename, p_x, p_y, p_tag_obj) {}
	~EnemyGhost () override {}
	void update () override;
	void draw () override;
	void init () override;
};

#endif //BOMBERMAN_ENEMYGHOST_H
