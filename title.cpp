
#include "DxLib.h"
#include "title.h"

#include "main.h"
extern Main main_game;

Title::Title(){

	menu = START;

}

void Title::render(){

	DrawFormatString(0,0, GetColor(255,255,255), "%d", menu);


	DrawFormatString((640-GetDrawFormatStringWidth("TOWER OF ELDER DRAGON"))/2,80, GetColor(255,255,255), "TOWER OF ELDER DRAGON");


	DrawFormatString((640-GetDrawFormatStringWidth("NEW GAME"))/2,240, GetColor(255,255,255), "NEW GAME");
	DrawFormatString((640-GetDrawFormatStringWidth("CONTINUE"))/2,280, GetColor(255,255,255), "CONTINUE");
	DrawFormatString((640-GetDrawFormatStringWidth("END GAME"))/2,320, GetColor(255,255,255), "END GAME");
	DrawFormatString((640-GetDrawFormatStringWidth("Copyright: 2011 by MUSYOKU DOUTEI ŸHyQRiOn/vs"))/2,400, GetColor(255,255,255), "Copyright: 2011 by MUSYOKU DOUTEI ŸHyQRiOn/vs");
	DrawFormatString((640-GetDrawFormatStringWidth("Created By ...?"))/2,420, GetColor(255,255,255), "Created By ...?");

	switch( menu ){

		case START:
			DrawFormatString(250 ,240, GetColor(255,255,255), "=>");
			break;
		case CONTINUE:
			DrawFormatString(250 ,280, GetColor(255,255,255), "=>");
			break;
		case END:
			DrawFormatString(250 ,320, GetColor(255,255,255), "=>");
			break;
	
	}

}

void Title::update(){
	;
}

void Title::event_handler( int* Key ){

	if ( Key[ KEY_INPUT_DOWN ] == 1 ) {
		menu = (menu + 1) % MAX_VALUE;


	} else if (Key[ KEY_INPUT_UP ] == 1 ){
		menu = (menu - 1) % MAX_VALUE;
		if( menu < 0){
			menu += MAX_VALUE;
		}
	}

	if ( menu == START && Key[ KEY_INPUT_Z] == 1){

		main_game.set_game_state( CITY );
		
	} else if (menu == CONTINUE && Key[ KEY_INPUT_Z] == 1){
		;
	} else if (menu == END && Key[ KEY_INPUT_Z] == 1){
		main_game.set_end_game(true);
	}
}

