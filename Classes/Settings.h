#pragma once
#include <cocos2d.h>
#include <iostream>

#ifndef SETTINGS_SCENE
#define SETTINGS_SCENE

class Settings : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	void menuBack(cocos2d::Ref* pSender);

	CREATE_FUNC(Settings);
};

#endif // !SETTINGS_SCENE
