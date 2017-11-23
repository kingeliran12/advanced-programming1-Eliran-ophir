# harocho
# 301884805

a.out: compileAll
	g++ *.o 
	rm -f *.o

compileAll: *.h *.cpp
	g++ -c *.cpp
