/**
 * File: File.c
 * Author: Sam Caulfield
 * Date: 29.08.2016
 * Description: File utility functions
 */

#include <stdio.h>
#include <stdlib.h>
#include "File.h"

char *fileRead(char *fileName)
{
	FILE *file = fopen(fileName, "r");
	if (!file) {
		return NULL;
	}
	fseek(file, 0L, SEEK_END);
	long fileLength = ftell(file);
	if (fileLength == -1) {
		fclose(file);
		return NULL;
	}
	char *buffer = malloc((fileLength + 1) * sizeof(*buffer));
	if (!buffer) {
		fclose(file);
		return NULL;
	}
	buffer[fileLength] = '\0';
	rewind(file);
	if (fread(buffer, sizeof(char), fileLength, file) != fileLength) {
		fclose(file);
		free(buffer);
		return NULL;
	}
	fclose(file);
	return buffer;
}

