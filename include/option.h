/*
** EPITECH PROJECT, 2017
** option
** File description:
** option
*/

#ifndef OPTION_
#define OPTION_

#include "header_tetris.h"

const char optstring[] = "hL:l:r:t:d:q:p:m:wD";

const struct option setting[] = {
	{"help", no_argument, 0, 'h'},
	{"level", required_argument, 0, 'L'},
	{"key-left", required_argument, 0, 'l'},
	{"key-right", required_argument, 0, 'r'},
	{"key-turn", required_argument, 0, 't'},
	{"key-drop", required_argument, 0, 'd'},
	{"key-quit", required_argument, 0, 'q'},
	{"key-pause", required_argument, 0, 'p'},
	{"map-size", required_argument, 0, 'm'},
	{"without-next", no_argument, 0, 'w'},
	{"debug", no_argument, 0, 'D'},
	{0, 0, 0, 0}
};

typedef struct setting_s {
	char label;
	int (*ptr)(char *, game_t *);
}setting_t;

const setting_t funct_set[9] = {
	{'L', set_level},
	{'l', set_key_left},
	{'r', set_key_right},
	{'t', set_key_turn},
	{'d', set_key_drop},
	{'q', set_key_quit},
	{'p', set_key_pause},
	{'m', set_size},
	{'\0', NULL}
};
#endif
