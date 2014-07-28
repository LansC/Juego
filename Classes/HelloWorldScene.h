#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "C:\cocos2d\cocos2d-x-2.2.5\projects\OneGame\proj.win32\HudLayer.h"


using namespace cocos2d;
//esta directiva le dice al compilador que utilice el namespace cocos2d para que
//no tengas que agregar el prefijo cocos2d:: de aqui en adelante

class HelloWorld : public cocos2d::CCLayer
{

	//esto crea una variable de instancia privada para tener una referencia al mapa (*.tmx)
	// y la otra para tener una referencia a la capa de fondo del mapa.
private:
	CCTMXTiledMap * _tileMap;
	CCTMXLayer * _background;
	CCSprite* _player;
	CCTMXLayer *_meta;
	CCTMXLayer *_foreground;
	HudLayer *_hud;

	int _numCollected = 0;

public:
	
	void setViewPointCenter(CCPoint position);

	void registerWithTouchDispatcher();

	void setPlayerPosition(CCPoint position);

	bool ccTouchBegan(CCTouch *touch, CCEvent *event);
	void ccTouchEnded(CCTouch *touch, CCEvent *event);

	CCPoint tileCoordForPosition(CCPoint position);

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();

	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::CCScene* scene();

	// a selector callback
	void menuCloseCallback(CCObject* pSender);

	// implement the "static node()" method manually
	CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
