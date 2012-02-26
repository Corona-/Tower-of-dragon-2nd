

#include "DxLib.h"
#include "state.h"
#include "main.h"


int Key[256]; 
int UpdateKey(){
        char tmpKey[256]; 
        GetHitKeyStateAll( tmpKey ); 
        for( int i=0; i<256; i++ ){ 
                if( tmpKey[i] != 0 ){
                        Key[i]++;  
                } else {             
                        Key[i] = 0;  
                }
        }
        return 0;
}

Main main_game = Main();

int WINAPI WinMain(HINSTANCE,HINSTANCE,LPSTR,int){
        ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen( DX_SCREEN_BACK ); //ウィンドウモード変更と初期化と裏画面設定




        while( ScreenFlip()==0 && ProcessMessage()==0 && ClearDrawScreen()==0 && UpdateKey()==0 ){

			//state is set on event handler and change actual state here
			main_game.change_game_state();

			main_game.update();
			main_game.render();
			main_game.event_handler( Key );

			if (main_game.get_end_game()){
				break;
			}
				
        }
        
        DxLib_End();
        return 0;
}  