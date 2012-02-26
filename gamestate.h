
#ifndef __GAMESTATE_H__
#define __GAMESTATE_H__


class IGameState{


	public:
		virtual void render()=0;
		virtual void update()=0;
		virtual void event_handler( int* Key )=0;
};

#endif