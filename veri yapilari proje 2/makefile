all:derle bagla calistir
derle:
	g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o
	g++ -c -I "./include" ./src/AVLAgaci.cpp -o ./lib/AVLAgaci.o
	g++ -c -I "./include" ./src/Dugum.cpp -o ./lib/Dugum.o	
	g++ -c -I "./include" ./src/YaprakYigini.cpp -o ./lib/YaprakYigini.o
	g++ -c -I "./include" ./src/BagilDugum.cpp -o ./lib/BagilDugum.o
	g++ -c -I "./include" ./src/BagliListe.cpp -o ./lib/BagliListe.o
	
	
bagla:
	g++ ./lib/Dugum.o	./lib/AVLAgaci.o ./lib/main.o ./lib/YaprakYigini.o ./lib/BagilDugum.o ./lib/BagliListe.o -o ./bin/program
calistir:
	./bin/program