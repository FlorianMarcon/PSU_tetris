/*
** EPITECH PROJECT, 2017
** help
** File description:
** help
*/

const char	*message_help[] = {
	"Usage:  %s [options]\n",
	"Options:\n",
	"\t--help               Display this help\n",
	"\t-L --level={num}     Start Tetris at level num (def: 1)\n",
	"\t-l --key-left={K}    Move the tetrimino LEFT using the K key \
(def: left arrow)\n",
	"\t-r --key-right={K}   Move the tetrimino RIGHT using the K key \
(def: right arrow)\n",
	"\t-t --key-turn={K}    TURN the tetrimino clockwise 90d using the K \
key (def: top arrow)\n",
	"\t-d --key-drop={K}    DROP the tetrimino using the K key \
(def: down arrow)\n",
	"\t-q --key-quit={K}    QUIT the game using the K key (def: `q' key)\n",
	"\t-p --key-pause={K}   PAUSE/RESTART the game using the K key \
(def: space bar)\n",
	"\t--map-size={row,col} Set the numbers of rows and columns of the map \
(def: 20,10)\n",
	"\t-w --without-next    Hide next tetrimino (def: false)\n",
	"\t-D --debug           Debug mode (def: false)\n",
	NULL
};
