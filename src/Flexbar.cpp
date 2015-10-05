/*==================================================
   
   Flexbar - flexible barcode and adapter removal
   
   Version 2.6 alpha  (GPLv3)
   
   Uses seqan library release 1.4.2
    and tbb library 4.0 or later
   
   Authors: Matthias Dodt and Johannes Roehr
   
   https://github.com/seqan/flexbar
   
===================================================*/


#include "Flexbar.h"
#include "Options.h"
#include "Enums.h"


int main(int argc, const char* argv[]){
	
	using namespace std;
	using namespace flexbar;
	
	using seqan::ArgumentParser;
	
	const string version = "2.6 alpha";
	const string date    = "October 4, 2015";
	
	ArgumentParser parser("flexbar");
	
	defineOptionsAndHelp(parser, version, date);
	parseCommandLine(parser, version, argc, argv);
	
	Options o;
	initOptions(o, parser);
	
	loadProgramOptions(o, parser);
	loadBarcodesAndAdapters(o);
	
	startComputation(o);
	printCompletedMessage(o);
	
	return 0;
}
