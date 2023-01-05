#pragma once

#include "cocos2d.h"

class lemmings : public cocos2d::Sprite {


public:
	lemmings();
	virtual ~lemmings();

	virtual bool init();
	virtual void  update(float dt);

	bool stateLemmings = false;
	int frameSpawn = 0;

	

	CREATE_FUNC(lemmings);
};

