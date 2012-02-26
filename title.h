
#ifndef __TITLE_H__
#define __TITLE_H__

#include "gamestate.h"
#include <string>
using namespace std;

class Title : public IGameState{

	enum title_menu {
		START,
		CONTINUE,
		END,
		MAX_VALUE

	};

	private:
		int menu;
		bool music;

	public:
		Title();
		void render();
		void update();
		void event_handler( int* Key );

};



#endif
