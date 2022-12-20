#ifndef STARTMENU_SCENE
#define STARTMENU_SCENE

#include "cocos2d.h"
#include "AudioEngine.h"

class StartMenu : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    void menuChangeScene(cocos2d::Ref* pSender);

    void menuSettings(cocos2d::Ref* pSender);

    void menuCloseCallback(Ref* pSender);

    CREATE_FUNC(StartMenu);

};
#endif // !STARTMENU_SCENE