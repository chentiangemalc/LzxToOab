// LzxToOab.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main(int argc, char* argv[])
{
	msoab_decompressor *decompressor = mspack_create_oab_decompressor(NULL);
	std::cout << "LZX to OAB v0.1 by Malcolm McCaffery" << std::endl;
	std::cout << "http://chentiangemalc.wordpress.com" << std::endl;
	std::cout << "based on libmspack https://www.cabextract.org.uk/libmspack/" << std::endl;
	std::cout << std::endl;

	if (argc != 3)
	{
		std::cout << "Decompresses complete LZX file i.e. <guid>-data-<sequence number>.lzx to OAB file format used by Outlook client." << std::endl;
		std::cout << "Usage:" << std::endl;
		std::cout << std::endl;
		std::cout << "LzxToOab [input LZX file] [output OAB file]";
		return 0;
	} 

	std::cout << "Decompressing '" << argv[1] << "' to '" << argv[2] << "'" << std::endl;
	decompressor->decompress(decompressor, argv[1], argv[2]);
	std::cout << "Complete.";
	
    return 0;
}

