
#include "DxLib.h"
#include "main.h"
#include "title.h"
#include "city.h"


Main::Main(){
	end_game = false;
	game_state = TITLE;
	old_game_state = TITLE;
	game = new Title();
}

int Main::get_game_state() const{

	return game_state;

}

void Main::set_game_state( int state ) {
	old_game_state = game_state;
	game_state = state;
}

void Main::change_game_state(){

	if (this->game_state == this->old_game_state){
		return;
	}

	switch ( this->game_state ){
		case TITLE:
			delete game;
			game = new Title();
			break;
		case CITY:
			delete game;
			game = new City();
			break;
	}

	this->old_game_state = this->game_state;

}

void Main::set_end_game( bool end ) {
	end_game = end;
}

bool Main::get_end_game() const{
	return end_game;
}

void Main::render(){

	game->render();

}

void Main::update(){

	game->update();

}

void Main::event_handler( int* Key){

	if ( Key[ KEY_INPUT_ESCAPE ] == 1 ){
		end_game = true;
	}

	game->event_handler( Key );

}