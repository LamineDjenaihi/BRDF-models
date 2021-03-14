#version 120
#pragma optionNV(unroll all)
varying vec3 n,s,v,h,t,b,nx;
varying float d;

vec3 L=vec3(1.0,1.0,1.0);
vec3 Kd=vec3(1.0, 1.0, 1.0);
vec3 La=vec3(0.0,0.0,0.0);
vec3 Ka=vec3(0.23125, 0.23125, 0.23125);
vec3 Ls=vec3(1.0,1.0,1.0);
vec3 Ks=vec3(0.773911, 0.773911, 0.773911);
void main(void)
{
vec3 diffus,ambiant;
float nyo=1.65;
float f = d*d;
//****************AMBIANT*************************
ambiant = La*Ka;
//******************DIFFUSE**************


float cos_theta = max(dot(s,n),0.0);

diffus =clamp(   Kd,0.0,1.0) ;
//*****SPECULAR*****************************
vec3 r = -s+(2*cos_theta*n);
float HdotN=max(dot(h,n),0.0);
float VdotN =max(dot(v,n),0.0);
float cos_beta=max(dot(v,h),0.0);
float cos_alpha=max(dot(r,v),0.0);
float sinus_beta=sqrt(1-pow(cos_beta,2));
float sinus_tau=sqrt(sinus_beta/nyo);
float cos_tau=sqrt(1-pow(cos_beta/nyo,2));
float tan_beta=sinus_beta/cos_beta;
float tan_tau=sinus_tau/cos_tau;
float alpha=acos(HdotN);
float D=exp(-pow(((sqrt(1-pow(HdotN,2)))/HdotN),2)/pow(0.8,2))/(3.14*pow(0.8,2)*pow(HdotN,4));
float p1=(pow((sinus_beta*cos_tau)-(sinus_tau*cos_beta),2)/pow((sinus_beta*cos_tau)+(sinus_tau*cos_beta),2));
float p2=pow(tan_beta-tan_tau,2)/pow(1-(tan_beta*tan_tau),2);
float p3=pow(1-(tan_beta*tan_tau),2)/pow(tan_beta-tan_tau,2);
float F_beta=0.5*(p1+(p2*p3));
float p4=(pow((sin(0)*cos_tau)-(sinus_tau*cos(0)),2)/pow((sin(0)*cos_tau)+(sinus_tau*cos(0)),2));
float p5=pow(tan(0)-tan_tau,2)/pow(1-(tan(0)*tan_tau),2);
float p6=pow(1-(tan(0)*tan_tau),2)/pow(tan(0)-tan_tau,2);
float F0=0.5*(p4+(p5*p6));

vec3  Fr=(F0*D)/(4*cos(v)*cos(s));
float beta=acos(cos_beta);
float tau=acos(cos_tau);
vec3 spec=((-(F_beta/F0)*((Fr*cos(h)*cos(h))/(cos(v)*cos(s)))));

//****************************************************************
gl_FragColor = vec4((ambiant+diffus+spec)*L,1.0);
}