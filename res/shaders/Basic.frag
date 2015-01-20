#version 120

void main()
{
	float lerpValue = gl_FragCoord.y / 500.0f;

	gl_FragColor = mix(vec4(1.0f, 1.0f, 1.0f, 1.0f), vec4(0.0f, 1.0f, 0.0f, 1.0f), lerpValue);
}
