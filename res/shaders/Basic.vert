#version 120

attribute vec3 position;
attribute vec3 color;
//attribute vec3 normal;

varying vec4 color0;
varying vec3 normal0;
//varying vec3 worldPos0;

uniform mat4 T_Model;
uniform mat4 T_Projection;

void main()
{
	gl_Position = T_Projection * T_Model * vec4(position, 1.0);
	color0 = vec4( color, 1.0 );
	//normal0 = (T_Model * vec4(normal, 0.0)).xyz;
	//worldPos0 = (T_Model * vec4(position, 1.0)).xyz;
}
