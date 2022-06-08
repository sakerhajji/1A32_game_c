prog: main.o menu.o prso.o inigme.o bg.o
	gcc main.o menu.o prso.o inigme.o bg.o -o prog -lSDL -lSDL_ttf -g -lSDL_image -lSDL_mixer
main.o:main.c 
	gcc -c main.c -g
menu.o:menu.c
	gcc -c menu.c -g
prso.o: prso.c
	gcc -c prso.c -g
inigme.o : inigme.c
	gcc -c inigme.c -g
bg.o:bg.c
	gcc -c bg.c -g
				
		
