#version 120
#pragma optionNV(unroll all)
varying vec3 n,s,v,h;
vec3 L=vec3(1.0,1.0,1.0);
vec3 Kd=vec3(0.75164,0.60648,0.22648);
vec3 Ks=vec3(0.628281,	0.555802,0.366065);
void main(void)
{
vec3 diffus,ambiant;
float nyo=1.65;
////*****DIFFUSE----------
float cos_theta = max(dot(s,n),0.0);
diffus =clamp(   Kd,0.0,1.0)  ;
////*****SPECULAIRE----------
vec3 r = -s+(2*cos_theta*n);
float HdotN=max(dot(n,h),0.0);
float VdotN =max(dot(n,v),0.0);
float cos_beta=max(dot(v,h),0.0);
float cos_alpha=max(dot(v,r),0.0);
float sinus_beta=sqrt(1-pow(cos_beta,2));
float sinus_tau=sqrt(sinus_beta/nyo);
float cos_tau=sqrt(1-pow(cos_beta/nyo,2));
float tan_beta=sinus_beta/cos_beta;
float tan_tau=sinus_tau/cos_tau;
float p1=(pow((sinus_beta*cos_tau)-(sinus_tau*cos_beta),2)/pow((sinus_beta*cos_tau)+(sinus_tau*cos_beta),2));
float p2=pow(tan_beta-tan_tau,2)/pow(1-(tan_beta*tan_tau),2);
float p3=pow(1-(tan_beta*tan_tau),2)/pow(tan_beta-tan_tau,2);
float F_beta=0.5*(p1+(p2*p3));
float alpha=acos(cos_alpha);  
//float D=(exp((pow(HdotN,2)-1/(pow(0.8,2)*pow(HdotN,2)))))/((pow(0.8,2)*pow(HdotN,4)));
float D = cos_beta*(exp(-2*(alpha/0.8)));
float test=min((2*HdotN*VdotN)/cos_beta,(2*HdotN*cos_theta)/cos_beta); 
float G = min(1,test);

float spec= ((D*F_beta*G)/(3.14*VdotN*cos_theta));
gl_FragColor = vec4((ambiant+diffus+spec)*L,1.0);
}