.name "zork"
.comment "I'M ALIIIIVE"

test:	live %1

l2:		aff r1
		live %2
		live %:test
		live %:test
		ld :l2, r1
