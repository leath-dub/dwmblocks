//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/
	{" ", "echo $(cpu)'%'",	5,		0},
	{" ", "echo $(mem)'%'",	30,		0},
	{" ", "bar_volume", 	1,  	0},
	{" ", "echo $(bat)",	60,		0},
	{" ", "echo $(dat)' '",	60,		0},
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = " │";
static unsigned int delimLen = 5;
