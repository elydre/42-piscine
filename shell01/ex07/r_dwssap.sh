#!/bin/bash
cat /etc/passwd | grep -v '#' | awk 'NR%2==0' | cut -d : -f 1 | rev | sort -r | awk "NR>=$FT_LINE1 && NR<=$FT_LINE2" | tr '\n' , | sed 's/,$/./g' | sed 's/,/, /g' | tr -d '\n'
