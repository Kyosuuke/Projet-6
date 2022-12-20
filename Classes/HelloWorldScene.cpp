#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object


    auto bg1 = Sprite::create("bg/bg1.png");
    float scale1 = MAX(visibleSize.width / bg1->getContentSize().width, visibleSize.height / bg1->getContentSize().height);
    bg1->setScale(scale1);
    bg1->getContentSize().height;
    bg1->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2));

    this->addChild(bg1, 0);

    auto bg2 = Sprite::create("bg/bg2.png");
    float scale2 = MAX(visibleSize.width / bg2->getContentSize().width, visibleSize.height / bg2->getContentSize().height);
    bg2->setScale(scale2);
    bg2->getContentSize().height;
    bg2->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2));

    this->addChild(bg2, 1);

    auto bg3 = Sprite::create("bg/bg3.png");
    float scale3 = MAX(visibleSize.width / bg3->getContentSize().width, visibleSize.height / bg3->getContentSize().height);
    bg3->setScale(scale3);
    bg3->getContentSize().height;
    bg3->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2));

    this->addChild(bg3, 2);

    auto bg4 = Sprite::create("bg/bg4.png");
    float scale4 = MAX(visibleSize.width / bg4->getContentSize().width, visibleSize.height / bg4->getContentSize().height);
    bg4->setScale(scale4);
    bg4->getContentSize().height;
    bg4->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2));

    this->addChild(bg4, 3);

    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

    if (closeItem == nullptr ||
        closeItem->getContentSize().width <= 0 ||
        closeItem->getContentSize().height <= 0)
    {
        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width - closeItem->getContentSize().width/2;
        float y = origin.y + closeItem->getContentSize().height/2;
        closeItem->setPosition(Vec2(x,y));
    }

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label

    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    if (label == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }

    else
    {
        // position the label on the center of the screen
        label->setPosition(Vec2(origin.x + visibleSize.width/2,
                                origin.y + visibleSize.height - label->getContentSize().height));

        // add the label as a child to this layer
        this->addChild(label, 1);
    }

    auto test = Label::createWithTTF("Test", "fonts/Marker Felt.ttf", 24);
    if (test == nullptr)
    {
        problemLoading("'fonts/Marker Felt.tff");
    }

    else
    {
        test->setPosition(Vec2(origin.x + visibleSize.width/4,
            origin.y + visibleSize.height - test->getContentSize().height));

        this->addChild(test, 1);
    }


    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");
    auto myNode = Node::create();
    if (sprite == nullptr)
    {
        problemLoading("'HelloWorld.png'");
    }
    else
    {
        // position the sprite on the center of the screen
        sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

        // add the sprite as a child to this layer
        this->addChild(sprite, 4);
    }
    return true;
    
    auto map = TMXTiledMap::create("Map/TestMap.tmx");
    this->addChild(map, 4, 99);
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}
