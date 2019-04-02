#!/bin/bash

gnuplot -e "set datafile separator \",\"; set term x11 0; splot 'wynik.csv' using 2:3:4; set term x11 1; splot 'wynik.csv' using 5:6:7; pause -1"
