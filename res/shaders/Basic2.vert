// Version du GLSL

#version 410


// Entrées

in vec3 in_Vertex;
in vec3 in_Color;
in vec3 in_Normal;


// Uniform

uniform mat4 T_Model;
uniform mat4 T_View;
uniform mat4 T_Projection;


// Sortie

out vec3 color;


// Fonction main

void main()
{
    // Position finale du vertex en 3D

    gl_Position = T_Projection * T_Model * T_View * vec4(in_Vertex, 1.0);


    // Envoi de la couleur au Fragment Shader

    color = in_Color;
}
