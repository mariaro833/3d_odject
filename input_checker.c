#include <stdio.h>
#include <stdlib.h>
#include "d.h"

int	width_calculation(int diameter)
{
	int	width;

	width = 0;
	if (diameter >= 80 && diameter < 220)
		width = 3;
	if (diameter >= 220 && diameter < 360)
		width = 4;
	if (diameter >= 360 && diameter < 500)
		width = 5;
	if (diameter == 500)
		width = 6;
	return (width);
}

void	input_checker(t_object *object)
{
	int		min_height;
	int		max_height;
	int		width_est;
	int		answer;

	object->height = 0;
	object->diameter = 0;
	object->width = 0;
	while (object->width == 0)
	{
		while (object->diameter == 0 )
		{
			printf("Print the diameter of the Object (min 80cm and max 500cm): ");
			scanf("%d", &object->diameter);
			if (object->diameter < 80 || object->diameter > 500)
				object->diameter = 0;
		}
		while (object->height == 0)
		{
			min_height = (object->diameter < 100) ? 100 : object->diameter;
			max_height = (object->diameter * 1.5 > 500) ? 500 : object->diameter * 1.5;
			printf("Print the hieght of the Object, (min %d cm, max %d cm): ", min_height, max_height);
			scanf("%d", &object->height);
			if (object->height < min_height || object->height > max_height)
			{
				object->height = 0;
				printf(">>Ratio between height(H) and diameter(D) is in the range 1:1 to 1:1.5\n");
			}
		}
		width_est = width_calculation(object->diameter);
		printf ("Width of a printed layer is %d, ok?\n", width_est);
		printf ("Type 1 if agreed ");
		scanf("%d", &answer);
		if (answer == 1)
			object->width = width_est;
		else
		{
			printf("\n***********************************************************************************\n");
			printf("\nThe diameter (D) and the height (H) should be changed\n(As dimesions of the cylinder increase, so does the width of the layer):\n\nfor width equals 3 -> D >= 80 && D < 220;\nfor width equals 4 -> D >= 220 && D < 360;\nfor width equals 5 -> D >= 360 && D < 500;\nfor width equals 6 -> D == 500\n\nRatio between height(H) and diameter(D) is in the range 1:1 to 1:1.5\n");
			printf("\n***********************************************************************************\n");
			object->diameter = 0;
			object->height = 0;
		}
	}
}