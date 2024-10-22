#ifndef CONSTANT_H
#define CONSTANT_H

//******************************************/

#define TOKEN_SIZE 100
#define BUFFER_SIZE 1024
 
//******************************************/

#define TRUE 1
#define FALSE 0

//******************************************/

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

#define SUB_CHAR 26

//******************************************/

#define ON 0
#define SQ_OFF 1
#define DQ_OFF 2

//******************************************/


#define RESET "\033[0m"
#define RED "\033[1m\033[31m"
#define GREEN "\033[1m\033[32m"

//******************************************/

#endif