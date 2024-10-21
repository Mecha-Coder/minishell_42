#ifndef CONSTANT_H
#define CONSTANT_H

//******************************************************/

#define BUFFER_SIZE 1024
#define CMD_SIZE 100
#define OPEN_FD_SIZE 10
 
//******************************************************/

#define TRUE 1
#define FALSE 0

//******************************************************/

#define ON 0
#define SQ_OFF 1
#define DQ_OFF 2

//******************************************************/

#define RESET "\033[0m"
#define RED "\033[1m\033[31m"
#define GREEN "\033[1m\033[32m"

//******************************************************/

#define LONG_INPUT "\033[1m\033[31mERROR: " \
                    "\033[0mInput command too long\n"

#define B_SYN_QUOTE "\033[1m\033[31mSYNTAX ISSUE: " \
                    "\033[0mQuote must be in pair\n"

#define B_SYN_BRACKET "\033[1m\033[31mSYNTAX ISSUE: " \
                    "\033[0mBracket placement issue\n"

#define B_SYN_OPERATOR "\033[1m\033[31mSYNTAX ISSUE: " \
                    "\033[0mInvalid operator\n"

//******************************************************/

#endif