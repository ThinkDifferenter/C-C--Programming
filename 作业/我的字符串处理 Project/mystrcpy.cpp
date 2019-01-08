char mystrcpy(char str1[],str2[])
{
	int i;
	for(i=0;str2[i]!='\0';i++)
	{
		str1[i]=str2[i];
	}
	return *str1;
}
