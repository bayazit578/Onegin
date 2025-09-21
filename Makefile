CFLAGS= -DTX_COMPILED -Wall -Wextra -I. -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal\
-Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++\
-Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body\
-Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers -Wnon-virtual-dtor\
-Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel\
-Wtype-limits -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE

program : main.o comparator.o create_of_ptr.o fileworks.o funcs.o sorts.o supportive.o
	g++ ${CFLAGS} main.o comparator.o create_of_ptr.o fileworks.o funcs.o sorts.o supportive.o -o program

run: program
	./program

%.o : %.cpp
	g++ ${CFLAGS} -c $< -MMD -MF $*.d -o $@

-include *.d

clean :
	rm program.exe *.o *.d
