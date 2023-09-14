# Suckless mental trainer (smt)

## Introduction
The best tool online to train yourself.
It is a tool to train your memory, mental calculation skills and visualisation skills.

I had the goal of keeping this C project below 3000 LOC.

Tutorials can be found on [sherlly.org](https://sherlly.org)

## Philosophy

This is software aimed towards advance computer users and advanced mental athletes.

It is designed to literally suck less than other brain training apps on the market, both being open source and well written.

While feature rich, it is performant and written in C.

### Features
This program has lots of features designed to help you train for memory competition, arithmetic competitions, blindfold chess and other intelligence events.

A mental trainer with usage smt --mode "mode name" [OPTIONS]
then game options

This will colour code your errors

## Output of smt --help 
Welcome to Sherlly's Mental Trainer. A one of a kind feature rich and efficient tool for all of your mental athletic needs 
smt -m mode -options 
options are -m/--m for mode, -c/--constant_name for constant name, -op/--operation for operation, -a/--amount for amount of data, -l or --length_of_time for length of time (seconds), -e/--explain to explain and -p/--power for setting the powrr 
Full documentation and tutorials can be found at: sherlly.org 
Use config.h as settings 
avaliable modes are: 
-m "numbers" -a amount_of_digits -l length_of_time 
-m "binary" -a amount_of_digits -l length_of_time 
-m "cards" -a amount_of_cards -l length_of_time 
-m "constants" -c constant_name -a amount_of_digits -l length_of_time | (only supports pi, e, phi and c. c being a custom one you define in config.h 
-m countries_quiz 
-m elements_quiz 
-m primes_quiz 
-m day_of_week | -e to pre-calculate codes 
-m calculator -a amount_of_digits -o 'operation' -l length_of_time | supports +, /, *, ^, - 
-m powers -a amount_of_digits -p exponent -l length_of_time 
-m rooting -a amount_of_digits -p exponent | no time limit 
-m knight_tour | -e to pre-calculate codes 
-m blind_knight 
[sherlly@mainframe ~/git/suckless_mental_trainer]$ smt --help 
Welcome to Sherlly's Mental Trainer. A one of a kind feature rich and efficient tool for all of your mental athletic needs 
smt -m mode -options 
options are -m/--m for mode, -c/--constant_name for constant name, -op/--operation for operation, -a/--amount for amount of data, -l or --length_of_time for length of time (seconds), -e/--explain to explain and -p/--power for setting the powrr 
Full documentation and tutorials can be found at: sherlly.org 
Use config.h as settings 
avaliable modes are: 
-m "numbers" -a amount_of_digits -l length_of_time 
-m "binary" -a amount_of_digits -l length_of_time 
-m "cards" -a amount_of_cards -l length_of_time 
-m "constants" -c constant_name -a amount_of_digits -l length_of_time | (only supports pi, e, phi and c. c being a custom one you define in config.h 
-m countries_quiz 
-m elements_quiz 
-m primes_quiz 
-m day_of_week | -e to pre-calculate codes 
-m calculator -a amount_of_digits -o 'operation' -l length_of_time | supports +, /, *, ^, - 
-m powers -a amount_of_digits -p exponent -l length_of_time 
-m rooting -a amount_of_digits -p exponent | no time limit 
-m knight_tour | -e to pre-calculate codes 
-m blind_knight 
-m chess_squares 



# TYPES

memory/airthmetic - Show data for X amount of time, then vanish and quiz, have to answer within certain amount of time
Technical note
array_test(array,chunk_size,time_for_all_data,time_for_testing);


quiz - Have a list not shown, list within a time frame 
array_quiz(array,ordered,time_to_testing);

chess - blindfold chess practice



