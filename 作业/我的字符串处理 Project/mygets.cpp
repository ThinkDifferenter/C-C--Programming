char mygets(char *str)
{
	char ch;
	while(ch!='\n')
	{
		scanf("%c",ch);
	}
	return *str;
}
