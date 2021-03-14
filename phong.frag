#version 120
#pragma optionNV(unroll all)
varying vec3 s,v,c;
varying float d;
vec3 Ld=vec3(1.0,1.0,1.0);
vec3 Kd=vec3(1.0,1.0,1.0);
vec3 Ls=vec3(1.0,1.0,1.0);
vec3 Ks=vec3(1.0,1.0,1.0);
void main(void)
{
vec3 diffus,ambiant,spec;
n=normalize(gl_Normal);
////*****DIFFUSE----------
float cos_theta = max(dot(s,n),0.0);
diffus =clamp( Ld * Kd * cos_theta,0.0,1.0) ;
////*****SPECULAIRE----------
vec3 r = -s+(2*cos_theta*n);
float cos_alpha=max(dot(r,v),0.0);
spec= Ls*Ks*(pow(cos_alpha,50)/cos_theta);
gl_FragColor = vec4(diffus+spec),1.0);
}