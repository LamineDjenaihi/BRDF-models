#version 120
#pragma optionNV(unroll all)
uniform vec3 position,camera;

//vec3 position=vec3(10.0,2.0,10.0);
varying vec3 n,s,v,h;
varying float d;
void main(void)
{
 
vec4 vertex=vec4(gl_Vertex);
gl_Position=gl_ModelViewProjectionMatrix * vertex;
d = distance(position.xyz,vertex.xyz);
v=normalize((camera.xyz-vertex.xyz));
n=normalize(gl_Normal);
s=normalize((position.xyz-vertex.xyz));
h=normalize(((position.xyz-vertex.xyz)+(camera.xyz-vertex.xyz))/2);
} 
