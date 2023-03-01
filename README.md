# Concept Scripts

Scripts in this repository may be shared under the terms of [Attribution 4.0 International (CC BY 4.0)] (https://creativecommons.org/licenses/by/4.0/). Please note the attribution requirement, as long as this is met any of these scripts may be used without any other restriction.

These are primarily intended as example scripts, both in terms of computing concepts and as small examples of my work in different languages etc.

## Binary Search Cat 
`Binary Search cat.sb3` is a scratch program with a cat, that will guess an integer of your choice between 1 and 100 using the binary search algorithm. This requires Scratch to run. See https://scratch.mit.edu/ to run Scratch in your browser, or obtain it for offline use (https://scratch.mit.edu/download).

## Dr Nim - Original Gameplay with coloured text (Python)
`doctor_nim_original_color.py` is a script to reproduce the gameplay of Dr. Nim as sold in the 1960s. Note that the computer player always wins on this version.
Requires Python3 to run (https://www.python.org/downloads/). 

This may be run from the command line as `python doctor_nim_original_color.py` when set to the directory in which the file is saved.

## Memory-efficient 100 Doors 
**(C and Python versions)**  
`efficient.py` is a script that solves the 100 doors problem using bitwise arithmetic. Runs with 100 (the classic value) by default, but accepts a command line value that over-rides the count of 100 doors. The efficiency is achieved by using 1 bit or the equivalent to represent each door (Boolean types may use at least one byte). Requires Python as per Dr Nim.

## `charNode` (directory)
Contains a linked-list solution in C to the issue that taking a string as input requires that the length of a string-equivalent (character array) must be specified when declared. A linked list does not require its length to be specified when the first node is declared. If you wish to run it, please compile from `charNodeTest.c`.
