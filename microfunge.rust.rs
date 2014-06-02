#[v]/*                      This is MicroFunge,
11<                               a minimalist BeFunge-93 interpreter ;-)    v*/
extern crate rand;// > 000p>:00g::45*4*1-`#v_1+00p\g,vp0010,*75              <
use std::io::{File//   >  #^                        #<88*89*1-64*p     ^
,stdio};use std::os/*^_^# ,*25  !`*64:+1$$$<*/;static w:int= 80;static h:int=25;
struct State{s:Vec<int>,x:int,y:int,a:int,b:int}impl State{fn p(&mut self,i:int)
{self.s.push(i)}fn q(&mut self)->int{match self.s.pop(){Some(i)=>i,_=>0}}fn t(&
mut self){self.x+=w+self.a;self.x%=w;self.y+=h+self.b;self.y %= h;}}fn main(){
let mut z=[[32u8,..w],..h];let mut s:State=State{s:Vec::new(),x:0,y:0,a:1,b:0};
let(mut t,mut u,mut m)=(0,0,false);{let mut f=match File::open(&Path::new(os::
args()[1])){Ok(f)=>f,_=>fail!()};while t<h{match f.read_u8(){Err(_)=>break,Ok(10
)=>{t+=1;u=0},Ok(b)=>if u<w{z[t][u]=b;u+=1}}}}loop{let c=z[s.y][s.x];if m{if c==
34{m=false}else{s.p(c as int)}}else{match c{32=>{},43=>{t=s.q()+s.q();s.p(t)},45
=>{t=s.q();t=s.q()-t;s.p(t)},42=>{t=s.q()*s.q();s.p(t)},47=>{t=s.q();t=s.q()/t;s
.p(t)},37=>{t=s.q();t=s.q()%t;s.p(t)},33=>{t=s.q();s.p((t==0)as int)},62=>{s.a=1
;s.b=0},60=>{s.a=-1;s.b=0},94=>{s.a=0;s.b=-1},118=>{s.a=0;s.b=1},96=>{t=s.q();u=
s.q();s.p((u>t)as int)},124=>{s.a=0;s.b=if s.q()==0{1}else{-1}},95=>{s.b=0;s.a=
if s.q()==0{1}else{-1}},35=>s.t(),63=>{t=rand::random();s.a=(t&1)*2-1;s.b=(t>>1&
2)-1;},92=>{t=s.q();u=s.q();s.p(t);s.p(u);},36=>{s.q();},58=>{t=s.q();s.p(t);s.p
(t);},112=>match(s.q(),s.q()){(u@0..h,t@0..w)=>z[u][t]=s.q()as u8,_=>{}},103=>{t
=match(s.q(),s.q()){(u@0..h,t@0..w)=>z[u][t]as int,_=>32};s.p(t)},d@48..57=>s.p(
d as int-48),34=>m=true,44=>print!("{}",s.q()as u8 as char),46=>print!("{}",s.q(
)),126=>{match stdio::stdin_raw().read_u8(){Ok(c)=>s.p(c as int),_=>{}}},38=>{
match stdio::stdin().read_line(){Ok(l)=>match from_str(l){Some(i)=>s.p(i)
,_=>{}},_=>{}}},64=>break,_=>fail!()}}s.t();}}//             by vojtech kral.hk
