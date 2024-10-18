#!/bin/bash

GREEN="\033[0;32m"
RED="\033[0;31m"
YELLOW="\033[0;33m"
NC="\033[0m" # No Color

run_command() {
     valgrind -q --leak-check=full --error-exitcode=1 ./a.out "$1"
    if [ $? -eq 0 ]; then
        echo -e "${GREEN}OK${NC}"
    else
        echo -e "${RED}KO${NC}"
    fi
    echo -e "${GREEN}--------------------------------------------------------------------${NC}"
}

run_swap() {
    echo -e "\n\n${YELLOW}========================= SWAP TEST ===========================${NC}\n\n"

    run_command "echo   -n   \"Hello \$USER\" ', nice day;)'"
    run_command "echo \"Hello \$USER lol \" -n \"\$SHELL\""
    run_command "echo 'Hi \$\$'"
    run_command "echo \"[Path \$SHELL  ' \$SHELL ' && !]\""
    run_command "echo \"[Path \$SHELL\$]\""
    run_command "echo \"[Test \'still\' valid \$USER]\""
    run_command "echo \"Exit status: \$?\""
    run_command "echo \"a\"s\"f\"g\"h\""
    run_command "echo '[Path \$SHELL \"  \" && !]'"
    run_command "echo '\$USER'"
    run_command "echo 'Hello World'"
    run_command "echo 'Exit status: \$?'"
    run_command "echo 'a's'f'f'g'h"
    run_command "echo \$"
    run_command "echo \$HOME\$_A55"
    run_command "echo \$~"
    run_command "Hi \"there\$USER\$?next\""
    run_command "Hi \"there\$USER next\""
    run_command "Hi \"there\$USERnext\""
    run_command "echo there\$USER\$!loo"
    run_command "echo bonjour > \$TEST"
    run_command "echo \$\$\$\$#\$USER\$0lolol"
    run_command "echo '\"\$USER\"'  \"'\$USER'\""
}

# Run the tests
run_swap