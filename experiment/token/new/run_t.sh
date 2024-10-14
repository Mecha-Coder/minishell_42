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

run_builtin_test() {
    echo -e "\n\n${YELLOW}========================= BUILT-IN ===========================${NC}\n\n"

    echo -e "${YELLOW}\na) echo  (like printf)${NC}\n"
    run_command "echo"
    run_command "echo -n"
    run_command "echo -n hi"
    run_command "echo -n      \"Hi\""
    run_command "echo   -n   \"Hello \$USER\" ', nice day;)'"
    run_command "echo 'Hi \$\$'"
    run_command "echo '[Hello \"World\"]'"
    run_command "   echo  \"[Hello 'World'']\""
    run_command "echo \"Hello \$USER lol \" -n \"\$SHELL\""
    run_command "echo \"EE"
    run_command "echo hello        world ls echo"
    run_command "echo \"Hello               world ls\" go"
    run_command "echo -nnnn Hello World"
    run_command "echo -n -n -nnnn -nnnnm"
    run_command "echo hi\";\" hihi"

    echo -e "${YELLOW}\nb) exit  (shutdown minishell)\n${NC}"
    run_command "exit"
    run_command "exit -n"
    run_command "echo hi && exit 0"
    run_command "ls | exit"
    run_command "exit 0 | exit 1"
    run_command "exit 0 5 hello \"\$SHELL\""
    run_command "echo hi && exit 55 70"

    echo -e "${YELLOW}\nc) cd (change dir)\n${NC}"
    run_command "cd"
    run_command "cd ."
    run_command "cd \"../../xxx\""
    run_command "mkdir new_dir && cd 'new_dir'"
    run_command "cd ./xxx/xxx"
    run_command "cd xxx"
    run_command "cd /usr/bin ./yyy"
    run_command "cd /usr/bin"

    echo -e "${YELLOW}\nd) env - get from minishell env struct\n${NC}"
    run_command "env"
    run_command "env a b c"

    echo -e "${YELLOW}\ne) export (add key & value to env struct)\n${NC}"
    run_command "export"
    run_command "export TEST=test"
    run_command "export TEST='[test]'"
    run_command "export TEST=\"['test']\""
    run_command "export TEST=\"['test' \$SHELL]\""
    run_command "export VAR = \"Hello\""
    run_command "export VAR=yoyo TEST=dada"
    run_command "export \"\" et unset \"\""
    run_command "export \"test=ici\"=coucou"

    echo -e "${YELLOW}\nf) unset (remove from env struct)\n${NC}"
    run_command "unset VAR=Hello"
    run_command "unset VAR"
    run_command "unset VAR TEST"
}

run_quotes_test() {
    echo -e "\n\n${YELLOW}========================= QUOTES ===========================${NC}\n\n"

    echo -e "${YELLOW}\na) Double quote (meta characters meaning inside \" \" is negated except \$)${NC}\n"
    run_command "echo \"[Path \$SHELL  '  ' && !]\""
    run_command "echo \"[Path \$SHELL\$]\""
    run_command "echo \"[Test \'still\' valid \$USER]\""
    run_command "echo \"Double quote: \"\""
    run_command "echo \"Path: /usr/local/bin\""
    run_command "echo \"It's a beautiful day\""
    run_command "echo \"Exit status: \$?\""
    run_command "echo \"a\"s\"f\"g\"h\""
    run_command "echo \"Done'\" '"

    echo -e "${YELLOW}\nb) Single quote (meta characters meaning inside \" \" is negated)\n${NC} "
    run_command "echo '[Path \$SHELL \"  \" && !]'"
    run_command "echo '\$USER'"
    run_command "echo 'Hello World'"
    run_command "echo 'Single quote: \''"
    run_command "echo 'Exit status: \$?'"
    run_command "echo 'a's'f'f'g'h"
    run_command "echo 'Done\"' \""
}

run_variable_test() {
    echo -e "\n\n${YELLOW}========================= ENV VARIABLE ===========================${NC}\n\n"

    run_command "echo \$USER"
    run_command "echo \$"
    run_command "echo \"\$USER\""
    run_command "echo \$USER"
    run_command "echo \$HOME\$"
    run_command "echo \$PATH"
    run_command "echo \$SHELL"
    run_command "echo \$PWD"
    run_command "echo \$~"
    run_command "echo \"\$\""
    run_command "echo \"\$aa\""
    run_command "echo \$SHELL\$HOME"
    run_command "echo bonjour > \$TEST.txt"
}

run_general_cmd_test() {
    echo -e "\n\n${YELLOW}========================= GENERAL COMMAND ===========================${NC}\n\n"

    echo -e "${YELLOW}\na) Command /w absolute | relative | no path${NC}\n"
    run_command "/usr/bin/ls"
    run_command "/bin/ls"
    run_command "ls"

    echo -e "${YELLOW}\nb) Command + argument${NC}\n"
    run_command "/usr/bin/ls -l"
    run_command "ls -l"
    run_command "wc -c"

    echo -e "${YELLOW}\nc) Invalid command${NC}\n"
    run_command "\"  \""
    run_command "\"\""
    run_command ""
    run_command "[space] \t \r"
    run_command "dsbksdgbksdghsd"
    run_command "Hello 'World'"

    echo -e "${YELLOW}\nd) Unset \$PATH (Only cmd /w absolute path can work${NC}\n"
    run_command "cat"
    run_command "ls"
    run_command "wc"
    run_command "/usr/bin/ls"

    echo -e "${YELLOW}\ne) Export \$PATH=dir1:dir2 (Working again)${NC}\n"
    run_command "cat"
}

run_pipe_test() {
    echo -e "\n\n${YELLOW}========================= PIPE ===========================${NC}\n\n"

    run_command "echo \"Hello there\" | grep \"e\""
    run_command "cat file.txt | wc -l"
    run_command "echo \"Hello World\" | tr 'a-z' 'A-Z'"
    run_command "ps aux | grep \"bash\""
    run_command "cat eval.h | cat | cat | ls"
    run_command "cat eval.h | cat | |cat | ls"
}

run_redirect_test() {
    echo -e "\n\n${YELLOW}========================= REDIRECT ===========================${NC}\n\n"

    echo -e "${YELLOW}\na) < (read file)${NC}\n"
    run_command "/usr/bin/ls"
    run_command "< in1.txt"
    run_command "cat < in1.txt"
    run_command "< in1.txt cat"
    run_command "cat < in1.c < in2.c"
    run_command "< in1.c < in2.c cat"
    run_command "cat < <"
    run_command "cat < in1.txt < in2.txt < in3.txt"
    run_command "< in1.txt cat < in2.txt"


    echo -e "${YELLOW}\nb) << (read from stdin until delimiter)${NC}\n"
    run_command "<< EOF"
    run_command "cat << EOF"
    run_command "<< EOF cat "
    run_command "cat << EOF < in.txt"
    run_command "< in.txt << EOF cat"
    run_command "< in.txt << EOF cat"
    run_command "< nonexist.txt << EOF cat"
    run_command "cat << Hello << EOF < in.txt"
    run_command "cat << Hello < in.txt << EOF "
    run_command "<< Hello << EOF cat"


    echo -e "${YELLOW}\nc) > (write file /w overwrite mode)${NC}\n"
    run_command "> out.txt"
    run_command "ls out.txt >"
    run_command "ls > out.txt"
    run_command "echo \"Hello World\" > out.txt"
    run_command "echo bonjour > test 1"
    run_command "echo bonjour > > out"
    run_command "> out.txt ls"
    run_command "> out1.txt echo Hello > out2.txt there "
    run_command "> in1.txt | ls"


    echo -e "${YELLOW}\nd) >> (write fille /w append mode)${NC}\n"
    run_command ">> out.txt"
    run_command "ls out.txt >>"
    run_command "ls >> out.txt"
    run_command ">> out.txt ls"
    run_command ">>  out1.txt  >>  out2.txt  >  out3.txt ls "
    run_command "ls  >>  out1.txt  >  out2.txt  >>  out3.txt "
    run_command "echo bonjour  >>>  test"
    run_command "echo bonjour  h>>  test"
    run_command "echo bonjour  h  >>out.txt"


    echo -e "${YELLOW}\ne) Mix${NC}\n"
    run_command "cat << EOF > out.txt"
    run_command "< nonexit.txt ls | wc -c > out.txt"
    run_command "ls -l < in.txt | wc -c > out.txt"
    run_command "< /dev/stdin cat | head -1 > out.txt"
    run_command "cat << EOF | wc -l > out.txt"
    run_command "<< EOF cat | wc -l > out.txt"
    run_command "cat in.txt << EOF > out1.txt >> out2.txt"
    run_command "> out1.txt cat > out.txt < in.txt"
    run_command "echo 2 >> out1 > out2"
    run_command "echo 2 > out1 >> out2"
    run_command "cat > out.txt | wc -l < in.txt"
    run_command "> out.txt cat in.txt | wc -l"
    run_command "> out1.txt echo \">>>>> out.txt\" < in.txt"

}

run_error_check_test() {
    echo -e "\n\n${YELLOW}========================= HANDLE ERROR ===========================${NC}\n\n"

    echo -e "${YELLOW}\na) Random${NC}\n"
    run_command "echo \"hi\"; echo hello"
    run_command "echo \$((3+ 5))"
    run_command "echo \\"-laa\\" test"
    run_command "cd ~"
    run_command " ls -l | (grep ic)"
    run_command "Echo"
    run_command "asdghjkbjkfldsbjak lfdsanko && dasghjgdshkf  "
    run_command "                                                                           "
    run_command "                                                                              ls"
    run_command "echo njk;dsfajkdfshjkkl;hdaskf kajdsfkfsdahjas"


    echo -e "${YELLOW}\nb) Continuous stream - urandom${NC}\n"
    run_command "cat /dev/random | head -n 1 | cat -e"
    run_command "< /dev/random cat  | head -n 1 | cat -e"


    echo -e "${YELLOW}\nc) Run other executable${NC}\n"
    run_command "./a.out"
    run_command "./minishell"


    echo -e "${YELLOW}\nd) Incorrect operator syntax${NC}\n"
    run_command "echo hello && && echo hi"
    run_command "echo hello &&& echo hi"
    run_command "echo hello & (echo done)"
    run_command "ls | | wc -l "
    run_command "cat XXX ||| echo ok || echo  done"
    run_command "cat < in.txt <"
    run_command "cat < < in.txt"
    run_command "ls >>> in.txt"
    run_command "| ls | wc -l > > out.txt"
    run_command " cat >> | cat"


    echo -e "${YELLOW}\ne) $ extreme${NC}\n"
    run_command "echo \$\$\$\$#\$USER\$0"
    run_command "\$!!\$Holo"


    echo -e "${YELLOW}\nf) Quote not even quantity${NC}\n"
    run_command "echo \"  \"  \" \"great day\" "
    run_command "echo \"  \"   \"great day\" "


    echo -e "${YELLOW}\nf) No space between command${NC}\n"
    run_command "cat in.txt <<EOF>out1.txt>>out2.txt"
    run_command "cat|cat|cat|cat>out.txt<in.txt>err.txt"


    echo -e "${YELLOW}\ng) Wrong bracket position and count${NC}\n"
    run_command "() && echo done ()"
    run_command "() && (                   )"
    run_command "( echo hello ) && (( echo hi  )  "
    run_command ") ) echo hello ( ( || cat"
    run_command "()"
    run_command "(echo 5) > out.txt"
    run_command "(echo 5) 6"
}

run_exit_status_test() {
    echo -e "\n\n${YELLOW}========================= EXIT STATUS ===========================${NC}\n\n"


    run_command "cat --> echo \$?"
    run_command "\$? + \$? --> echo \$? + \$?"
    run_command "echo \"Hello\" --> echo \$?"
    run_command "rm non_existent_file ||  echo \"Exit staus: \$?\" && echo \"Exit staus: \$?\""
}

run_and_or_test() {
    echo -e "\n\n${YELLOW}========================= || and && ===========================${NC}\n\n"

    echo -e "${YELLOW}\na) AND operator${NC}\n"
    run_command "echo hello && ls"
    run_command "mkdir new_dir && cd new_dir"
    run_command "touch file.txt && echo \"Hello\" > out.txt"
    run_command "ls && echo \"Listed files\""
    run_command "grep \"pattern\" file.txt && echo \"Pattern found\""
    run_command "rm file.txt && echo \"File removed\""
    run_command "cat < in.txt && ls"
    run_command "cd ../../../../ && pwd"
    run_command "pwd && (mkdir new && cd new) && pwd && rmdir new"
    run_command "(echo \"World\" && (echo \"Hello\"))"
    run_command "(export a=10 && echo \$a) && echo \$a"
    run_command "pwd && (cd ../ && pwd) && pwd"
    run_command "ls -l && (echo hello && echo nice to meet you)"
    run_command "(ls -l && (echo hello && echo nice to meet you))"
    run_command "env | grep SHLVL && (env | grep SHLVL)"


    echo -e "${YELLOW}\nb) OR operator${NC}\n"
    run_command "cat || ls"
    run_command "cd random/hah || echo \"Invalid path\""
    run_command "grep \"pattern\" file.txt || echo \"Pattern not found\""
    run_command "rm file.txt || echo \"File not found\""
    run_command "touch file.txt || echo \"Failed to create file\""
    run_command "grep \"pattern\" file.txt || echo \"Not found\""


    echo -e "${YELLOW}\nc) Mix && and || ${NC}\n"
    run_command "pwd || rm xx  && echo done1  || echo done2"
    run_command "mkdir new_dir || echo \"Directory exists\" && rmdir new_dir"
    run_command "touch file.txt ||  | echo \"Failed to create file\""
    run_command "touch file.txt &&& echo \"Failed to create file\""
    run_command "touch file.txt &&"
    run_command "touch & file.txt"
    run_command "&& touch file.txt"
    
}

run_wildcard_test() {
    echo -e "\n\n${YELLOW}========================= WILDCARD * ===========================${NC}\n\n"

    run_command "find . -type f -name \"*.c\""
    run_command "rm *.txt"
    run_command "ls *"
    run_command "echo *"
    run_command "echo Makef*"
    run_command "echo *a"
    run_command "echo * *"
    run_command "echo **"
    run_command "echo filena*"
    run_command "echo .*"
    run_command "cd /usr/*b/ && pwd"
    run_command "cd /usr/*b*4/ && pwd"
    run_command "cd /usr/*b*/ && pwd"
    run_command "export TEST=* && echo \$TEST"
    run_command "export *=no"
    run_command "echo XX*X*"
    run_command "env *"
    run_command "pwd *"
    run_command "exit *"
}

run_mix_test() {
    echo -e "\n\n${YELLOW}========================= MIX ===========================${NC}\n\n"

    run_command "echo \"cat lol.c | cat > lol.c\""
    run_command "ls | grep \"pattern\" > result.txt"
    run_command "cat < file.txt | wc -l"
    run_command "echo \"Hello\" > file.txt && cat file.txt"
    run_command "echo \"Hello\" && echo \"World\" || echo \"Failed\""
    run_command "(ls && echo \"Listed\") || echo \"Failed\""
    run_command "< main.c < a.c cat && cat < main.c"
    run_command "echo hi || ls && echo world"
    run_command "echo hi || ls && danjasjdakj || echo world"
    run_command "echo hi || ls && echo success || echo world"
    run_command "< in.txt ls -l | wc -l"
    run_command "< .in.txt grep all | sort | uniq"
    run_command "< ./file/in.txt ls | cat | cat | cat | cat | cat"
    run_command "cat in1.txt | cat | cat | cat > out.txt < in2.txt > err.txt"
    run_command " cat in.txt | cat | cat > out.txt | cat >> out.txt > err.txt"
    run_command "export TRY=out.txt && cat in.txt | cat  > \$TRY"
    run_command "< in.txt echo > out.txt there"
    run_command "l's'"
    run_command "l''s'"
    run_command "e''c''h''o' 'h''i'"
    run_command "export a=\"ho hi\" --> ec\$a"
    run_command "e'\"c\"'h''o' 'h''i'"
    run_command "export TRY=c && 'e'\"\$TRY\"'h''o' 'h''i'"
}

# Run the tests
# run_builtin_test
# run_quotes_test
# run_variable_test
# run_general_cmd_test
# run_pipe_test
# run_redirect_test
# run_error_check_test
# run_exit_status_test
# run_and_or_test
# run_wildcard_test
run_mix_test