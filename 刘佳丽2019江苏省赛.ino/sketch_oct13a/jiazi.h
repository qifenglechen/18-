void servopulse3(int jiazi_servo,int myangle)//定义一个脉冲函数
{
pulsewidth=(myangle*11)+500;//将角度转化为500-2480 的脉宽值
digitalWrite(jiazi_servo,HIGH);//将舵机接口电平至高
delayMicroseconds(pulsewidth);//延时脉宽值的微秒数
digitalWrite(jiazi_servo,LOW);//将舵机接口电平至低
delay(20-pulsewidth/1000);
}

void jiazi(int x3)
{
  
{
for(int i=0;i<=50;i++) //给予舵机足够的时间让它转到指定角度
servopulse3(jiazi_servo,x3);//引用脉冲函数
}

}
