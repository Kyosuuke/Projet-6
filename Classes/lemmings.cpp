#include "lemmings.h"

USING_NS_CC;


lemmings::lemmings() {

}

lemmings::~lemmings() {

}

bool lemmings::init() {

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto sprite = Sprite::create("Sprite/Knight1.png");
    auto myNode = Node::create();

    auto physicsBody = PhysicsBody::createBox(Size(25.0f, 50.0f), PhysicsMaterial(0.1f, 0.0f, 1.0f));
    physicsBody->setDynamic(true);

    if (sprite == nullptr)
    {
        //problemLoading("'HelloWorld.png'");
    }
    else
    {
        // position the sprite on the center of the screen
        sprite->setPosition(Vec2(visibleSize.width / 3 + origin.x, visibleSize.height / 2 + origin.y));
        sprite->addComponent(physicsBody);

        scheduleUpdate();
        // add the sprite as a child to this layer
        this->addChild(sprite);
    }

    //auto map = TMXTiledMap::create("Map/Test.tmx");
    //this->addChild(map, 3);

    //auto spritepos = sprite->getPosition();

    return true;
}

void lemmings::update(float dt){

    if (stateLemmings == false) {
        this->setPositionX(this->getPositionX() + 0);
        stateLemmings = true;
    }
    else if (stateLemmings == true && frameSpawn >= 120) {
        this->setPositionX(this->getPositionX() + 30*dt);
    }

    frameSpawn++;
}