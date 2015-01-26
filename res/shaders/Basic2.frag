// Version du GLSL

#version 410


// Entrée

in vec3 color;



// Fonction main

void main()
{
    // Couleur finale du pixel

    gl_FragColor = vec4( color, 1.0 );
}
