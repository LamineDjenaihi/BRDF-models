#version 120
#pragma optionNV(unroll all)
uniform vec3 position,camera;

//vec3 position=vec3(10.0,2.0,10.0);
varying vec3 n,s,v,h,t,b,nx;
varying float d;
 
void main(void)
{
 t=vec3(1,0,0);
 b=vec3(0,1,0);
 nx=vec3(0,0,1);
vec4 vertex=vec4(gl_Vertex);
gl_Position=gl_ModelViewProjectionMatrix * vertex;
d = distance(position.xyz,vertex.xyz);
v=normalize((camera.xyz-vertex.xyz));
n=normalize(gl_Normal);
s=normalize((position.xyz-vertex.xyz));
h=normalize(((position.xyz-vertex.xyz)+(camera.xyz-vertex.xyz))/2);
nx=normalize(nx);
b=normalize(b);
t=normalize(t);
}
