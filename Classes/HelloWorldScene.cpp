#include "HelloWorldScene.h"
#include "lemmings.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    auto scene = Scene::createWithPhysics();
    scene->getPhysicsWorld()->setGravity(Vec2(0, -900));

    scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_SHAPE);

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
    if ( !Scene::initWithPhysics() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto lemsbody = PhysicsBody::createBox(Size(16.0f, 16.0f),
                    PhysicsMaterial(0.1f, 1.0f, 0.0f));
    lemsbody->setDynamic(false);

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object


    auto bg1 = Sprite::create("bg1.png");
    float scale1 = MAX(visibleSize.width / bg1->getContentSize().width, visibleSize.height / bg1->getContentSize().height);
    bg1->setScale(scale1);
    bg1->getContentSize().height;
    bg1->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2));

    this->addChild(bg1, 0);

    auto bg2 = Sprite::create("bg2.png");
    float scale2 = MAX(visibleSize.width / bg2->getContentSize().width, visibleSize.height / bg2->getContentSize().height);
    bg2->setScale(scale2);
    bg2->getContentSize().height;
    bg2->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2));

    this->addChild(bg2, 1);


    /*Animation::addSpriteFrameWithFile("Sprite/Test-0.png");*/

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


    //auto sprite test
    /*auto spritetest = DrawNode::create();
    Vec2 rectangle[4];
    rectangle[0] = Vec2(-50, -50);
    rectangle[1] = Vec2(50, -50);
    rectangle[2] = Vec2(50, 50);
    rectangle[3] = Vec2(-50, 50);

    Color4F red(1, 255, 0, 1);

    spritetest->drawPolygon(rectangle, 4, red, 1, red);
    this->addChild(spritetest, 5);
    auto eventListener = EventListenerKeyboard::create();
    eventListener->onKeyPressed = [](EventKeyboard::KeyCode keyCode, Event* event) {
        Vec2 loc = event->getCurrentTarget()->getPosition();
        switch (keyCode)
        {
        case EventKeyboard::KeyCode::KEY_Q:
            event->getCurrentTarget()->setOpacity(100);
            break;
        }
        return true;
    };
    this->_eventDispatcher->addEventListenerWithSceneGraphPriority(eventListener, spritetest);*/

    //spawn lemmings
    scheduleUpdate();

    //map part
    auto map = TMXTiledMap::create("Map/Test.tmx");
    this->addChild(map, 3);

    //map colide
    auto edgeNode = Node::create();

    auto edgeBody = PhysicsBody::createEdgeBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 3);

    edgeNode->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    edgeNode->setPhysicsBody(edgeBody);

    this->addChild(edgeNode);

    return true;
}

void HelloWorld::update(float dt) {


    if (this->numberLemmings == 5) {
        this->lemming = lemmings::create();
        addChild(lemming, 4);

        this->numberLemmings--;
        
    }
    else if (this->numberLemmings >= 1 && frameSpawn >= 60) {
        this->lemming = lemmings::create();
        addChild(lemming, 4);

        this->numberLemmings--;
    }
    if ( frameSpawn == 60) {
        frameSpawn = 0;
    }
    
    this->frameSpawn++;
    
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}
