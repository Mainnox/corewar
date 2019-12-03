.name "number_1"
.comment "simple live"

ld 				    :ld, r1
ld:				live%:ld                 #tamer
	live %:live
		live %:live
sti:			sti r1 ,:live         							, %:live
live %:test
 sti r1, r2, %:test
test: sti r1, r2, %:test
