#include "Settings.h"
#include "StartMenu.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

Scene* Settings::createScene()
{
	return Settings::create();
}

bool Settings::init()
{
	if (!Scene::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto changeFont = MenuItemFont::create("Back", CC_CALLBACK_1(Settings::menuBack, this));

	if (changeFont == nullptr ||
		changeFont->getContentSize().width <= 0 ||
		changeFont->getContentSize().height <= 0)
	{
		problemLoading("'fonts/Marker Felt.ttf'");
	}

	else
	{
		changeFont->setPosition(Vec2(origin.x + visibleSize.width *0.1,
			origin.y + visibleSize.height - changeFont->getContentSize().height));
	}

	auto menu1 = Menu::create(changeFont, NULL);
	menu1->setPosition(Vec2::ZERO);
	this->addChild(menu1, 1);

	auto m = Label::createWithTTF("Master Volume", "fonts/Marker Felt.ttf", 24);

	if (m == nullptr ||
		m->getContentSize().width <= 0 ||
		m->getContentSize().height <= 0)
	{
		problemLoading("'fonts/Marker Felt.ttf'");
	}

	else
	{
		m->setPosition(Vec2(origin.x + visibleSize.width * 0.5,
			origin.y + visibleSize.height * 0.75 - m->getContentSize().height));
	}

	this->addChild(m, 1);

	auto slider = ui::Slider::create();
	slider->loadBarTexture("Sliders/Slider_Back.png");
	slider->loadSlidBallTextures("Sliders/SliderNode_Normal.png", "Sliders/SliderNode_Press.png", "Sliders/SliderNode_Disable.png");
	slider->loadProgressBarTexture("Sliders/Slider_PressBar.png");

	slider->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type)
		{
			switch (type)
			{
			case ui::Widget::TouchEventType::BEGAN:
				break;
			case ui::Widget::TouchEventType::ENDED:
				std::cout << "slider moved" << std::endl;
				break;
			default:
				break;
			}
		});

	slider->setPosition(Vec2(origin.x + visibleSize.width * 0.5,
		origin.y + visibleSize.height * 0.7 - changeFont->getContentSize().height));
	this->addChild(slider, 1);
}

void Settings::menuBack(Ref* pSender)
{
	auto mainMenu = StartMenu::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(0.5, mainMenu, Color3B(0, 0, 0)));
}

