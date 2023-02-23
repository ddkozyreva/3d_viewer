CC 				= gcc
CFLAGS			:= # -Wall -Werror -Wextra -g
GCOV_FLAGS 		:= -fprofile-arcs -ftest-coverage
LDFLAGS 		:= -fprofile-arcs --coverage
LIN_FLAGS 		:= -lpthread -pthread -lrt -lm -lsubunit
LCHECK			= -I/opt/homebrew/include  -L/opt/homebrew/lib -lcheck
ifeq ($(shell uname), Linux)
CHECK_FLAGS += $(LIN_FLAGS)
endif
# PROJECT_NAME	= Cal cd $(PROJECT_NAME) &&
PROJECT_FILE 	:= CMakeLists.txt
SOURCES			:= parser/parser.c  aphins/aphins.c
OBJECTS 		:= $(addprefix obj/,$(SOURCES:.c=.o))
OBJECTS_GCOV 	:= $(addprefix obj_gcov/,$(SOURCES:.c=.o))
HEADER			:= parser/parser.h aphins/aphins.h 
OBJ_DIR     	:= obj
OBJ_GCOV_DIR	:= obj_gcov
CHECKMK_FILE	:= 
TEST_EXE		:=test_test.out
LIB_NAME		=s21_viewer.a
TEST_FILE		=parser/test/tests.c
TEXI2HTML		=makeinfo --no-split --html
DOXYFILE		=Dox.texi
DOXHTML			=Dox.html
BUILD_DIR = ${HOME}/build/
SRC_DIR = ${PATH}


all: install 
create_dir:
	@mkdir -p $(OBJ_DIR) $(OBJ_GCOV_DIR)

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $(subst /,_,$@) $(CHECK_FLAGS)
	@mv *.o $(OBJ_DIR)/

$(LIB_NAME): create_dir $(OBJECTS)
	ar rc $@ $(OBJ_DIR)/*.o

$(TEST_FILE):
	@checkmk clean_mode=0 $(TEST_FILE)


tests: $(LIB_NAME) $(TEST_FILE)
	$(CC) $(CFLAGS) $^ -o $(TEST_EXE) $(LCHECK) $(CHECK_FLAGS)
	@./$(TEST_EXE)

dvi: foo.html 

dist:
	tar czf dist.tar  *

foo.html: $(DOXYFILE)
	rm -rf $(DOXHTML)
	$(TEXI2HTML) $(DOXYFILE)
	open $(DOXHTML)

$(OBJ_GCOV_DIR)/%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) $(GCOV_FLAGS) -c $< -o $(subst /,_,$@) $(CHECK_FLAGS)
	mv *.o *gcno $(OBJ_GCOV_DIR)/

libgcov.a: create_dir $(OBJECTS_GCOV)
	ar rcs libgcov.a $(OBJ_GCOV_DIR)/*.o

gcov_report: $(TEST_FILE) $(HEADER) libgcov.a
	$(CC) $(CFLAGS) $^ -o $(TEST_EXE) $(LCHECK) $(LDFLAGS) $(GCOV_FLAGS) $(CHECK_FLAGS)
	./$(TEST_EXE)
	@mv *.gcda *.gcno $(OBJ_GCOV_DIR)
	@rm -f $(OBJ_GCOV_DIR)/*tests*
	lcov -c -d $(OBJ_GCOV_DIR)/. -o $(OBJ_GCOV_DIR)/coverage.info
	genhtml $(OBJ_GCOV_DIR)/coverage.info --output-directory out
	open out/index.html

install:
	mkdir $(BUILD_DIR)
	cmake -S . -B $(BUILD_DIR)
	cmake --build $(BUILD_DIR)

uninstall:
	rm -rf $(BUILD_DIR)

open:
	$(BUILD_DIR)/viewer.app/Contents/MacOS/viewer




main:
	gcc -Wall -Werror -Wextra -g parser/parser.c  aphins/aphins.c -o $(TEST_EXE)
	./$(TEST_EXE)

clean:
	rm -rf obj
	rm -rf obj_gcov
	rm -rf out
	rm -rf *.dSYM
	rm -rf *.a *.out
	rm -rf *.html
	rm -rf *.tar
style: 
	cp ../materials/linters/.clang-format .
	# clang-format -i *.cpp
	clang-format -n *.cpp 
	# clang-format -i *.h
	clang-format -n *.h
	# clang-format -i parser/*.c
	clang-format -n parser/*.c
	# clang-format -i parser/*.h
	clang-format -n parser/*.h
	# clang-format -i aphins/*.c
	clang-format -n aphins/*.c
	# clang-format -i aphins/*.h
	clang-format -n aphins/*.h
	rm .clang-format

