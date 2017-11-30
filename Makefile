SDL_Stuff = -Ilib\SDL\include\SDL2 -Llib\SDL\lib -w  -lmingw32 -lSDL2main -lSDL2_ttf -lSDL2 -lSDL2_image 


Static_Stuff = -static-libgcc -static-libstdc++

all: 
	g++ -g src\main.cpp src\game.cpp src\gameobject.cpp src\player.cpp src\ball.cpp src\input.cpp src\score.cpp -Iheaders $(SDL_Stuff) $(Static_Stuff) -o bin\pong