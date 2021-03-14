#version 120
#pragma optionNV(unroll all)
uniform vec3 position;
varying vec3 n,s,v,h;
//varying float d;
vec3 L=vec3(1.0,1.0,1.0);
vec3 Kd=vec3(0.75164,0.60648,0.22648);
vec3 Ka=vec3(0.24725,0.1995,0.0745);
vec3 Ks=vec3(0.628281,	0.555802,0.366065);
void main(void)
{
vec3 diffus,ambiant,spec;

//float d=length(t);
//vec3 color = vec3(d);
////*****AMBIANT----------
ambiant = L*Ka;
////*****DIFFUSE----------
float cos_theta_i = max(dot(s,n),0.0);
float theta_i=acos(cos_theta_i);
vec3 r = -s+(2*cos_theta_i*n);
float cos_alpha=max(dot(r,v),0.0);
float alpha=acos(cos_alpha);
float am=exp(-pow(tan(alpha),2)/pow(0.4512,2))/(3.14*pow(0.4512,2)*pow(cos(alpha),4));
float A=1-((0.5*pow(am,2))/(pow(am,2)+0.33));
float B=(0.45*pow(am,2))/(pow(am,2)+0.09);
float cos_theta_r=max(dot(n,v),0.0);
float theta_r=acos(cos_theta_r);
float as=max(theta_i,theta_r);
float bs=min(theta_i,theta_r);
float cos_betha=max(dot(h,v),0.0);
float sin_theta_i=sqrt(1-pow(cos_theta_i,2));
float sin_theta_r=sqrt(1-pow(cos_theta_r,2));
float cos_phi=(cos_betha-(cos_theta_i*cos_theta_r))/(sin_theta_i*sin_theta_r);
float t=(A+(B*cos_phi*sin(as)*tan(bs)));
diffus =clamp((0.80/3.14)*cos_theta_i*t*L*Kd ,0.0,1.0);

gl_FragColor = vec4((ambiant+diffus),1.0);
}


