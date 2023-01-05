#include "StartMenu.h"
#include "HelloWorldScene.h"
#include "LevelChoice.h"
#include "Settings.h"

USING_NS_CC;

static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

Scene* StartMenu::createScene()
{
	return StartMenu::create();
}

bool StartMenu::init()
{
	if (!Scene::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	// Background music

	auto musicVol = 0.1f;
	auto gameAudioProfile = AudioEngine::INVALID_AUDIO_ID;

	if (gameAudioProfile == AudioEngine::INVALID_AUDIO_ID)
	{
		gameAudioProfile = AudioEngine::play2d("Music/Vagabond.mp3", true, musicVol);
	}

	// Background
	auto bg1 = Sprite::create("MenuBack.png");
	float scale = MAX(visibleSize.width / bg1->getContentSize().width, visibleSize.height / bg1->getContentSize().height);
	bg1->setScale(scale);
	bg1->getContentSize().height;
	bg1->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2));

	this->addChild(bg1, 0);

	// Title

	auto label = Label::createWithTTF("Les Mings", "fonts/Marker Felt.ttf", 70);

	if (label == nullptr ||
		label->getContentSize().width <= 0 ||
		label->getContentSize().height <= 0)
	{
		problemLoading("'font/Marker Felt.tff'");
	}

	else
	{
		label->setPosition(Vec2(origin.x + visibleSize.width * 0.5,
			origin.y + visibleSize.height * 0.8 - label->getContentSize().height));
	}

	this->addChild(label, 1);

	auto changeFont = MenuItemFont::create("Start", CC_CALLBACK_1(StartMenu::menuChangeScene, this));

	if (changeFont == nullptr ||
		changeFont->getContentSize().width <= 0 ||
		changeFont->getContentSize().height <= 0)
	{
		problemLoading("'fonts/Marker Felt.ttf'");
	}

	else
	{
		changeFont->setPosition(Vec2(origin.x + visibleSize.width / 2,
			origin.y + visibleSize.height * 0.5 - changeFont->getContentSize().height));
	}

	auto menu1 = Menu::create(changeFont, NULL);
	menu1->setPosition(Vec2::ZERO);
	this->addChild(menu1, 4);

	auto settings = MenuItemFont::create("Settings", CC_CALLBACK_1(StartMenu::menuSettings, this));

	if (settings == nullptr ||
		settings->getContentSize().width <= 0 ||
		settings->getContentSize().height <= 0)
	{
		problemLoading("'fonts/Marker Felt.ttf'");
	}

	else
	{
		settings->setPosition(Vec2(origin.x + visibleSize.width * 0.5,
			origin.y + visibleSize.height * 0.4 - settings->getContentSize().height));
	}

	auto menu2 = Menu::create(settings, NULL);
	menu2->setPosition(Vec2::ZERO);
	this->addChild(menu2, 4);

	auto quit = MenuItemFont::create("Quit", CC_CALLBACK_1(StartMenu::menuCloseCallback, this));

	if (quit == nullptr ||
		quit->getContentSize().width <= 0 ||
		quit->getContentSize().height <= 0)
	{
		problemLoading("'fonts/Marker Felt.ttf'");
	}

	else
	{
		quit->setPosition(Vec2(origin.x + visibleSize.width * 0.5,
			origin.y + visibleSize.height * 0.3 - quit->getContentSize().height));
	}

	auto menu3 = Menu::create(quit, NULL);
	menu3->setPosition(Vec2::ZERO);
	this->addChild(menu3, 4);

}

void StartMenu::menuChangeScene(Ref* pSender)
{
	auto scene = HelloWorld::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(0.5, scene, Color3B(0, 0, 0)));
}

void StartMenu::menuSettings(Ref* pSender)
{
	auto set = Settings::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(0.5, set, Color3B(0, 0, 0)));
}

void StartMenu::menuCloseCallback(Ref* pSender)
{
	Director::getInstance()->end();
}