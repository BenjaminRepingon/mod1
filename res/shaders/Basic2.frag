// Version du GLSL

#version 120


// Entrée

varying vec3 color;



// Fonction main

void main()
{
    // Couleur finale du pixel

    gl_FragColor = vec4( color, 1.0 );
}