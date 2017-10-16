#include <ncurses.h>
int main(){
	initscr();
	noecho();
	curs_set(0);
	int posX,posY,key,maxX,maxY,startY,currentX,level;
	int levelHeight = 5;
	getmaxyx(stdscr,maxY,maxX);
	startY=maxY-levelHeight;
	//Draw ground
	while(startY != maxY){
		currentX=0;
		level++;
		while(currentX != maxX){
			mvprintw(startY,currentX,"X");
			currentX++;
		}
		startY++;
	}
	startY=maxY-levelHeight;
	posY=startY-1;
	mvprintw(posY,posX,"#");
	refresh();
	//Control "Player"
	while((key = getch())!=27){
		if(posY != startY){
			move(posY,posX);
			delch();
			if(key == 119){posY--;}
			if(key == 115){posY++;}
			if(key == 97){posX--;}
			if(key == 100){posX++;}
			mvprintw(posY,posX,"#");
			refresh();
		}else{
			move(posY,posX);
			printw("X");
			posY--;
			refresh();
		}
	}
	endwin();
	return 0;
}
