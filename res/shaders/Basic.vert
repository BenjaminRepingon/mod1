attribute vec4 position;
attribute vec4 color;

varying vec4 color0;

void main()
{
	gl_Position = position;
	color0 = color;
}
