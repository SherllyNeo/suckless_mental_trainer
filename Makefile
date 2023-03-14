mental_trainer: mental_trainer.c config.h games.h day_of_any_date.c doad_calc.h doad_calc.c cards.c constants.c calculation.c blind_knight.c knights_tour.c chess.c squares.c powers.c
	$(CC) mental_trainer.c config.h games.h doad_calc.h -g -std=gnu99 -o mental_trainer -lm
install:
	cp -f mental_trainer /usr/local/bin
