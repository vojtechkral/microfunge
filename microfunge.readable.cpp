#include <iostream>
#include <fstream>
#include <stack>
#include <cstdlib>
#include <cstring>
#include <ctime>

typedef long i;

using namespace std;

i x, y, a=1, b, t, u, m;
const i w=80, h=25;
stack<i> s;

unsigned char z[h][w];

i p(i x){s.push(x);}
i q(){i t;return s.size()?(t=s.top(),s.pop(),t):0;}

i op_nop(){}
i op_add(){p(q()+q());}
i op_sub(){p((t=q(),q()-t));}
i op_mul(){p(q()*q());}
i op_div(){p((t=q(),q()/t));}
i op_mod(){p((t=q(),q()%t));}
i op_not(){p(!q());}
i op_right(){a=1;b=0;}
i op_left(){a=-1;b=0;}
i op_up(){a=0;b=-1;}
i op_down(){a=0;b=1;}
i op_greater(){p((t=q(),q()>t));}
i op_if_vert(){a=0;b=q()?-1:1;}
i op_if_horiz(){b=0;a=q()?-1:1;}
i op_trampoline(){x+=w+a;x%=w;y+=h+b;y%=h;}
i op_rand(){t=rand();a=(t&1)*2-1;b=(t>>1&2)-1;}
i op_swap(){t=q();u=q();p(t);p(u);}
i op_duplicate(){t=q();p(t);p(t);}
i op_put(){u=q();t=q();(u|t)<0||u<h&&t<w&&(z[u][t]=q());}
i op_get(){u=q();t=q();p((u|t)>=0&&u<h&&t<w?z[u][t]:32);}
i op_digit(){p(z[y][x]-48);}
i op_string(){m=1;}
i op_out_c(){cout<<(char)q()<<flush;}
i op_out_i(){cout<<q()<<flush;}
i op_in_i(){cin>>t;p(t);}
i op_in_c(){p(cin.get());}
i op_bad(){exit(1);}
i op_exit(){exit(0);}


typedef i (*Op)();

struct SOp_Bad
{
	Op op = op_bad;
};

struct SOp_Digit
{
	Op op = op_digit;
};

struct SOp
{
	Op op;
};

struct Op_All
{
	SOp_Bad a[32];  // 31
	SOp b[16] = { {op_nop}, {op_not}, {op_string}, {op_trampoline}, {q}, {op_mod}, {op_in_i}, {op_bad}, {op_bad}, {op_bad}, {op_mul},
	              {op_add}, {op_out_c}, {op_sub}, {op_out_i}, {op_div} };  // 47
	SOp_Digit c[10];  // 57
	SOp d[7] = { {op_duplicate}, {op_bad}, {op_left}, {op_bad}, {op_right}, {op_rand}, {op_exit} };  // 64
	SOp_Bad e[27];  // 91
	SOp f[5] = { {op_swap}, {op_bad}, {op_up}, {op_if_horiz}, {op_greater} };  // 96
	SOp_Bad g[6];  // 102
	SOp h[1] = { {op_get} };  // 103
	SOp_Bad w[8];  // 111
	SOp x[1] = { {op_put} };  // 112
	SOp_Bad y[5];  // 117
	SOp z[9] = { {op_down}, {op_bad}, {op_bad}, {op_bad}, {op_bad}, {op_bad}, {op_if_vert}, {op_bad}, {op_in_c} };  // 126
	SOp_Bad m[129];  // 255
} op_all;

int main(int, char**d)
{
	y=b=t=u=m=0;
	srand(time(0));
	memset(z, 32, w*h);

	fstream f(d[1]);
	f.good()||op_bad();

	for(;(x = f.get(), f.good() && t < h);)
	{
		if (x == '\n' || (x == '\r' && f.peek() != '\n'))
		{
			t++; u = 0;
		}
		else if (x != '\r')
		{
			if (u < w) z[t][u++] = x;
		}
	}

	f.close();

	x=0;
	for(;;)
	{
		i c = z[y][x];

		if (m)
		{
			if (c != 34) p(c);
			else m = 0;
		} else
		{
			((SOp*)&op_all)[c].op();
		}

		op_trampoline();
	}
}
