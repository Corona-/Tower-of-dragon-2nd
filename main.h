
#ifndef __MAIN_H__
#define __MAIN_H__

#include "state.h"
#include "gamestate.h"


class Main : public IGameState{

	private:
		bool end_game;
		int game_state;
		int old_game_state;
		IGameState* game;

	public:
		Main();
		void set_game_state( int state);
		int get_game_state() const;
		void set_end_game( bool end );
		bool get_end_game() const;

		void change_game_state();

		void render();
		void update();
		void event_handler( int* Key);


};


#endif