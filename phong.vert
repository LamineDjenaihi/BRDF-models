#version 120
#pragma optionNV(unroll all)
vec3 camera=vec3{3.0,3.0,3.0};

vec3 position=vec3(3.0,3.0,3.0);
varying vec3 n,s,v;
varying float d;
void main(void)
{
 
vec4 vertex=vec4(gl_Vertex);
gl_Position=gl_ModelViewProjectionMatrix * vertex;
//d = distance(position.xyz,vertex.xyz);
v=normalize((camera.xyz-vertex.xyz));

s=normalize((position.xyz-vertex.xyz));


} 

