attribute vec4 position;
attribute vec4 color;

varying vec4 color0;

uniform mat4 projection;
uniform mat4 modelview;

void main()
{
	gl_Position = projection * modelview * position;
	color0 = color;
}
