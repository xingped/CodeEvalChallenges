int is_pal(char* test_string);

int is_pal(char* test_string)
{
	int i;
	int str_size = strlen(test_string);
	
	for(i = 0; i < str_size; i++)
	{
		if(test_string[i] == test_string[str_size - i - 1])
		{
			continue;
		}
		else
		{
			return(1);
		}
	}
	
	return(0);
}