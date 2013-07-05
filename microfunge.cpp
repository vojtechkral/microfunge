#/*3<         This is MicroFunge, a minimalist BeFunge-93 interpreter ;-)    v*/
#include <iostream>
#include <fstream>//                                (c)2013 Vojtech Kral
#include <stack>
#include <cstdlib>// > 000p>:00g::45*4*1-`#v_1+00p\g,vp0010,*75              <
#include <cstring>//   >  #^                        #<                         ^
#include <ctime>  // ^_^# ,*25  !`*64:+1$$$<
typedef long int i;using namespace std;const i w=80,h=25;i x,y=0,a=1,b=0,t=0,u=0
,m=0;stack<i>s;unsigned char z[h][w];i p(i x){s.push(x);}i q(){i t;return s.size
()?(t=s.top(),s.pop(),t):0;}i D(){p(q()*q());}i A(){}i B(){p(q()+q());}i C(){p((
t=q(),q()-t));}i E(){p((t=q(),q()/t));}i G(){p(!q());}i H(){a=1;b=0;}i F(){p((t=
q(),q()%t));}i I(){a=-1;b=0;}i J(){a=0;b=-1;}i V(){m=1;}i L(){p((t=q(),q()>t));}
i M(){a=0;b=q()?-1:1;}i N(){b=0;a=q()?-1:1;}i O(){x+=w+a;x%=w;y+=h+b;y%=h;}i P()
{t=rand();a=(t&1)*2-1;b=(t>>1&2)-1;}i Q(){t=q();u=q();p(t);p(u);}i R(){t=q();p(t
);p(t);}i S(){u=q();t=q();(u|t)<0||u<h&&t<w&&(z[u][t]=q());}i O2(){cout<<(char)q
()<<flush;}i U(){p(z[y][x]-48);}i T(){u=q();t=q();p((u|t)>=0&&u<h&&t<w?z[u][t]:
32);}i O3(){cout<<q()<<flush;}i W(){cin>>t;p(t);}i X(){p(cin.get());}i Y(){exit(
1);}i Z(){exit(0);}typedef i (*o)();struct j{o _;};struct k{o _=Y;};i K(){a=0;b=
1;}struct l{o _=U;};struct{k a[32];j b[16]={{A},{G},{V},{O},{q},{F},{W},{Y},{Y},
{Y},{D},{B},{O2},{C},{O3},{E}};l c[10];j d[7]={{R},{Y},{I},{Y},{H},{P},{Z}};k e[
27];j f[5]={{Q},{Y},{J},{N},{L}};k g[6];j h[1]={{T}};k w[8];j x[1]={{S}};k y[5];
j z[9]={{K},{Y},{Y},{Y},{Y},{Y},{M},{Y},{X}};k m[129];o operator[](i x){return((
j*)this)[x]._;}}g;int main(int,char**d){srand(time(0));memset(z,32,w*h);fstream
f(d[1]);f.good()||Y();for(;(x=f.get(),f.good()&&t<h);)x^10?(u<w?z[t][u++]=x:0):(
t++,u=0);f.close();x=0;for(;;){i j = z[y][x];m?j^34?p(j):m=0:(*g[j])();O();}}//@
