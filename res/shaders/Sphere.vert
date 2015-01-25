attribute vec3 position;
attribute vec3 color;

varying vec4 color0;
varying vec2 mapping;

uniform mat4 T_MVP;
uniform float sphereRadius;

void main()
{
	// gl_Position = T_MVP * vec4( position, 1.0 );
	color0 = vec4( color, 1.0 );
	vec2 offset;

	if ( gl_VertexID == 0 )
	{
		//Bottom-left
		mapping = vec2(-1.0, -1.0);
		offset = vec2(-sphereRadius, -sphereRadius);
	}
	else if ( gl_VertexID == 1 )
	{
		//Top-left
		mapping = vec2(-1.0, 1.0);
		offset = vec2(-sphereRadius, sphereRadius);
	}
	else if ( gl_VertexID == 2 )
	{
		//Bottom-right
		mapping = vec2(1.0, -1.0);
		offset = vec2(sphereRadius, -sphereRadius);
	}
	else if ( gl_VertexID == 3 )
	{
		//Top-right
		mapping = vec2(1.0, 1.0);
		offset = vec2(sphereRadius, sphereRadius);
	}

	vec4 cameraCornerPos = vec4(position, 1.0);
	cameraCornerPos.xy += offset;

	gl_Position = T_MVP * cameraCornerPos;
}
