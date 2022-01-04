#!/bin/bash
#ARG=`ruby -e "puts (1..5).to_a.shuffle.join(' ')"`; ./push_swap $(echo $ARG)
#ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`; ./push_swap $(echo $ARG)
ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`; ./push_swap $(echo $ARG)
#ARG=`ruby -e "puts (1..30).to_a.shuffle.join(' ')"`; echo $ARG; ./push_swap $(echo $ARG)
