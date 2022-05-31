
/* #line 1 "FSM_actions.rl" */

/* #line 12 "FSM_actions.rl" */



#include <stdio.h>
#include <string.h>


/* #line 13 "FSM_actions.c" */
static const char _FSM_actions[] = {
	0, 1, 0, 1, 1, 1, 2, 1, 
	3
};

static const char _FSM_key_offsets[] = {
	0, 0, 1, 4, 6, 8, 10
};

static const char _FSM_trans_keys[] = {
	58, 65, 73, 78, 48, 57, 90, 97, 
	90, 97, 0
};

static const char _FSM_single_lengths[] = {
	0, 1, 3, 0, 0, 0, 0
};

static const char _FSM_range_lengths[] = {
	0, 0, 0, 1, 1, 1, 0
};

static const char _FSM_index_offsets[] = {
	0, 0, 2, 6, 8, 10, 12
};

static const char _FSM_trans_targs[] = {
	2, 0, 3, 4, 5, 0, 6, 0, 
	6, 0, 6, 0, 0, 0
};

static const char _FSM_trans_actions[] = {
	7, 0, 7, 7, 7, 0, 5, 0, 
	1, 0, 3, 0, 0, 0
};

static const int FSM_start = 1;
static const int FSM_first_final = 6;
static const int FSM_error = 0;

static const int FSM_en_main = 1;


/* #line 19 "FSM_actions.rl" */

int parse(char* string)
{
  int cs;
  int res=0;
  char *p, *pe;

  p = string;
  pe = p + strlen(string);

  
/* #line 69 "FSM_actions.c" */
	{
	cs = FSM_start;
	}

/* #line 30 "FSM_actions.rl" */
  
/* #line 76 "FSM_actions.c" */
	{
	int _klen;
	unsigned int _trans;
	const char *_acts;
	unsigned int _nacts;
	const char *_keys;

	if ( p == pe )
		goto _test_eof;
	if ( cs == 0 )
		goto _out;
_resume:
	_keys = _FSM_trans_keys + _FSM_key_offsets[cs];
	_trans = _FSM_index_offsets[cs];

	_klen = _FSM_single_lengths[cs];
	if ( _klen > 0 ) {
		const char *_lower = _keys;
		const char *_mid;
		const char *_upper = _keys + _klen - 1;
		while (1) {
			if ( _upper < _lower )
				break;

			_mid = _lower + ((_upper-_lower) >> 1);
			if ( (*p) < *_mid )
				_upper = _mid - 1;
			else if ( (*p) > *_mid )
				_lower = _mid + 1;
			else {
				_trans += (unsigned int)(_mid - _keys);
				goto _match;
			}
		}
		_keys += _klen;
		_trans += _klen;
	}

	_klen = _FSM_range_lengths[cs];
	if ( _klen > 0 ) {
		const char *_lower = _keys;
		const char *_mid;
		const char *_upper = _keys + (_klen<<1) - 2;
		while (1) {
			if ( _upper < _lower )
				break;

			_mid = _lower + (((_upper-_lower) >> 1) & ~1);
			if ( (*p) < _mid[0] )
				_upper = _mid - 2;
			else if ( (*p) > _mid[1] )
				_lower = _mid + 2;
			else {
				_trans += (unsigned int)((_mid - _keys)>>1);
				goto _match;
			}
		}
		_trans += _klen;
	}

_match:
	cs = _FSM_trans_targs[_trans];

	if ( _FSM_trans_actions[_trans] == 0 )
		goto _again;

	_acts = _FSM_actions + _FSM_trans_actions[_trans];
	_nacts = (unsigned int) *_acts++;
	while ( _nacts-- > 0 )
	{
		switch ( *_acts++ )
		{
	case 0:
/* #line 5 "FSM_actions.rl" */
	{ res = 'I'; }
	break;
	case 1:
/* #line 6 "FSM_actions.rl" */
	{ res = 'N'; }
	break;
	case 2:
/* #line 7 "FSM_actions.rl" */
	{ res = 'A'; }
	break;
	case 3:
/* #line 8 "FSM_actions.rl" */
	{ res = 0; }
	break;
/* #line 165 "FSM_actions.c" */
		}
	}

_again:
	if ( cs == 0 )
		goto _out;
	if ( ++p != pe )
		goto _resume;
	_test_eof: {}
	_out: {}
	}

/* #line 31 "FSM_actions.rl" */

  return res;
}

