#include "../inc/simplewave.h"
/**
 * main - Program Entry Point 
 * Draws a representation of a sin wave to the screen "stdout"
 */
int main()
{
	initscr(); /*initialize screen*/
	cbreak(); /* allow for immediate character input*/
	noecho(); /* do not print characters to screen*/
	nodelay(stdscr, TRUE); /* getch is nonblocking*/
	int yMax, xMax; /* yMax - y axis of the screen xMax - x axis of the screen */
	getmaxyx(stdscr, yMax, xMax); /* get size of screen*/
	start_color(); /*start colors*/
	init_pair(1, COLOR_RED, COLOR_BLACK); /* color pair 1 = red on black*/
	init_pair(2, COLOR_GREEN, COLOR_BLACK); /* color pair 2 = green on black*/
	init_pair(3, COLOR_YELLOW, COLOR_BLACK); /* color pair 3 = yellow on black*/
	init_pair(4, COLOR_BLUE, COLOR_BLACK); /* color pair 4 = blue on black*/
	init_pair(5, COLOR_MAGENTA, COLOR_BLACK); /* color pair 5 = magenta on black*/

	int x = 0;

	while (x < xMax) 
	{
		/* Amplitude * sin((2π * time / Period) + Phase shift) */
		int y = (yMax/2) + (sin((2 * 3.14159 * x)/50) * (yMax/4));
		usleep(10000);

		if (x < (xMax/5)) {
			attron(COLOR_PAIR(1));
			mvprintw(y, x, "*");
			attroff(COLOR_PAIR(1));
			usleep(10000);
		}
		else if (x < (2*xMax/5)) {
			attron(COLOR_PAIR(2));
			mvprintw(y, x, "*");
			attroff(COLOR_PAIR(2));
			usleep(10000);
		}
		else if (x < (3*xMax/5)) {
			attron(COLOR_PAIR(3));
			mvprintw(y, x, "*");
			attroff(COLOR_PAIR(3));
			usleep(10000);
		}
		else if (x < (4*xMax/5)) {
			attron(COLOR_PAIR(4));
			mvprintw(y, x, "*");
			attroff(COLOR_PAIR(4));
			usleep(10000);

		}
		else {
			attron(COLOR_PAIR(5));
			mvprintw(y, x, "*");
			attroff(COLOR_PAIR(5));
			usleep(10000);

		}

		refresh();
		usleep(10000);
		x++;
	}
	/* Reverse and flip */
	int x2 = 0;

	while (x2 < xMax) 
	{
		/* Amplitude * sin((2π * time / Period) + Phase shift) */
		int y2 = (yMax/2) - (sin((2 * 3.14159 * x2)/50) * (yMax/4));
		usleep(10000);


		if (x2 < (xMax/5)) {
			attron(COLOR_PAIR(1));
			mvprintw(y2, x2, "*");
			attroff(COLOR_PAIR(1));
			usleep(10000);
		}
		else if (x2 < (2*xMax/5)) {
			attron(COLOR_PAIR(2));
			mvprintw(y2, x2, "*");
			attroff(COLOR_PAIR(2));
			usleep(10000);
		}
		else if (x2 < (3*xMax/5)) {
			attron(COLOR_PAIR(3));
			mvprintw(y2, x2, "*");
			attroff(COLOR_PAIR(3));
			usleep(10000);
		}
		else if (x2 < (4*xMax/5)) {
			attron(COLOR_PAIR(4));
			mvprintw(y2, x2, "*");
			attroff(COLOR_PAIR(4));
			usleep(10000);
		}
		else {
			attron(COLOR_PAIR(5));
			mvprintw(y2, x2, "*");
			attroff(COLOR_PAIR(5));
		}

		refresh();
		usleep(10000);
		x2++;
	}

	getch();
	endwin();
	return 0;
}
