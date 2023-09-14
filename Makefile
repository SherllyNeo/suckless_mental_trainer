src=src
binary_dir=bin
cc=gcc


smt: $(src)/main.c $(src)/config.h $(src)/games.h $(src)/day_of_any_date.c $(src)/doad_calc.h $(src)/doad_calc.c $(src)/cards.c $(src)/constants.c $(src)/calculation.c $(src)/blind_knight.c $(src)/knights_tour.c $(src)/chess.c $(src)/squares.c $(src)/powers.c $(src)/countries.c $(src)/elements.c $(src)/primes.c $(src)/cities.c $(src)/states.c $(src)/binary.c $(src)/rooting.c
	$(CC) $(src)/main.c -g -std=gnu11 -o $(binary_dir)/smt -lm
install:
	cp -f smt /usr/local/bin
clean:
	$(CC) $(src)/main.c -g -std=gnu11 -o $(binary_dir)/smt -lm && rm vg*
web:
	emcc $(src)/main.c -g -std=gnu11 -o $(binary_dir)/web/smt.html -lm 

gui: $(src)/main.c $(src)/config.h $(src)/games.h $(src)/day_of_any_date.c $(src)/doad_calc.h $(src)/doad_calc.c $(src)/cards.c $(src)/constants.c $(src)/calculation.c $(src)/blind_knight.c $(src)/knights_tour.c $(src)/chess.c $(src)/squares.c $(src)/powers.c $(src)/countries.c $(src)/elements.c $(src)/primes.c $(src)/cities.c $(src)/states.c $(src)/binary.c $(src)/rooting.c $(src)/gui_parser.h $(src)/gui_parser.c
	$(CC) $(src)/main_gui.c -g -std=gnu11 -o $(binary_dir)/smt_gui -lm -lraylib
