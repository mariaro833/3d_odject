## GEOMETRICAL OBJECT FOR ROBOTIC 3D-PRINTING

Task: Program a parametrically driven geometrical object for robotic 3D-printing

Object: cylinder that could be utilized as a manhole, water tank, silo

The target: A visualization of the parametric model with a set of interactive parameters (numerical sliders).

Arguments: object height, object diameter, width of a printed layer.
- Height: min 100 cm, max 500 cm. Diameter: min 80 cm, max 500 cm
- Ratio between height and diameter is in the range 1-1 to 1-1.5. As one parameter changes, the second changes too in the given ratio.
- Width of a printed layer is in a range 3 cm - 6 cm

Conditions:
Once height or diameter of the cylinder is more than 150 cm, the surface of the
cylinder is copied inwards with an offset. From one-wall object it becomes a two-wall
object. Offset range - 6-20 cm.
- As dimensions of the cylinder increase, so does the offset between inner and
outer surfaces.
- As dimensions of the cylinder increase, so does the width of the printed layer.
- Once there is a space between inner and outer surfaces (walls), an infill is
generated between them. Infill geometry is zigzag.

Project implementation:

The project implementation consist of two parts:
1. Calculation of the parameters;
2. Visualization of the result

<details><summary>1. Calculation of the parameters.</summary> 

Part 1 was implemented with C language and there was calculated the parameters for the constituent parts of an object.

Bottom of the object.
  There was added the bottom of the object with the follows parameters:
	height_b is equal to the width of a printed layer;
	diameter_b is equal to the diameter of the Object.

Offset for the  inner cylinder
According to the condition of the assignment,the offset is 3-6 cm and depends on the size of the subject. 
So it was introduced the follows direct dependence of the offset on the diameter of the object:
- if (diameter >= 80 && diameter < 220)
	width = 3;
- if (diameter >= 220 && diameter < 360)
        width = 4;
- if (diameter >= 360 && diameter < 500)
	width = 5;
- if (diameter == 500)
        width = 6;

Inner cylinder
The diameter of the inner cylinder is equal to: 
diameter of the Object - width of a printed layer for the outer cylinder -  2 * offset -  width of a printed layer for the inner cylinder. 
The width of a printed layer for both cylinders are taken into account.

Zigzag
For zigzag parameters, it was assumed that the zigzag does not need to be superimposed on the outer and inner cylinders.
zigzag_height is equals offset;
zigzag_step = 2pi

<details><summary>2. Visualization of the result</summary>
  
