#include <unistd.h>
#include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char *get_next_line(int fd)
{
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	char *string = malloc(1000000), *copy = string;
	while(read(fd,copy,1) > 0 && *copy++ != '\n');
	*copy = '\0';
	return (copy > string) ? (copy = NULL, string) : (free(string), NULL);
}
