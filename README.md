# Suckless mental trainer

## Introduction
A suckless style mental trainer. Probably more bloated in features than other suckless software however I have been unable to find any satisficatory mental training software and wished to make my own.

### Features
This program has lots of features designed to help you train for memory competition, arithmetic competitions, blindfold chess and other intelligence events.

A mental trainer with usage ./mental_trainer --mode
then game options

This will colour code your errors


## Memory training
### Numbers
./memory_trainer --numbers amount_of_digits length_of_time

### Cards
./memory_trainer --numbers amount_of_cards length_of_time

### constants (such as pi, e)
./memory_trainer --constants "constant_name" amount_of_digits

This will ask you to input that many digits then compare at the end.

it is shipped with

1000 digits of e

1000 digits of pi

1000 digits of phi (golden ratio)

And a custom one you can change in config.h, you get get your custom number by using
./memory_trainer --constants "c" amount_of_digits

### General Knowledge
./memory_trainer --knowledge "name_of_list"

currently only supports countries, UK cities and perodic table

## Human calculator training
### Day of the week for any date calculation
./memory_trainer --day_of_week
optional -e to explain the different codes as you go

Full tutorial can be found here: https://sherlly.org/memory_cont/doad

### Lightning calculation
./memory_trainer --calculator max_length_of_numbers operation length_of_time

example:
./memory_trainer --calculator 7 + 3

12345 + 9182734


the only valid operations are: +, /, *, ^, -

### powers
./memory_trainer --powers max_length_of_numbers base_to_raise_to length_of_time


## Visualtion practice

### Blindfold Knight games
./memory_trainer --blind_knight
### Blindfold Knights tour
./memory_trainer --knight_tour
### Colours of each square
./memory_trainer --chess_squares

## Studying
### flashcard app
todo()!
