#pragma once

void my_strcpy(const char* source, char* destination)
{
	while (*source != 0) 
	{
		*destination = *source;
		destination++;
		source++;
	}
	*destination = 0;
}

bool my_strcmp(const char* first, const char* second)
{
	while (*first != 0 && *second != 0)
	{
		if (*first != *second)
			return false;
		first++;
		second++;
	}
}

