# Suckless mental trainer (smt)

## Introduction
A suckless style mental trainer. Probably more bloated in features than other suckless software however I have been unable to find any satisficatory mental training software and wished to make my own.

It is a tool to train your memory, mental calculation skills and visualisation skills.

I had the goal of keeping this C project below 2000 LOC.

Tutorials can be found on [sherlly.org](https://sherlly.org)

## Philosophy

This is software aimed towards advance computer users and advanced mental athletes.

It is designed to literally suck less than other brain training apps on the market, both being open source and well written.

While feature rich, it is performant and written in C.

### Features
This program has lots of features designed to help you train for memory competition, arithmetic competitions, blindfold chess and other intelligence events.

A mental trainer with usage smt --mode
then game options

This will colour code your errors


## Memory training
### Numbers
smt --numbers amount_of_digits length_of_time

### Binary
smt --binary amount_of_digits length_of_time

### Cards
smt --cards amount_of_cards length_of_time

### constants (such as pi, e)
smt --constants "constant_name" amount_of_digits

This will ask you to input that many digits then compare at the end.

it is shipped with

1000 digits of e

1000 digits of pi

1000 digits of phi (golden ratio)

And a custom one you can change in config.h, you get get your custom number by using
smt --constants "c" amount_of_digits

### Countries quiz
smt --countries_quiz

You type in all the countries in the world, it'll show you the captial for each before ticking it off the list. Once you've done all the countries, it'll say well done.

### Elements quiz
smt --elements_quiz

You type in all the elements in the periodic table, it'll show you the atomic mass and atomic number for each before ticking it off the list. Once you've done all the elements, it'll say well done.

### primes quiz
smt --primes_quiz

You type in all the primes up to 1000, once done it'll say well done.

### states quiz
smt --states_quiz

You type in all the us states, once done it'll say well done.

### uk cities quiz
smt --cities_quiz

You type in all the uk cities, once done it'll say well done.

## Human calculator training
### Day of the week for any date calculation
smt --day_of_week
optional -e to explain the different codes as you go

Full tutorial can be found here: https://sherlly.org/memory_cont/doad

### Lightning calculation
smt --calculator max_length_of_numbers operation length_of_time

example:
smt --calculator 7 + 3

12345 + 9182734


the only valid operations are: +, /, *, ^, -

### powers
smt --powers max_length_of_numbers base_to_raise_to length_of_time


## Visualtion practice

### Blindfold Knight games
smt --blind_knight
### Blindfold Knights tour
smt --knight_tour
### Colours of each square
smt --chess_squares


