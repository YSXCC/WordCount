#include <stdio.h>
#include <string.h>

int countChar(FILE* file);
int countWord(FILE* file);

int main(int argc, char* argv[])
{
	char* parameter = argv[1];
	char* input_file_name = argv[2];
	FILE* file = fopen(input_file_name, "r");
	if (strcmp(parameter, "-c") == 0)
	{
		int count = countChar(file);
		printf("×Ö·ûÊý£º%d\n", count);
	}
	else if (strcmp(parameter, "-w") == 0)
	{
		int count = countWord(file);
		printf("µ¥´ÊÊý£º%d\n", count);
	}
	return 0;
}

int countChar(FILE* file)
{
	int count_char = 0;
	do {
		char c = fgetc(file);
		if (feof(file)) {
			break;
		}
		count_char++;
	} while (!feof(file));
	return count_char;
}

int countWord(FILE* file) 
{
	int count_word = 0;
	bool flag = false;
	do {
		char c = fgetc(file);
		if (feof(file)) {
			if (flag){
				count_word++;
			}
			break;
		}
		if (c != ' ' && c != ',' && c != '\n' && c != '\t') {
			flag = true;
		}else{
			if (flag) {
				count_word++;
			}
			flag = false;
		}
	} while (!feof(file));
	return count_word;
}