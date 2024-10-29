#include "../include/minishell.h"

/* detection
Purpose: Unable/disable meta character detection.
Param:
	c : pass char
	state : reference pointer to &state from parent function
Return:
	0 : Not a quotes
	1 : Double quote detected, ignore YES
	2 : Single quote detected, ignore YES
	3 : Double quote detected, detection ON
	4 : Single quote detected, detection ON
*/

int detection(char c, int *state)
{
	int trigger_no;

	trigger_no = 0;
	if (c == '\"' && *state == ON)           (*state = DQ_OFF,   trigger_no = 1);
	else if (c == '\'' && *state == ON)      (*state = SQ_OFF,   trigger_no = 2);
	else if (c == '\"' && *state == DQ_OFF)  (*state = ON,       trigger_no = 3); 
	else if (c == '\'' && *state == SQ_OFF)  (*state = ON,       trigger_no = 4);
	return (trigger_no);
}