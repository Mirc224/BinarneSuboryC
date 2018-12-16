#include <stdio.h>
#include <iostream>
#include <fstream> // C++

struct Objekt
{
	int hodnota1;
	int hodnota2;
	float hodnota3;
};
// zarovnavanie pamate 

int main()
{
	char buffer[1000];
	FILE* file = fopen("binarny.txt", "w+");  // metody fread fwrite fseek
	fread(buffer, sizeof(char), 1000, file); // buffer pole v ktorom su data, ktore chceme zapisat, char pointrove polia, buffer je pole 
	//fseek(file,0, SEEK_SET); // 3 seekovacie makra, seekcur seekset seekend / podla toho odkial ideme citat end koniec, cur aktualna pozicia 0 JE offset o kolko sa posuvam od aktualneho 
	fwrite(buffer, sizeof(char), 1000, file);
	fwrite(buffer, sizeof(Objekt), 1000, file);
	fread(buffer, sizeof(Objekt), 1000, file);
	fclose(file);

	std::fstream binaryFile("binarny.txt", std::ios::in | std::ios::out | std::ios::binary); //flagy | binarny sucet
	//binaryFile.seekp();  // v C++ dva pointre, odkial yiskavame a kam davame// seekg posuva pointer kde citame a seekp kam davame
	// to iste ako to hore, ale neprehladne   fwrite(buffer, sizeof(buffer),1, file);
	binaryFile.write((char*) buffer, sizeof(buffer)); //mozes hocico pretypovat na char pointer
	binaryFile.read((char*) buffer, sizeof(buffer)); //zatvaranie prebehne samo  
	//alebo
	// mozes pouzit static_cast na objekty, na primitivne to nejde binaryFile.write((char*)buffer, sizeof(buffer));
	return 0;
}