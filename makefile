make: emulator linker assembler

emulator: src/emulator.cpp
	g++ -o $(@) $(^)

linker: src/linker.cpp
	g++ -o $(@) $(^)

assembler: src/parser.cpp src/assembler.cpp src/flex.cpp
	g++ -o $(@) $(^)

src/flex.cpp: misc/flex.l
	flex --outfile=$(@) $(^)

src/parser.cpp: misc/bison.y
	bison -v --defines=inc/parser.hpp --output=$(@) $(^)