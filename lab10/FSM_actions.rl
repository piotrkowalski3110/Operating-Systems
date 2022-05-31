%%{

machine FSM;

action accept_Imie { res = 'I'; }
action accept_Nazwisko { res = 'N'; }
action accept_Album { res = 'A'; }
action not_accept { res = 0; }

include "FSM.rl";

}%%


#include <stdio.h>
#include <string.h>

%% write data;

int parse(char* string)
{
  int cs;
  int res=0;
  char *p, *pe;

  p = string;
  pe = p + strlen(string);

  %% write init;
  %% write exec;

  return res;
}

