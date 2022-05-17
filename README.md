## GEOMETRICAL OBJECT FOR ROBOTIC 3D-PRINTING

Task: Program a parametrically driven geometrical object for robotic 3D-printing

Object: a cylinder that could be utilized as a manhole, water tank, silo

The target: A visualization of the parametric model with a set of interactive parameters (numerical sliders).

Arguments: object height, object diameter, the width of a printed layer.
- Height: min 100 cm, max 500 cm. Diameter: min 80 cm, max 500 cm
- Ratio between height and diameter is in the range of 1-1 to 1-1.5. As one parameter changes, the second changes too in the given ratio.
- Width of a printed layer is in the range of 3 cm - 6 cm

Conditions:
Once the height or diameter of the cylinder is more than 150 cm, the surface of the
cylinder is copied inwards with an offset. From a one-wall object it becomes a two-wall
object. Offset range - 6-20 cm.
- As the dimensions of the cylinder increase, so does the offset between inner and
outer surfaces.
- As the dimensions of the cylinder increase, so does the width of the printed layer.
- Once there is a space between inner and outer surfaces (walls), an infill is
generated between them. Infill geometry is zigzag.

Project implementation:

The project implemented on JS.

At first, the parameters for the constituent parts of an object was calculated.

Width of the printed layer 
- According to the condition of the assignment, the width of the printed layer is 3-6 cm and depends on the size of the subject. 
So it was introduced the follows direct dependence of the width of the printed layer on the diameter of the object:
- if (diameter >= 80 && diameter < 220)
	width = 3;
- if (diameter >= 220 && diameter < 360)
        width = 4;
- if (diameter >= 360 && diameter < 500)
	width = 5;
- if (diameter == 500)
        width = 6;

Outer cylinder
- The diameter of the outer cylinder is equal to:
(diameter of the Object) minus (width of a printed layer).
- The height of the outer cylinder is equal to the height of the Object.
					
Inner cylinder
- The diameter of the inner cylinder is equal to: 
(diameter of the outer cylinder) minus (2 * offset). 
- The width of a printed layer for both cylinders is taken into account.

Zigzag
- For zigzag parameters, it was assumed that the zigzag does not need to be superimposed on the outer and inner cylinders.
So zigzag draws according to the number of segments, wich specified as the argument.

You can change the height and width of an object. Also, zigzag parameters are adjusted in the "Zigzag, number of segments" field.
The zigzag is reflected as a line, I did not extend the lines to the entire height of the cylinder, as they do not look very pretty.

I added the "scale" parameter, it shows the current display scale of the object.
