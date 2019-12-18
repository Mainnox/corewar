.name "tagrossemere"
.comment "c'est vrai qu'elle est fat !"

aff r1
fork %1
ld %1, r1
ld 1, r1
st r1, 1
st r1, 1
add r1, r1, r1 
and	%1, r1, r1
and r1, %1, r1
and r1, 1, r1
and %1, %1, r1
and 1, %1, r1
and 1, 1, r1
sti r1, r1, %1
sti r1, %1, %1
sti r1, 1, %1
