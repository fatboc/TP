#!/bin/bash

gnuplot -e "set datafile separator \",\"; set term x11 0; splot 'wynik.csv' using 2:3:4; pause -1; set term x11 1; splot 'wynik.csv' using 5:6:7; pause -1"

gnuplot -e "set datafile separator \",\"; set term x11 0; plot 'wynik.csv' using 1:5; set term x11 1; plot 'wynik.csv' using 1:6; set term x11 2; plot 'wynik.csv' using 1:7 ;pause -1"
