int main(void)
{
	char	*line;
	int		fd;
	int		i;

	int		fd2;
	int		fd3;
	int		fd4;
	int		fd5;

	//bad fd
	printf("\n");
	printf("Bad fd\n");
	i = get_next_line(-1, &line);
	printf("**%d** %s\n", i, line);
	printf("\n");

	// n symbol in file
	printf("\\n symbol in file \n");
	fd2 = open("ntest.txt", O_RDONLY);
	i = get_next_line(fd2, &line);
	printf("**%d** %s\n", i, line);
	printf("\n");

	// empty file
	printf("empty file \n");
	fd3 = open("empty.txt", O_RDONLY);
	i = get_next_line(fd3, &line);
	printf("**%d** %s\n", i, line);
	printf("\n");


	//bonus multiple fd

	fd4 = open("multiple1.txt", O_RDONLY);
	i = get_next_line(fd4, &line);
	printf("**%d** %s\n", i, line);

	fd5 = open("multiple2.txt", O_RDONLY);

	i = get_next_line(fd5, &line)
	printf("**%d** %s\n", i, line);
	
	i = get_next_line(fd4, &line);
	printf("**%d** %s\n", i, line);
	printf("\n");
	

	// reading from file
	printf("reading file \n");
	fd = open("nik2.txt", O_RDONLY);
	while ((i = get_next_line(fd, &line)))
	{
		printf("**%d** %s\n", i, line);
		free(line);
	}
	printf("**%d** %s\n", i, line);
	free(line);
	printf("\n");

	// printf("\n");
	// printf("Stdio\n");
	// while ((i = get_next_line(1, &line)) > 0)
	// 	printf("**%d** %s\n", i, line);
	// printf("\n");


}