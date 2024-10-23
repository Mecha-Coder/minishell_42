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

#define LONG_INPUT "\n\033[1m\033[31mERROR: " \
                    "\033[0mInput command too long\n"

#define B_SYN_QUOTE "\n\033[1m\033[31mSYNTAX ISSUE: " \
                    "\033[0mQuote must be in pair\n"

#define B_SYN_BRACKET "\n\033[1m\033[31mSYNTAX ISSUE: " \
                    "\033[0mBracket placement issue\n"

#define B_SYN_OPERATOR "\n\033[1m\033[31mSYNTAX ISSUE: " \
                    "\033[0mInvalid operator\n"

#define FAIL_TOKEN "\n\033[1m\033[31mERROR: " \
                    "\033[0mTokenize failed. Command too long\n"

#define A_SYN_REDIRECT "\n\033[1m\033[31mSYNTAX ISSUE: " \
                    "\033[0mRedirect must followed by string\n"

#define A_SYN_OPERATOR "\n\033[1m\033[31mSYNTAX ISSUE: " \
                    "\033[0mOperator must be between commands\n"

#define A_SYN_BRACKET "\n\033[1m\033[31mSYNTAX ISSUE: " \
                    "\033[0mBracket placement issue\n"
                    
#define FAIL_AST "\n\033[1m\033[31mERROR: " \
                    "\033[0mFailed to build AST\n"

#define FAIL_SWAP "\n\033[1m\033[31mERROR: " \
                    "\033[0mFailed to execute. Can't tranform:\n"

//******************************************************/

#define OR 0     // ||
#define PIPE 1   // |
#define HERE 2   // <<
#define RD 3     // <
#define APPD 4   // >>
#define WR 5     // >
#define AND 6    // &&
#define OB 7     // (
#define CB 8     // )
#define STR 9   // Others

#define CMD 10   // Group of <STR> 
#define SUB 11   // Sub-shell

//******************************************/

#endif