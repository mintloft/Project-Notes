# OpenGLLearn
a opengl learn project
所有的依赖都包含在项目工程里，并且已经配置好路径，原则上可以直接编译



     calc    ColorA         ColorB
1      x      ==x+0           0 
2      y       x+0          ==x+0+y
3      z      ==x+0+y+z      x+0+y
4      w      x+0+y+z       ==x+0+y+z+w




1、objects--->Gbuffer
2、light(Gbuffer) + 0 -->color
   light(Gbuffer) + lastColor --->color
   light(Gbuffer) + lastColor --->color
    ....
   light(Gbuffer) + lastColor --->final color
3、final color ---> rt[screen, texture]





