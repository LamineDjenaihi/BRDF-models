#version 120
#pragma optionNV(unroll all)
uniform vec3 position;
varying vec3 n,s,v,c,t;
//varying float d;
vec3 Ld=vec3(1.0,1.0,1.0);
vec3 Kd=vec3(0.75164,0.60648,0.22648);
vec3 La=vec3(0.9,0.9,0.9);
vec3 Ka=vec3(0.24725,0.1995,0.0745);
vec3 Ls=vec3(1.0,1.0,1.0);
vec3 Ks=vec3(0.628281,	0.555802,0.366065);
void main(void)
{
vec3 diffus,ambiant,spec;

float d=length(t);
//vec3 color = vec3(d);
////*****AMBIANT----------
ambiant = La*Ka;
////*****DIFFUSE----------
float cos_theta = max(dot(s,n),0.0);
diffus =clamp(Ld * Kd * cos_theta,0.0,1.0) ;

gl_FragColor = vec4((ambiant+diffus),1.0);
}


