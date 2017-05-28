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

	if (argc != 3 && argc !=4)
	{
		std::cout << "Decompresses complete LZX file i.e. <guid>-data-<sequence number>.lzx or complete LZX file + incremental patch file i.e. <guid>-binpatch-<sequence number> to OAB file format used by Outlook client." << std::endl;
		std::cout << "Usage:" << std::endl;
		std::cout << std::endl;
		std::cout << "LzxToOab [input LZX file] [output OAB file]";
		std::cout << "LzxToOab [input base LZX file] [input LZX incremenal file] [output OAB file]";
		return 0;
	} 

	if (argc == 3)
	{
		std::cout << "Decompressing '" << argv[1] << "' to '" << argv[2] << "'" << std::endl;
		decompressor->decompress(decompressor, argv[1], argv[2]);
	}
	else
	{
		std::cout << "Decompressing '" << argv[1] << "'+'" << argv[2] << "' to '" << argv[3] << "'" << std::endl;
		decompressor->decompress(decompressor, argv[1], argv[2]);
		decompressor->decompress_incremental(decompressor, argv[2], argv[1], argv[3]);
	}
	std::cout << "Complete.";
    return 0;
}

