#ifndef RL_TERMINAL_H
#define RL_TERMINAL_H


#include "genos/container/gstring.h"
#include "genos/dev/symb_dev.h"

// direction of history navigation
#define _HIST_UP   0
#define _HIST_DOWN 1

#define _COMMAND_LINE_LEN 50
#define _RING_HISTORY_LEN 256

namespace genos {

class ring_history_t{
	public:
	char ring_buf [_RING_HISTORY_LEN];
	int begin;
	int end;
	int cur;
	
void hist_erase_older ();
int hist_is_space_for_new (int len);
void print_hist ();
void hist_save_line (char * line, int len);
int hist_restore_line (char * line, int dir);
} ;

class rl_terminal : public symb_dev{
	public:
	char oldchar;
	gstring str; 	
	gstring::cursor cur;
	b_ostream* echo;
	symb_dev* echo_com;	
	int mode;
	void hist_search (int dir);
	ring_history_t ring_hist;
	
	
	size_t write(uint8_t);
	void command(pair_message); 
	
	//void rl_rewrite();
	void	print_prompt();
	rl_terminal(symb_dev* _echo=0) : oldchar(0), echo(_echo) , cur(str), mode(0) {};
	
	void execute();
	//void init(symb_dev* _echo=0);
	
	void set_echo(b_ostream& s) {echo_com=0; echo=&s;};
	void set_echo(symb_dev& s) {echo_com=&s; echo=&s;};
	
	using b_ostream::write;
	};

};
#endif
