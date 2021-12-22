#!/bin/bash
#ARG=`ruby -e "puts (0..500).to_a.shuffle.join(' ')"`; ./push_swap $(echo $ARG)
ARG=`ruby -e "puts (0..20).to_a.shuffle.join(' ')"`; ./a.out $(echo $ARG)
