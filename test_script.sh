#!/bin/bash
#ARG=`ruby -e "puts (0..500).to_a.shuffle.join(' ')"`; ./push_swap $(echo $ARG)
ARG=`ruby -e "puts (1..30).to_a.shuffle.join(' ')"`; echo $ARG; ./push_swap $(echo $ARG)
