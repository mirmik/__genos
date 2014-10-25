
#include "genos/rl_terminal/rl_terminal.h"
#include "genos.h"


#include <genos/console/strexecute.h>
namespace genos {

/*
// print buffer content on screen
void ring_history_t::print_hist ()
{
	printf ("\n");
	for (int i = 0; i < _RING_HISTORY_LEN; i++) {
		if (i == this->begin)
			printf ("b");
		else 
			printf (" ");
	}
	printf ("\n");
	for (int i = 0; i < _RING_HISTORY_LEN; i++) {
		if (isalpha(this->ring_buf[i]))
			printf ("%c", this->ring_buf[i]);
		else 
			printf ("%d", this->ring_buf[i]);
	}
	printf ("\n");
	for (int i = 0; i < _RING_HISTORY_LEN; i++) {
		if (i == this->end)
			printf ("e");
		else 
			printf (" ");
	}
	printf ("\n");
}*/
/*
//*****************************************************************************
// remove older message from ring buffer
void ring_history_t::hist_erase_older ()
{
	int new_pos = this->begin + this->ring_buf [this->begin] + 1;
	if (new_pos >= _RING_HISTORY_LEN)
		new_pos = new_pos - _RING_HISTORY_LEN;
	
	this->begin = new_pos;
}

//*****************************************************************************
// check space for new line, remove older while not space
int ring_history_t::hist_is_space_for_new (int len)
{
	if (this->ring_buf [this->begin] == 0)
		return true;
	if (this->end >= this->begin) {
		if (_RING_HISTORY_LEN - this->end + this->begin - 1 > len)
			return true;
	}	else {
		if (this->begin - this->end - 1> len)
			return true;
	}
	return false;
}

//*****************************************************************************
// put line to ring buffer
void ring_history_t::hist_save_line (char * line, int len)
{
	if (len > _RING_HISTORY_LEN - 2)
		return;
	while (!hist_is_space_for_new (len)) {
		hist_erase_older ();
	}
	// if it's first line
	if (this->ring_buf [this->begin] == 0) 
		this->ring_buf [this->begin] = len;
	
	// store line
	if (len < _RING_HISTORY_LEN-this->end-1)
		memcpy (this->ring_buf + this->end + 1, line, len);
	else {
		int part_len = _RING_HISTORY_LEN-this->end-1;
		memcpy (this->ring_buf + this->end + 1, line, part_len);
		memcpy (this->ring_buf, line + part_len, len - part_len);
	}
	this->ring_buf [this->end] = len;
	this->end = this->end + len + 1;
	if (this->end >= _RING_HISTORY_LEN)
		this->end -= _RING_HISTORY_LEN;
	this->ring_buf [this->end] = 0;
	this->cur = 0;
}

void rl_terminal::hist_search (int dir)
{
	int len = ring_hist.hist_restore_line (rl->cmdline, dir);
	if (len >= 0) {
		echo->left(rl->cursor);
		echo->del(rl->cmdlen);
		rl->cursor = rl->cmdlen = len;
		echo->print(rl->get_line());
	}
}


//*****************************************************************************
// copy saved line to 'line' and return size of line
int ring_history_t::hist_restore_line (char * line, int dir)
{
	int cnt = 0;
	// count history record	
	int header = this->begin;
	while (this->ring_buf [header] != 0) {
		header += this->ring_buf [header] + 1;
		if (header >= _RING_HISTORY_LEN)
			header -= _RING_HISTORY_LEN; 
		cnt++;
	}

	if (dir == _HIST_UP) {
		if (cnt >= this->cur) {
			int header = this->begin;
			int j = 0;
			// found record for 'this->cur' index
			while ((this->ring_buf [header] != 0) && (cnt - j -1 != this->cur)) {
				header += this->ring_buf [header] + 1;
				if (header >= _RING_HISTORY_LEN)
					header -= _RING_HISTORY_LEN;
				j++;
			}
			if (this->ring_buf[header]) {
					this->cur++;
				// obtain saved line
				if (this->ring_buf [header] + header < _RING_HISTORY_LEN) {
					memset (line, 0, _COMMAND_LINE_LEN);
					memcpy (line, this->ring_buf + header + 1, this->ring_buf[header]);
				} else {
					int part0 = _RING_HISTORY_LEN - header - 1;
					memset (line, 0, _COMMAND_LINE_LEN);
					memcpy (line, this->ring_buf + header + 1, part0);
					memcpy (line + part0, this->ring_buf, this->ring_buf[header] - part0);
				}
				return this->ring_buf[header];
			}
		}
	} else {
		if (this->cur > 0) {
				this->cur--;
			int header = this->begin;
			int j = 0;

			while ((this->ring_buf [header] != 0) && (cnt - j != this->cur)) {
				header += this->ring_buf [header] + 1;
				if (header >= _RING_HISTORY_LEN)
					header -= _RING_HISTORY_LEN;
				j++;
			}
			if (this->ring_buf [header] + header < _RING_HISTORY_LEN) {
				memcpy (line, this->ring_buf + header + 1, this->ring_buf[header]);
			} else {
				int part0 = _RING_HISTORY_LEN - header - 1;
				memcpy (line, this->ring_buf + header + 1, part0);
				memcpy (line + part0, this->ring_buf, this->ring_buf[header] - part0);
			}
			return this->ring_buf[header];
		} else {
			// empty line 
			return 0;
		}
	}
	return -1;
}
*/

void	rl_terminal::print_prompt()
{
	echo->write(MACHINE_NAME);echo->write(':');
}


/*	
   void	rl_terminal::init(symb_dev* _echo)
	{echo=_echo; mode=0;}
*/
void rl_terminal::execute()
{
strexec(str.c_str());
str.clean();
cur = str.begin_cursor();
};


   size_t	rl_terminal::write(uint8_t c)
	{	
		if ((oldchar=='\n' && c=='\r') || (oldchar=='\r' && c=='\n')) return 0;
		oldchar=c;		
		switch(c)
		{
		case '\b': cur.bs(); break;
		case '\n': 
		case '\r': //ring_hist.hist_save_line (rl->get_line(), rl->cmdlen);
		echo->write('\r');echo->write('\n');execute();print_prompt();break;		
		default:
		cur.write(c); 
		if (echo!=0) echo->write(c);
		}
	}

	#include <genos/message/pair_message.h>
	void rl_terminal::command(pair_message m)
	{
	switch (m.first){
	case CHAR: write(m.second); break;
	case KEYCOM: switch(m.second){
				case LEFT: cur--; break;		
				case RIGHT: cur++;break;
				case UP:break;
				case DOWN:break;
				case ENTER: execute(); break;
				default: break;
				};
				break;
	default: break;
	};	
	};
};