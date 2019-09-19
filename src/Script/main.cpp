#include "../Header/all.hpp"

const int xsize = Block_PixelSize*MAP_X_SideLength ,ysize = Block_PixelSize*MAP_Y_SideLength;

int main(int argc, char* args[])
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window = SDL_CreateWindow("Hey" ,SDL_WINDOWPOS_CENTERED ,SDL_WINDOWPOS_CENTERED ,xsize ,ysize ,0);
	SDL_Renderer* render = SDL_CreateRenderer(window ,-1 ,SDL_RENDERER_ACCELERATED);
	SDL_Surface* image = NULL; 
 	image = IMG_Load("../image/UzimatuTiyaIcon.bmp");
	printf("%s",SDL_GetError());
	
	SDL_Texture* texture =  SDL_CreateTextureFromSurface(render ,image);
	SDL_Rect copy = {0 ,0 ,xsize ,ysize};
	SDL_Rect dwar = {0 ,0 ,xsize ,ysize};
	
	Map map;

	SDL_RenderCopy(render ,texture ,&copy ,&dwar);
	SDL_RenderPresent(render);
	
	/*//SDL_Event ev;

		SDL_SetRenderDrawColor(render, 0, 255, 0, 255);
		SD
		L_RenderClear(render);
		while(SDL_PollEvent(&ev))
		{
			if (ev.type == SDL_QUIT)
			return 0;
		}
		SDL_SetRenderDrawColor(render, 255, 0, 0, 255);
		SDL_RenderDrawLine(render,0, 0, 640, 480);
		SDL_RenderPresent(render);	
	*/

	SDL_Delay(30000); //60sec
	SDL_RenderClear(render);
	SDL_RenderPresent(render);
	SDL_Quit();
	return 0;
}