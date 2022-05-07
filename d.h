#ifndef D_H
#define D_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct s_object
{
	float	height;
	float	diameter;
	float	width;
}	t_object;

void	input_checker(t_object *object);
void	prints_value_calculation(t_object *object);
int		width_calculation(int diameter);

#endif