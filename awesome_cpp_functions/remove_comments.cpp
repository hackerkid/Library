#include <iostream>
#include <fstream>
#include <sstream>


enum states { TEXT, SINGLE_QUOTE, SINGLE_SLASH, SINGLE_LINE_COMMENT, MULTI_COMMENT, MULTI_LINE_COMMENT, STAR_FOUND};
using namespace std;

/**/

//read the file from the file
string read_file(const char * name)
{
	std::ifstream fcin(name);
	std::stringstream buffer;
	
	buffer << fcin.rdbuf();

	return buffer.str();

}


//check 

void parser(string file)
{	
	int state;
	char c;
	state = TEXT;

	for(int i = 0; i < file.length(); i++) {
		c = file[i];
	
		switch(state) {
			case TEXT:

				switch(c) {
					case '/':
						state = SINGLE_SLASH;
						break;

					case '"':
						state = SINGLE_QUOTE;
						break;

					default: 
					cout << c;
				}

				break;

			case SINGLE_SLASH:
				switch(c) {
					case '/':
					state = SINGLE_LINE_COMMENT;
					break;

					case '*':
					state = MULTI_LINE_COMMENT;
					break;
				}

				break;

			case SINGLE_LINE_COMMENT:
				switch(c) {
					case '\n':
						state = TEXT;
						break;
				}
				

				break;

			case MULTI_LINE_COMMENT:
				switch(c) {
					case '*':
					state = STAR_FOUND;
				}
				break;

			case STAR_FOUND:
				switch(c) {
					case '/':
						state = TEXT;
						break;
				}
				break;

			case SINGLE_QUOTE:
				switch(c) {
					case '"':
					state = TEXT;
					break;
				}
				break;

		}		
	}
} 


int main()
{
	string file;

	file = read_file("input");
	parser(file);

}

