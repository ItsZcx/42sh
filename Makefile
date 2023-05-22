##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## makefile
##

# Compilation flags
_TEST_FLAGS1_ = -I ./include/ -I ./lib/my/include/
_TEST_FLAGS2_ = -L ./.obj -lmy --coverage -lcriterion

# Directories
_DIRS1_ = ./src/*.c ./src/cmd/*.c ./src/tree/*.c ./src/parsing/*.c
_DIRS2_ = ./src/others/*.c ./src/operators/*.c ./src/builtins/cd/*.c
_DIRS3_ = ./src/builtins/env/*.c ./src/builtins/exit/*.c ./src/builtins/echo/*.c ./lib/*.c
_DIRS4_ = ./src/builtins/alias/*.c ./src/builtins/history/*.c ./src/builtins/variables/*.c ./src/builtins/which_where/*.c

# Colours
_GREEN_ = \033[1;32m
_CYAN_ = \033[1;36m
_BLUE_ = \033[94m
_DEFAULT_ = \033[0m

all:
	make -C lib/
	make -C src/

clean:
	make clean -C lib/
	make clean -C src/
	rm -rf diff.txt
	rm -rf unit_test-42sh_tests.gcda
	rm -rf unit_test-42sh_tests.gcno
	rm -rf coding-style-reports.log

quiet_clean:
	@rm -rf diff.txt
	@rm -rf unit_test-42sh_tests.gcda
	@rm -rf unit_test-42sh_tests.gcno
	@rm -rf coding-style-reports.log

fclean: clean
	make fclean -C lib/
	make fclean -C src/
	rm -rf .obj
	rm -rf unit_test
	rm -rf ./*.o

re:			fclean all

tests_run: build_objects quiet_clean
	@rm -rf ./.obj/*.o
	@gcc -o unit_test tests/42sh_tests.c $(_TEST_FLAGS1_) $(_TEST_FLAGS2_)
	@echo "$(_GREEN_)Unit Tests:$(_DEFAULT_)"
	@./unit_test -j1
	@gcovr --exclude ./tests

build_objects:
	@echo "$(_BLUE_)Building objects...$(_DEFAULT_)"
	@mkdir -p .obj
	@rm -rf ./.obj/*
	@gcc -c $(_TEST_FLAGS1_) $(_DIRS1_) $(_DIRS2_) $(_DIRS3_) $(_DIRS4_)
	@mv ./*.o ./.obj
	@rm ./.obj/main.o
	@ar rc ./.obj/libmy.a .obj/*.o
	@echo "$(_CYAN_)Success\n$(_DEFAULT_)"
