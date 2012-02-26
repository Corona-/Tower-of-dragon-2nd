
#ifndef __CITY_H__
#define __CITY_H__

#include "gamestate.h"

class City : public IGameState {

	enum city_menu {
		BAR,
		INN,
		HOUSE,
		SHOP,
		TEMPLE,
		CASTLE,
		TOWER,
		MAX_VALUE
	};

	private:
		int menu;
		bool music;

	public:
		City();
		void render();
		void update();
		void event_handler( int* Key );

};


#endif