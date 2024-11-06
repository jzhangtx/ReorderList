ReorderList: ReorderList.o
	g++ -g -o ReorderList.exe ReorderList.o -pthread    

ReorderList.o: ReorderList/ReorderList.cpp
	g++ -g  -c -pthread ReorderList/ReorderList.cpp
