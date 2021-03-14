#version 120
#pragma optionNV(unroll all)
uniform vec3 position;

//vec3 position=vec3(9.0,15.0,40.0);
varying vec3 n,s,v,t;
//varying float d;
void main(void)
{

 vec4 vertex=vec4(gl_Vertex);
gl_Position=gl_ModelViewProjectionMatrix * vertex;
t=(position.xyz-vertex.xyz);

n=normalize(gl_Normal);
s=normalize((position.xyz-vertex.xyz));


} 

