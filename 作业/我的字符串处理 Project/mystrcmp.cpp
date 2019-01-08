int mystrcmp(char str1[],str2[])
{
	int i,j;
	for(j=0;str1[j]!='\0';j++);
	for(i=0;str1[i]!='\0'||str2[i]!='\0';i++)
	{
		if(str1[i]==str2[i])
		{
			i++;
		}
		else if(str1[i]>str2[i])
		{
			return 1;
			break;	
		}
		else
		{
			return -1;
			break;
		}
	}
	if(i==j)
	{
		return 0;
	}
}
