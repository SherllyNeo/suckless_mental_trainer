smt: mental_trainer.c config.h games.h day_of_any_date.c doad_calc.h doad_calc.c cards.c constants.c calculation.c blind_knight.c knights_tour.c chess.c squares.c powers.c countries.c flashcards.c elements.c primes.c cities.c states.c binary.c
	$(CC) mental_trainer.c config.h games.h doad_calc.h -g -std=gnu11 -o smt -lm
install:
	cp -f smt /usr/local/bin
clean:
	$(CC) mental_trainer.c config.h games.h doad_calc.h -g -std=gnu11 -o smt -lm && rm vg*
