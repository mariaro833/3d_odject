#include <stdio.h>
#include <stdlib.h>
#include "d.h"

int	exit_msg(char *message, int output)
{
	printf("%s\n", message);
	return(output);
}

int main()
{
	t_object	*object;

	if (!(object = (t_object *)malloc(sizeof(t_object))))
		exit_msg("STACK OVERFLOW", 1);
	input_checker(object);
	prints_value_calculation(object);
	// printf("d: %d\n h: %d\n w: %d\n", object->diameter, object->height, object->width);
	return (0);
}
