cat /etc/passwd | sed '/#/d' | sed -n '/ /{n;p;}' | rev | sort -r | cut -d ":" -f 7 | awk -v min=$FT_LINE1 -v max=$FT_LINE2 'NR >= min && NR <= max' | tr '\n' ' ' | sed 's/ /, /g' | sed 's/\(.*\), /\1./g' | tr -d '\n'