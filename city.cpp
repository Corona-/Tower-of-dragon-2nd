

#include "DxLib.h"
#include "city.h"

#include "main.h"
extern Main main_game;

City::City(){

	menu = BAR;

}

void City::render(){

	DrawFormatString((640-GetDrawFormatStringWidth("CITY"))/2,80, GetColor(255,255,255), "CITY");


	DrawFormatString((640-GetDrawFormatStringWidth("NEW GAME"))/2,240, GetColor(255,255,255), "BAR");
	DrawFormatString((640-GetDrawFormatStringWidth("CONTINUE"))/2,280, GetColor(255,255,255), "CONTINUE");
	DrawFormatString((640-GetDrawFormatStringWidth("END GAME"))/2,320, GetColor(255,255,255), "END GAME");
	DrawFormatString((640-GetDrawFormatStringWidth("Copyright: 2011 by MUSYOKU DOUTEI ŸHyQRiOn/vs"))/2,400, GetColor(255,255,255), "Copyright: 2011 by MUSYOKU DOUTEI ŸHyQRiOn/vs");
	DrawFormatString((640-GetDrawFormatStringWidth("Created By ...?"))/2,420, GetColor(255,255,255), "Created By ...?");


	DrawFormatString(250 ,240+menu*40, GetColor(255,255,255), "=>");


}

void City::update(){
	;
}

void City::event_handler( int* Key ){

	if ( Key[ KEY_INPUT_Z ] == 1 ){
		main_game.set_game_state( TITLE );
	}

	if ( Key[ KEY_INPUT_DOWN ] == 1 ) {
		menu = (menu + 1) % MAX_VALUE;


	} else if (Key[ KEY_INPUT_UP ] == 1 ){
		menu = (menu - 1) % MAX_VALUE;
		if( menu < 0){
			menu += MAX_VALUE;
		}
	}

	switch ( menu ) {
		case BAR:
			break;
		case INN:
			break;
		case HOUSE:
			break;
		case SHOP:
			break;
		case CASTLE:
			break;
		case TEMPLE:
			break;
		case TOWER:
			break;
	}
}

