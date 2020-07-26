# Fillit

Fillit is a project that let you discover and/or familiarize yourself with a recurring problematic in programming:
<br/>searching the optimal solution among a huge set of possibilities, in a respectable timing.
<br/>In this project, you will have to find a way to assemble a given Tetriminos set altogether in the smallest possible square.
<br/>A Tetriminos is a 4-blocks geometric figure you probably already heard of, thanks to the popular game Tetris.
<br/>It is a project you have to do with 2people, I did it togheter with [@mvhou](https://github.com/mvhou)

## Project

Fillit takes a file that contains a list of Tetriminos, and arrange them in order to create the smallest square possible in a fast way.

## Rules

A file should contain between 1 and 26 tetriminos.
<br/>A files should have the following format:
- A tetrimino is a classic piece of Tetris, composed of 4 blocks.
- A tetrimino must fit in a 4 by 4 chars square, each line followed by a newline.
- All tetriminos must be separated by an newline.
- The square can only have '#' (block character) and '.'(empty character).
- Each block of a tetrimino must touch at least one other block on any of his 4 sides.
<br/>Example of a valid file
```
...#
...#
...#
...#

..#.
..#.
..##
....
```

## Goal

The goal of this project is to arrange every tetriminos with each others in order to make the smallest possible square. But in some cases, this square should contains holes when 
<br/>some given pieces won’t fit in perfectly with others.
<br/>Even if they are embedded in a 4x4 square, each Tetrimino is defined by its minimal boundaries (their ’#’). The 12 remaining empty characters will be ignored for the 
<br/>tetriminos assemble process.
Tetriminos are ordered by they apparition order in the file. Among all the possible candidates for the smallest square, we only accept the one where tetriminos is placed on their most upper-left position.

You can't rotate a tetrimino.

## Program output

The program must display the smallest assembled square on the standard output. To identify each tetrimino in the square solution,
<br/>you will assign a capital letter to each tetrimino, starting with 'A' and increasing for each new tetrimino.

## Allowed functions

exit
<br/>open
<br/>close
<br/>write
<br/>read
<br/>malloc
<br/>free

## Usage
```bash
$ make
$ ./fillit [filename]
```
