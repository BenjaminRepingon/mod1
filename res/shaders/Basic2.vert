// Version du GLSL

#version 120


// Entrées

attribute vec3 in_Vertex;
attribute vec3 in_Color;


// Uniform

uniform mat4 T_Projection;
uniform mat4 T_Model;


// Sortie

varying vec3 color;


// Fonction main

void main()
{
    // Position finale du vertex en 3D

    gl_Position = T_Projection * T_Model * vec4(in_Vertex, 1.0);


    // Envoi de la couleur au Fragment Shader

    color = in_Color;
}