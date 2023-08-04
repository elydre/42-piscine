#!/bin/bash

# base `'\"?!` => base 5 (01234)
# base `mrdoc` => base 5 (01234)
# base `gtaio luSnemf` => base 13 (0123456789ABC)

# base1="'"'\\"?!'
#
# n1=`echo $FT_NBR1 | sed 'y/'$base1'/01234/'`
# n2=`echo $FT_NBR2 | sed 'y/mrdoc/01234/'`
#
# sum=`echo "obase=13;ibase=5;$n1+$n2" | bc`
#
# echo $sum | sed 'y/0123456789ABC/gtaio\ luSnemf/'

echo $(echo "obase=13;ibase=5;$(echo $FT_NBR1 | sed 'y/'"'"'\\"?!''/01234/')+$(echo $FT_NBR2 | sed 'y/mrdoc/01234/')" | bc) | sed 'y/0123456789ABC/gtaio\ luSnemf/'
