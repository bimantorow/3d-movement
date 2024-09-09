build:
	gcc -o 3d_movement -I./include/ -Wall -std=gnu17 -pedantic ./src/*.c `sdl2-config --cflags --libs`