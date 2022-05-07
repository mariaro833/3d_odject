#include <stdio.h>
#include <stdlib.h>
#include "d.h"

void	prints_value_calculation(t_object *object)
{
	int	diameter_b;
	int	height_b;
	int	diameter1;
	int	height1;
	int	width1;
	int	diameter2;
	int	height2;
	int	width2;
	int	offset;
	int	height_zigzag;
	int	step_zigzag;

/* the buttom's parameters */
	diameter_b = object->diameter;
	height_b = object->width;
/* Outer Cylinder's parameters */
	diameter1 = object->diameter;
	height1 = object->height - height_b;
	width1 = object->width;
/* Offset calculation */
	offset = (object->height < 150 || object->diameter < 150) ? 0 : object->height * 0.04;
/* Inward cylinder's calculation && Zigzag's parameters calculation */
	diameter2 = 0;
	height2 = 0;
	width2 = 0;
	height_zigzag = 0;
	step_zigzag = 0;
	if (object->height >= 150 && object->diameter >= 150)
	{
		diameter2 = object->diameter - width1 - 2 * offset;
		height2 = object->height - height_b;
		width2 = width_calculation(diameter2);
		diameter2 = object->diameter - width2;
		height_zigzag = offset;
		step_zigzag = (int)M_PI * 2;
	}
	printf("\n");
	printf("**************************** OBJECT's PARAMETERS *********************************\n\n");
	printf("BUTTOM:\n");
	printf("diameter: %d, height: %d\n\n", object->diameter, object->height);
	printf("OUTER CYLINDER:\n");
	printf("diameter: %d, height: %d, width of a printed layer: %d\n", diameter1, height1, width1);
	if (object->height >= 150 && object->diameter >= 150)
	{
		printf("\n");
		printf("OFFSET: %d\n\n", offset);
		printf("INWARD CYLINDER:\n");
		printf("diameter: %d, height: %d, width of a printed layer: %d\n\n", diameter2, height2, width2);
		printf("ZIGZAG:\n");
		printf("height: %d, step: %d\n", height_zigzag, step_zigzag);
	}
	printf("\n");
	printf("***********************************************************************************\n");
}
