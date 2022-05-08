#include <stdio.h>
#include <stdlib.h>
#include "d.h"

void	prints_value_calculation(t_object *object)
{
	float	diameter_b;
	float	height_b;
	float	diameter1;
	float	height1;
	float	width1;
	float	diameter2;
	float	height2;
	float	width2;
	float	offset;
	float	height_zigzag;
	float	step_zigzag;

/* the buttom's parameters */
	diameter_b = object->diameter - (object->width / 2);
	height_b = object->width;
/* Outer Cylinder's parameters */
	diameter1 = object->diameter - (object->width / 2);
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
		width2 = object->width;
		diameter2 = object->diameter - 2 * width1 - 2 * offset - width2;
		height2 = object->height - height_b;
		height_zigzag = offset;
		step_zigzag = M_PI * 2;
	}
	printf("\n");
	printf("**************************** OBJECT's PARAMETERS *********************************\n\n");
	printf("BUTTOM:\n");
	printf("diameter: %.1f, height: %.1f\n\n", diameter_b, height_b);
	printf("OUTER CYLINDER:\n");
	printf("diameter: %.1f, height: %.1f, width of a printed layer: %.1f\n", diameter1, height1, width1);
	if (object->height >= 150 && object->diameter >= 150)
	{
		printf("\n");
		printf("OFFSET: %.1f\n\n", offset);
		printf("INWARD CYLINDER:\n");
		printf("diameter: %.1f, height: %.1f, width of a printed layer: %.1f\n\n", diameter2, height2, width2);
		printf("ZIGZAG:\n");
		printf("height: %.1f, step: %.1f\n", height_zigzag, step_zigzag);
	}
	printf("\n");
	printf("***********************************************************************************\n");
}
