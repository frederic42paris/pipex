SRCS = ./src/arg_number.o ./src/check_infile.o ./src/check_outfile.o ./src/get_loop_start.o ./src/handle_pipe.o\
./src/handle_unlink.o ./src/handle_wait.o ./src/last_exec.o ./src/main.o ./src/open_infile.o \
./src/open_outfile.o ./src/permission_denied.o ./src/pipex_utils.o ./src/store_basic_data.o\
./get_next_line/get_next_line.o ./get_next_line/get_next_line_utils.o\

SRCS_BONUS = ./src_bonus/arg_number_bonus.o ./src_bonus/check_infile_bonus.o ./src_bonus/check_outfile_bonus.o ./src_bonus/get_loop_start_bonus.o ./src_bonus/handle_pipe_bonus.o\
./src_bonus/handle_unlink_bonus.o ./src_bonus/handle_wait_bonus.o ./src_bonus/last_exec_bonus.o ./src_bonus/main_bonus.o ./src_bonus/open_infile_bonus.o \
./src_bonus/open_outfile_bonus.o ./src_bonus/permission_denied_bonus.o ./src_bonus/pipex_utils_bonus.o ./src_bonus/store_basic_data_bonus.o\
./get_next_line/get_next_line.o ./get_next_line/get_next_line_utils.o\

NAME = pipex

all: $(NAME)

$(NAME): $(SRCS)
	make -C ./libft
	make -C ./printf
	cc -Wall -Wextra -Werror -g -o $(NAME) $(SRCS) ./printf/libftprintf.a ./libft/libft.a

%.o:%.c 
	cc -Wall -Wextra -Werror -o $@ -c $<

clean:
	make clean -C ./libft
	make clean -C ./printf
	rm -f $(SRCS)
	rm -f $(SRCS_BONUS)

fclean: clean
	make fclean -C ./libft
	make fclean -C ./printf
	rm -f $(NAME)

re: fclean all

bonus : $(SRCS_BONUS) 
	make -C ./libft
	make -C ./printf
	cc -Wall -Wextra -Werror -o $(NAME) $(SRCS_BONUS) ./printf/libftprintf.a ./libft/libft.a

%.o:%.c 
	cc -Wall -Wextra -Werror -o $@ -c $<

.PHONY: all clean fclean re

# valid:
# multiplevalid: replace
# multiplevalid: replace
# multiplevalid: replace
# outfile_dont_exist: same as valid, just create the file
# incorrect_infile: run all commands except 1st
# noaccessoutfile : run all commands except last
# shellcmdinvalid: clear outfile with message
# infile_outfile_incorrect: run all commands except last and 1st
# infile_incorrect_grep: run all commands except 1st
# shelloptioninvalid: clear outfile with message

VALID_CMD_3 = "grep a2" "grep ciao" "wc -l"
INVALID_CMD_4 = "grepll -n a2" "wcaa -l" "wcbb -l" "wccc -l"
INVALID_OPTION_4 = "grep -ndd a2" "wc -ldd" "wc -laa" "wc -lbb"

VALGRIND = valgrind --track-origins=yes --trace-children=yes --track-fds=yes --leak-check=full
VALGRIND_VALID_CMD_3 = "cat" "cat" "cat"

testbasic:
	./pipex infile $(VALID_CMD_3) test_valid2
	./pipex infile $(VALID_CMD_3) test_valid2
	./pipex infile $(VALID_CMD_3) test_valid2
	./pipex infile $(VALID_CMD_3) test_valid2
	./pipex infile $(VALID_CMD_3) test_outfiledontexist1
	./pipex infiledd "grepll -n a2" "wcaa -l" "wcbb -l" "wccc -l" outfile
	./pipex infile "grepll -n a2" "wcaa -l" "wcbb -l" "wccc -l" test_noaccessoutfile 
	./pipex infile "grepll -n a2" "wcaa -l" "wcbb -l" "wccc -l" test_cmdinvalid1
	./pipex infiledd "grepll -n a2" "wcaa -l" "wcbb -l" "wccc -l" test_noaccessoutfile 
	./pipex infiledd "grepdd -n a2" "grep -n a2" "wcaa -l" "wcbb -l" outfile 
	./pipex infile "grep -ndd a2" "wc -ldd" "wc -laa" "wc -lbb" test_optioninvalid2

testshell:
	< infile grep a2 | grep ciao | wc -l > test_valid1
	< infile grep a2 | grep ciao | wc -l > test_valid1
	< infile grep a2 | grep ciao | wc -l > test_valid1
	< infile grep a2 | grep ciao | wc -l > test_valid1
	< infile grep a2 | grep ciao | wc -l > test_outfiledontexist2
	< infiledd grepdd -n a2 | wcdd -l | wcaa | wcbb -l > outfile
	< infile grepdd -n a2 | wcdd -l | wcaa -l | wcbb -l > test_noaccessoutfile
	< infile grepdd -n a2 | wcdd -l | wcaa | wcbb -l > test_cmdinvalid2
	< infiledd grepdd -n a2 | wcdd -l | wcaa | wcbb -l > test_noaccessoutfile
	< infiledd grepdd -n a2 | grep -n a2 | wcaa | wcbb -l  > outfile
	< infile grep -ndd a2 | wc -ldd | wc -laa | wc -lbb > test_optioninvalid1

valgrind_testbasic:
	$(VALGRIND) ./pipex infile $(VALGRIND_VALID_CMD_3) test_valid2
	$(VALGRIND) ./pipex infile $(VALGRIND_VALID_CMD_3) test_valid2
	$(VALGRIND) ./pipex infile $(VALGRIND_VALID_CMD_3) test_valid2
	$(VALGRIND) ./pipex infile $(VALGRIND_VALID_CMD_3) test_valid2
	$(VALGRIND) ./pipex infile $(VALGRIND_VALID_CMD_3) test_outfiledontexist1
	valgrind --track-origins=yes --trace-children=yes --track-fds=yes --leak-check=full	./pipex infiledd "grepll -n a2" "wcaa -l" "wcbb -l" "wccc -l" outfile
	valgrind --track-origins=yes --trace-children=yes --track-fds=yes --leak-check=full	./pipex infile "grepll -n a2" "wcaa -l" "wcbb -l" "wccc -l" test_noaccessoutfile 
	valgrind --track-origins=yes --trace-children=yes --track-fds=yes --leak-check=full	./pipex infile "grepll -n a2" "wcaa -l" "wcbb -l" "wccc -l" test_cmdinvalid1
	valgrind --track-origins=yes --trace-children=yes --track-fds=yes --leak-check=full	./pipex infiledd "grepll -n a2" "wcaa -l" "wcbb -l" "wccc -l" test_noaccessoutfile 
	valgrind --track-origins=yes --trace-children=yes --track-fds=yes --leak-check=full	./pipex infiledd "grepdd -n a2" "grep -n a2" "wcaa -l" "wcbb -l" outfile 
	valgrind --track-origins=yes --trace-children=yes --track-fds=yes --leak-check=full	./pipex infile "grepll -n a2" "wcaa -l" "wcbb -l" "wccc -l" test_optioninvalid2
	valgrind --track-origins=yes --trace-children=yes --track-fds=yes --leak-check=full env -i ./pipex infile "grepll -n a2" "wcaa -l" "wcbb -l" "wccc -l" test_cmdinvalid1

# valid
# multiple valid : append
# multiple valid : append
# multiple valid : append
# shell cmd invalid

testlimiter:
	./pipex here_doc LIMITER $(VALID_CMD_3) outfile
	./pipex here_doc LIMITER $(VALID_CMD_3) outfile
	./pipex here_doc LIMITER $(VALID_CMD_3) outfile
	./pipex here_doc LIMITER $(VALID_CMD_3) outfile
	./pipex here_doc LIMITER $(INVALID_CMD_4) outfile

testlimitershell:
	grep a2 << LIMITER | grep ciao | wc -l >> outfile
	grep a2 << LIMITER | grep ciao | wc -l >> outfile
	grep a2 << LIMITER | grep ciao | wc -l >> outfile
	grep a2 << LIMITER | grep ciao | wc -l >> outfile
	grepdd a2 << LIMITER | wcdd -l | wcaa | wcbb -l >> outfile

number_arguments:
	./pipex infile "grep a2" outfile