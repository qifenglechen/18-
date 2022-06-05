 //********************************颜色部分**************************************
#include <TimerOne.h> //申明库文件
//把TCS3200颜色传感器各控制引脚连到Arduino数字端口
//VCC--灰色   GND--紫色和红色
#define S0    3  //(蓝色)      物体表面的反射光越强，TCS3002D内置振荡器产生的方波频率越高，
#define S1    4  //（绿色）S0和S1的组合决定输出信号频率比例因子，比例因子为2%
                 //比率因子为TCS3200传感器OUT引脚输出信号频率与其内置振荡器频率之比
#define S2    5 //（黄色）S2和S3的组合决定让红、绿、蓝，哪种光线通过滤波器
#define S3    6//（橙色）
#define OUT    2  //（棕色）TCS3200颜色传感器输出信号连接到Arduino中断0引脚，并引发脉冲信号中断
                  //在中断函数中记录TCS3200输出信号的脉冲个数
#define LED    7  //控制TCS3200颜色传感器是否点亮LED灯
float g_SF[3];     //从TCS3200输出信号的脉冲数转换为RGB标准值的RGB比例因子
int   g_count = 0;  // 计算与反射光强相对应TCS3200颜色传感器输出信号的脉冲数
// 数组用于存储在1s内TCS3200输出信号的脉冲数，它乘以RGB比例因子就是RGB标准值
int   g_array[3];  
int   g_flag = 0;   // 滤波器模式选择顺序标志

//判断颜色相关变量
int i=0;

int y1;   //前进距离设置
int y2;

int k0;   //用于判断任务2中前往颜色区域是否存在物块，lv,bai,hong,hei,lan
int k1;
int k2;
int k;
 
// 初始化TSC3200各控制引脚的输入输出模式
//设置TCS3002D的内置振荡器方波频率与其输出信号频率的比例因子为2%
void TSC_Init()
{
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(OUT, INPUT);
  pinMode(LED, OUTPUT);
  digitalWrite(S0, LOW); 
  digitalWrite(S1, HIGH);
}
 //选择滤波器模式，决定让红、绿、蓝，哪种光线通过滤波器
void TSC_FilterColor(int Level01, int Level02)
{
  if(Level01 != 0)
    Level01 = HIGH;
  if(Level02 != 0)
    Level02 = HIGH;
  digitalWrite(S2, Level01);
  
  digitalWrite(S3, Level02);
}
 
//中断函数，计算TCS3200输出信号的脉冲数
void TSC_Count()
{
  g_count ++ ;
}
 
//定时器中断函数，每1s中断后，把该时间内的红、绿、蓝三种光线通过滤波器时，
//TCS3200输出信号脉冲个数分别存储到数组g_array[3]的相应元素变量中


void TSC_Callback()
{
  switch(g_flag)
  {
    case 0:
        Serial.println("->WB Start");
         TSC_WB(LOW, LOW);   //选择让红色光线通过滤波器的模式
         break;
    case 1:
         Serial.print("->Frequency R=");
         Serial.println(g_count);   //打印1s内的红光通过滤波器时，TCS3200输出的脉冲个数
         g_array[0] = g_count;    //存储1s内的红光通过滤波器时，TCS3200输出的脉冲个数
         TSC_WB(HIGH, HIGH);  //选择让绿色光线通过滤波器的模式
         break;
    case 2:
         Serial.print("->Frequency G=");
         Serial.println(g_count);   //打印1s内的绿光通过滤波器时，TCS3200输出的脉冲个数
         g_array[1] = g_count;    //存储1s内的绿光通过滤波器时，TCS3200输出的脉冲个数
         TSC_WB(LOW, HIGH);  //选择让蓝色光线通过滤波器的模式
         break;
 
    case 3:
         Serial.print("->Frequency B=");
         Serial.println(g_count);   //打印1s内的蓝光通过滤波器时，TCS3200输出的脉冲个数
         Serial.println("->WB End");
         g_array[2] = g_count;     //存储1s内的蓝光通过滤波器时，TCS3200输出的脉冲个数
         TSC_WB(HIGH, LOW);   //选择无滤波器的模式  
         break;
   default:
         g_count = 0;     //计数值清零
         break;
  }
}

//设置反射光中红、绿、蓝三色光分别通过滤波器时如何处理数据的标志
//该函数被TSC_Callback( )调用
void TSC_WB(int Level0, int Level1)    
{
  g_flag ++;     //输出信号计数标志
  TSC_FilterColor(Level0, Level1); //滤波器模式
  Timer1.setPeriod(1000000);     //设置输出信号脉冲计数时长1s
}

//***********************************************************************//

//**********HTTP://WWW.ECARE365.COM/
//****************舵机部分*************************************//

int shengjiang_servo=34;//定义数字接口34连接升降舵机信号线 34 红色
int gouzi_servo_s=35;//定义数字接口35连接升勾子上舵机信号线  蓝色
int gouzi_servo_x=36;//定义数字接口36连接勾子下舵机信号线  绿色
int jiazi_servo=37;  //定义数字接口37连接夹子舵机信号线  紫色

int myangle;//定义角度变量
int pulsewidth;//定义脉宽变量
//***********************************************************************

//************************步进电机部分**********************************//
const int lzzCLK =40;  //黑  
int DJ1State =LOW;            
int lzzEN=38;   //蓝       //左轮
int DIR1=LOW;
int lzzCW=39;  //绿HTTP://WWW.ECARE365.COM/



const int lzyCLK =44;    //红  
int DJ2State = LOW;            
int lzyEN=42;       //白      //右轮
int DIR2=LOW; 
int lzyCW=43;       //棕

long previous1 =0;        
long previous2 =0; 

long v1=80;   //时间直行、后退循迹速度    
long v2=80;     

long v5=160;   //前后传感器循迹速度
long v6=160;

long v7=200;  //转弯速度
long v8=200;

//偏移量修正值
int a=65; 
int b=115;
int c=135;
//后退量修正值
int d=130;//后灰度传感器
int f=160;//尾灰5度传感器
//*****************************************************************//
//***************灰度传感************************//
int QHDZ =28;  //前面左边传感器
int QHDY =29;  //前面右边传感器

int HHDZ =26;  //后面左边传感器
int HHDY =27;  //后面右边传感器

int HD1;
int HD2;
int HD3;
int HD4;
int HD5;
int HD6;

int HD7;  //后退循迹
int HD8;
int HD9;  //后退循迹
int HD10;
//**************************调用函数***********************************//

#include "going.h"
#include "gouzi.h"
#include "jiazi.h"
#include "shengjiang.h"
#include "xunji.h"
#include "yanse.h"
void setup() {
   //************电机（驱动板）模块**************//
   Serial.begin (9600);
   pinMode(lzzEN,OUTPUT);  
   pinMode(lzzCW,OUTPUT);  
   pinMode(lzzCLK,OUTPUT);  
   pinMode(lzyEN,OUTPUT);  
   pinMode(lzyCW,OUTPUT);
   pinMode(lzyCLK,OUTPUT);

  //定义循迹模块为输入模式
  pinMode(14,INPUT);  
  pinMode(15,INPUT);  
  pinMode(16,INPUT);
  pinMode(17,INPUT);
  pinMode(18,INPUT);
  pinMode(19,INPUT);
  
  pinMode(23,INPUT);
  pinMode(24,INPUT);

//设定舵机为输出模式
pinMode(shengjiang_servo,OUTPUT);//设定舵机接口为输出接口
pinMode(gouzi_servo_s,OUTPUT);//设定舵机接口为输出接口
//pinMode(gouzi_servo_x,OUTPUT);//设定舵机接口为输出接口
pinMode(jiazi_servo,OUTPUT);//设定出接口

//设置灰度传感输出接口
pinMode(QHDZ,INPUT);
pinMode(QHDY,INPUT);

pinMode(HHDZ,INPUT);
pinMode(HHDY,INPUT);

//颜色识别部分

TSC_Init();
  Timer1.initialize();   // defaulte is 1s
  Timer1.attachInterrupt(TSC_Callback); //设置定时器1的中断，中断调用函数为TSC_Callback()
  //设置TCS3200输出信号的上跳沿触发中断，中断调用函数为TSC_Count()
  attachInterrupt(0, TSC_Count, RISING);
 //  digitalWrite(LED, HIGH);//点亮LED灯5
 // delay(4000); //延时4s，以等待被测物体红、绿、蓝三色在1s内的TCS3200输出信号脉冲计数


  //通过白平衡测试，计算得到白色物体RGB值255与1s内三色光脉冲数的RGB比例因子
  g_SF[0] =0.12196;  //255.0/ g_array[0];    //红色光比例因子   //0.09020;
  g_SF[1] =0.12094; //255.0/ g_array[1];    //绿色光比例因子   //0.09763;
  g_SF[2] =0.09792;  //255.0/ g_array[2];    //蓝色光比例因子   //0.08139;
  //打印白平衡后的红、绿、蓝三色的RGB比例因子
  Serial.println(g_SF[0],5);
  Serial.println(g_SF[1],5);
  Serial.println(g_SF[2],5);
  //红、绿、蓝三色光分别对应的1s内TCS3200输出脉冲数乘以相应的比例因子就是RGB标准值
  //打印被测物体的RGB值
  for(int i=0; i<3; i++);
  Serial.println(int(g_array[i] * g_SF[i])); 
 }



//***************************************************************************************
//gouzi_servo1 控制勾子上下,设得角度越大，越往地上偏 
//gouzi_servo2 控制勾子左右  值越大越往左 极限：左—165    右—100
//jiazi 控制夹子  值越大越开，推荐值 开：160，合35
//shengjiang 控制升降舵机  值越大越下 极限：上—105，下—155

//sj_xunji(100);,sj_houtui_xunji(100) 100对应约4~5cm
//go_time(5000);  5000对应约4cm
//***********************主程序开始***************************

void loop()
{
 while(1){
  yanse();
 }
//******************初始化舵机位置******************//
gouzi_servo1(11);
//gouzi_servo2(145);
jiazi(170);
shengjiang(130);
//######################任务1开始，到C点夹C物块#################################//
  sj_xunji(1400);
  qhd_xunji();
  sj_xunji(20);//防止物块夹偏
  jiazi(90);//夹取物块

//#######################后退掉头回中心##########################//
  sj_xunji_houtui(250);//150,145
  houtui_hhd_xunji();     //白点回到中心
  sj_ht_xunji2(80);    
  
 //***********************识别C处物块颜色**************************//
  yanseC();
 //************************逻辑判断*************************//

 if (k1==1)    //如果C处物块是绿色,回到中心判断A处夹取的物块的颜色
{
     yanseA();   //识别去绿色区中夹取的A处物块颜色
  
     if(k0==2)  //白色
     {
      right_135();             //朝向E区域

      sj_xunji(200);     //到达E点
      qhd_xunji();
      sj_xunji(20);//防止物块夹偏HTTP://WWW.ECARE365.COM/


     jiazi(70);         //夹取物块
    

    sj_xunji_houtui(260);
    houtui_hhd_xunji();     //白点回到中心
    sj_ht_xunji2(50);
    houtui_hhd_xunji(); 
    sj_ht_xunji2(60);
    }
      else if(k0==3)  //红色
    {
      right_90();             //朝向E区域
  
      sj_xunji(200);     //到达E点
      qhd_xunji();
      sj_xunji(20);//防止物块夹偏
      
  
      jiazi(100);         //夹取物块
  
      sj_xunji_houtui(260);
      houtui_hhd_xunji();
      sj_ht_xunji2(50);//白点回到中心
      houtui_hhd_xunji(); 
      sj_ht_xunji2(60);
    }
     else if(k0==4)  //黑色
    {
     right_45();             //朝向E区域
     tingzhi(100);
    sj_xunji(200);     //到达E点
    qhd_xunji();
     sj_xunji(20);//防止物块夹偏
    //js_go_time(5000);

    jiazi(100);         //夹取物块
   tingzhi(100);


    sj_xunji_houtui(300);
    houtui_hhd_xunji();     //白点回到中心
     sj_ht_xunji2(50);
    houtui_hhd_xunji(); 
    sj_ht_xunji2(60);
    }
     else if(k0==5)  //蓝色,物块已经在中点那了
    {
      ;
    }
    yanseE();  //识别去蓝色区中夹取的E处物块颜色

    //执行完识别颜色的命令后，可以去F区域了
      if(k2==2)   //白色
    {
          left_90();            //朝向F区域
    }

    else if(k2==3)   //红色
    {
          left_135();             //朝向F区域
    }

     else if(k2==4)   //黑色
    {
          left_180();             //朝向F区域
    }

     else if(k2==5)   //蓝色
    {
         right_135();             //朝向F区域
    }
}
else if(k1==5) //如果C处物块是蓝色

{
  
  yanseE();   //识别去蓝色区中夹取的E处物块颜色

         if(k2==2)
         {           //如果K2为白色
    
          left_45();            //朝向A区域

          sj_xunji(120);     //到达A点
          qhd_xunji();
          sj_xunji(20);//防止物块夹偏
    

           jiazi(100);         //夹取物块 
    

           sj_xunji_houtui(200);
           houtui_hhd_xunji();   //白点处回到中心
           sj_ht_xunji2(50);
           houtui_hhd_xunji();  
            sj_ht_xunji2(60);
    }

        else if(k2==3)  //红色
    {
          left_90();             //朝向A区域

          sj_xunji(200);     //到达A点
          qhd_xunji();
          sj_xunji(20);//防止物块夹偏
          //js_go_time(5000);

       jiazi(100);         //夹取物块
    
        sj_xunji_houtui(200);
        houtui_hhd_xunji();     //白点回到中心
        sj_ht_xunji2(50);
        houtui_hhd_xunji(); 
          sj_ht_xunji2(60);
    }
    else if(k2==4)  //黑色
    {
         left_135();             //朝向A区域

      sj_xunji(200);     //到达A点
      qhd_xunji();
      sj_xunji(20);//防止物块夹偏
    

      jiazi(100);         //夹取物块
      

      sj_xunji_houtui(200);
      houtui_hhd_xunji();     //白点回到中心
      sj_ht_xunji2(50);
      houtui_hhd_xunji(); 
      sj_ht_xunji2(60);
    }
    else if(k2==5)
    {
          left_180();             //朝向A区域

    sj_xunji(200);     //到达A点
    qhd_xunji();
    sj_xunji(20);//防止物块夹偏
   

    jiazi(100);         //夹取物块
   

   sj_xunji_houtui(200);
   houtui_hhd_xunji();   //白点处回到中心
   sj_ht_xunji2(50);
   houtui_hhd_xunji(); 
    sj_ht_xunji2(50);
    }
    yanseA();//识别绿色区域中夹取的A处物块

      if(k0==1)
    {
         left_45();             //朝向F区域
    }

    else if(k0==2)
    {
          left_90();
    }

    else if(k0==3)
    {
          left_135();             //朝向F区域
    }

     else if(k0==4)
    {
          left_180();             //朝向F区域
    }

     else if(k0==5)
    {
         right_135();             //朝向F区域
    }
    
}
else  //如果C处物块为 白色，红色，黑色
{
  //前往A处夹取物块
             if(k1==2)
    {
          left_45();            //朝向A区域
    }

    else if(k1==3)
    {
          left_90();             //朝向A区域
    }

     else if(k1==4)
    {
          left_135();             //朝向A区域
    }

   sj_xunji(200);     //到达A点
   qhd_xunji();
   sj_xunji(20);//防止物块夹偏
   

    jiazi(100);         //夹取物块


     sj_xunji_houtui(200);
     houtui_hhd_xunji();  
     sj_ht_xunji2(50);      // sj_xunji_houtui(80);  //白点处回到中心
     houtui_hhd_xunji(); 
     sj_ht_xunji2(50);      

     yanseA();        //识别A处物块的颜色

if(k0==5)     //如果A处颜色是蓝色
   {
         yanseE0();   //识别E0处的物块，A区域已经没有物块
  
   }

else  if(k0==1)  //如果A处物块是绿色
   {
          left_180();             //朝向E区域

           sj_xunji(100);  //到达E点
           qhd_xunji();
           sj_xunji(20);//防止物块夹偏
         

         jiazi(100);         //夹取物块

         sj_xunji_houtui(200);
         houtui_hhd_xunji();  
         sj_ht_xunji2(50);
         houtui_hhd_xunji(); 
         sj_ht_xunji2(50);
         yanseE0();        //颜色识别
   }

else  if(k0==2)  //如果A处物块是白色
   {
        right_135();             //朝向E区域

          sj_xunji(100);  //到达E点
           qhd_xunji();
           sj_xunji(20);//防止物块夹偏
     

         jiazi(90);         //夹取物块

         sj_xunji_houtui(200);
         houtui_hhd_xunji();  
          sj_ht_xunji2(50);//回到中心
         houtui_hhd_xunji(); 
          sj_ht_xunji2(50);
        
         yanseE0();        //颜色识别
   }
else if(k0==3)   //如果A处物块是红色
   {
         right_90();             //朝向E区域

         sj_xunji(100);  //到达E点
         qhd_xunji();
           sj_xunji(20);//防止物块夹偏
        // js_go_time(5000);

         jiazi(100);         //夹取物块

         sj_xunji_houtui(200);
         houtui_hhd_xunji();  
        sj_ht_xunji2(50); //回到中心
         houtui_hhd_xunji(); 
           sj_ht_xunji2(50);
           
         yanseE0();        //颜色识别
   }
    else if(k0==4)  //如果A处物块是黑色
   {
         right_45();             //朝向E区域

         sj_xunji(100);  //到达E点
         qhd_xunji();
          sj_xunji(20);//防止物块夹偏
        

         jiazi(100);         //夹取物块

         sj_xunji_houtui(200);
         houtui_hhd_xunji();  
         sj_ht_xunji2(50);   //回到中心
         houtui_hhd_xunji(); 
         sj_ht_xunji2(50);
         
         yanseE0();        //颜色识别
   }

      if(k2==1)
    {
         left_45();             //朝向F区域
    }

    else if(k2==2)
    {
          left_90();            //朝向F区域
    }

    else if(k2==3)
    {
          left_135();             //朝向F区域
    }

     else if(k2==4)
    {
          left_180();             //朝向F区域
    }

     else if(k2==5)
    {
         right_135();             //朝向F区域
    }

}
tingzhi(100);

//***********************************任务一结束**************************//
//***********************************任务二开始**************************//


 // 到F区钩C处物块
   
     sj_xunji(680);//从中点到达F区外圈停止
     tingzhi(100);
    qhd_hxunji();
     sj_js_xunji(50);
     
     right_27();
    


//勾取物块，将物块放进夹子
     
     gouzi_servo1(50);
    gouzi_servo2(155);
     gouzi_servo1(110);
     gouzi_servo2(50);
     gouzi_servo1(10); 
     gouzi_servo2(135);  //物块向外

     jiazi(90);//夹子关闭
    
     back_time(100);//自己添加的 后退一点
     left_27();//转回直线状态


 //&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&回到中点&&&&&&&&&&&&&&&&&&&&&&&&&//
 sj_xunji_houtui(650);//后退到中点
tingzhi(100);
 houtui_hhd_xunji();
 sj_ht_xunji2(50);
 tingzhi(100);
 houtui_hhd_xunji();
 
//&&&&&&&&&&&&&&&&&&&&&&&&&前往G区勾取物块A&&&&&&&&&&&&&&&&&&&&&&&&&//
     
    left_90();

    
    sj_xunji(700);//从中点向G区出发
    
    
    qhd_hxunji();//从中点到达F区外圈停止
    sj_js_xunji(109);
    
   
    
    //开始勾取物块
    gouzi_servo1(50);//110,100,90,80,在50处时它很完美（初始化状态，使其能在其上方）
    gouzi_servo2(122);//钩子向外在物块上方
    gouzi_servo1(110);//向下勾取物块，钩子下降
     
    gouzi_servo2(160);//钩子再往外翻，往后去一点
    sj_xunji_houtui(60);
    
    shengjiang(40);//夹子往上升
    
    //gouzi_servo2(80);//钩子向里面放,对它进行缓冲
    gouzi_servo2(35);//钩子向里面放
    gouzi_servo1(62);//钩子往上一点，将物块放进去
    
    gouzi_servo2(110);//钩子再往外偏
    gouzi_servo1(88);//钩子往上来一点
    gouzi_servo2(35);//钩子再往里推
    gouzi_servo2(130);//出来
    gouzi_servo1(40);
    
    shengjiang(90);//夹子向下一点
    jiazi(135);//夹子打开一点
    
    shengjiang(130);//夹子完全下降
    jiazi(90);//夹子关紧
    
//************************回到中点**************************//
   sj_xunji_houtui(540);
   houtui_hhd_xunji();  
   sj_ht_xunji2(50); //回到中心sj_xunji_houtui(50); 
   houtui_hhd_xunji(); 
     sj_ht_xunji2(60);
    tingzhi(100);
  //********************颜色判断根据任务一******************************//
if (k0==1)
 {
     right_135();//到绿色区域
   
     sj_xunji(670);
     shengjiang(60); 
        
      qhd_hxunji();
      sj_txunji(50);//速度慢点，往前走
      shengjiang(90); //夹子下降一点
      
       jiazi(135);
       shengjiang(160);
       jiazi(90);
        houtui_qhd_xunji();     
         
       jiazi(160);   //打开夹子  

  sj_xunji_houtui(750);
  houtui_hhd_xunji();  
  sj_ht_xunji2(55); //回到中心
  houtui_hhd_xunji(); 
   sj_ht_xunji2(40); 


  left_45();            //朝向F区域
 }

else if(k0==2)
{
      left_180();

      sj_xunji(680);
      //打开夹子上升一定高度
      shengjiang(60); 
        
      qhd_hxunji();
      sj_txunji(50);
      shengjiang(85); //夹子下降一点
      
       jiazi(135);//夹子打开一点
       shengjiang(160);
       jiazi(90);
        houtui_qhd_xunji();     
         
       jiazi(160);   //打开夹子     

      sj_xunji_houtui(800);
      houtui_hhd_xunji();  
      sj_ht_xunji2(50);   //回到中心
      houtui_hhd_xunji(); 
      sj_ht_xunji2(60);
      left_90();
}

else if(k0==3)
{
  left_135();

  sj_xunji(670);   
  shengjiang(60);  //夹子上升一点

  qhd_hxunji();     
  sj_txunji(50);  
  shengjiang(90); //夹子下降一点
           
  jiazi(135);//夹子打开一点  
  shengjiang(160);   //夹子下降到底
  jiazi(90);//夹子夹紧
  houtui_qhd_xunji();//后退到黑线停止     
  jiazi(160);         //夹子打开   

  sj_xunji_houtui(720);
  houtui_hhd_xunji();  
  sj_ht_xunji2(50);   //回到中心
  houtui_hhd_xunji();
  //sj_ht_xunji2(60);
  
   left_135();//去向E区
}

else if(k0==4)
{
  left_90();

       sj_xunji(670);   
       shengjiang(60);//夹子上升一点
       
       
       qhd_hxunji();      



      qhd_hxunji();     
      sj_txunji(50);  
      shengjiang(90); //夹子下降一点
           
     jiazi(135);//夹子打开一点  
     shengjiang(160);   //夹子下降到底
     jiazi(90);//夹子夹紧
     houtui_qhd_xunji();//后退到黑线停止     
 
     jiazi(160);         //夹子打开   
      //jiazi(160);   //打开夹子     

      sj_xunji_houtui(720);
      houtui_hhd_xunji();  
      sj_ht_xunji2(50);  //回到中心
      houtui_hhd_xunji(); 
       sj_ht_xunji2(60);
      left_180();
}

else if(k0==5)
{
  left_45();

  sj_xunji(670);   
  shengjiang(60);  //夹子上升一点

  qhd_hxunji();     
  sj_txunji(50); 
  shengjiang(90); //夹子下降一点
           
  jiazi(135);   //夹子打开一点 
  shengjiang(160);   //夹子下降到底
  jiazi(90);//夹子夹紧一点
  houtui_qhd_xunji();
  //back_time(1500);   //后退一点
 

  //jiazi(35);         //夹子夹紧
  //sj_xunji_houtui(60);
  jiazi(160);         //夹子打开   

  sj_xunji_houtui(720);
  houtui_hhd_xunji();  
  sj_ht_xunji2(50);  //回到中心
  houtui_hhd_xunji();
   sj_ht_xunji2(80); 
   right_135();//朝向F区
}
//********************到达F区域夹B***********************//

//到F区域
sj_xunji(690);
qhd_hxunji();
sj_js_xunji(108);
//钩子钩物块

gouzi_servo2(125);//钩子向外在物块上方
gouzi_servo1(111);//向下勾取物块，钩子下降
gouzi_servo2(35);//钩子再往里偏
gouzi_servo1(11);  
gouzi_servo2(130);

jiazi(90);//关闭夹子


 //jiazi(110);
 // gouzi_servo2(35);//钩子向里面放
   // gouzi_servo1(50);//钩子往上一点，将物块放进去

//*******************退回中点*******************//

  sj_xunji_houtui(700);
  houtui_hhd_xunji();  
   sj_ht_xunji2(55); //回到中心sj_xunji_houtui(50); 
  houtui_hhd_xunji();
    sj_ht_xunji2(50); 
//*******************到达G区夹物块B********************//

  left_90();
  
  sj_xunji(550);//从中点到达F区外圈停止
  //sj_js_xunji(150);//可能需要删减
   qhd_hxunji();//到外圈停止
   right_20();//右转一点,后面貌似可以直接用减速时间直行js_go_time(5000);
   sj_js_xunji(104);//开始勾取物块
   shengjiang(50);//将夹子上升到一定高度
   gouzi_servo2(151);  //钩子放在物块上方
   gouzi_servo1(120);//钩子往下钩物块
   js_back_time(6000);
   gouzi_servo2(35);
   gouzi_servo1(60);

    gouzi_servo2(130);
//将物块往里打
    gouzi_servo1(111);
    gouzi_servo2(45);
    gouzi_servo2(130);
    gouzi_servo1(50);
    
    shengjiang(90);//夹子向下一点
    jiazi(138);//夹子打开一点点

    shengjiang(130);//夹子完全下降
    jiazi(90);//夹子关闭

    back_time(1000);
    left_24();//转回直线状态
    //************************回到中点**************************//
   sj_xunji_houtui(600);
   houtui_hhd_xunji();  
   sj_ht_xunji2(66); //回到中心sj_xunji_houtui(50); 
   houtui_hhd_xunji(); 
   //sj_ht_xunji2(45);
//**************************判断B处颜色***********************
  
  yanse2();
  
//*************************朝向F区域****************************
  if(k==1)
  {
    left_45();
  }

  else if(k==2)
  {
    left_90();
  }
  else if(k==3)
  {
    left_135();
  }
  else if(k==4)
  {
    left_180();
  }
  else if(k==5)
  {
    right_135();
  }
  //*********************************到达F区域夹C********************//
     sj_xunji(650);//从中点到达F区外圈停止

     qhd_hxunji();
     sj_js_xunji(180);
      

     
      gouzi_servo2(119);//钩子勾到物块上方
     
      gouzi_servo1(120); 
      tingzhi(100);
      js_back_time(10000);//往后退一点再钩物块,防止撞到
      gouzi_servo2(40);
      gouzi_servo1(11);
      gouzi_servo2(130);
      jiazi(90);  




  
   
      sj_xunji_houtui(780);
     houtui_hhd_xunji();  
     sj_ht_xunji2(66);   //回到中心
     houtui_hhd_xunji();  
     sj_ht_xunji2(70); 
//*************************前往G区勾取物块C***************************
     left_90();

     gouzi_servo1(50);
     sj_xunji(540);//从中点到达F区外圈停止
     qhd_hxunji();
     sj_js_xunji(160);
     right_17();

     shengjiang(60);
//勾取物块
     gouzi_servo2(142);
     gouzi_servo1(109);
     gouzi_servo2(40);
     gouzi_servo1(60);
     gouzi_servo2(130);
//再将物块往里推推
     gouzi_servo1(106);
     gouzi_servo2(45);
     gouzi_servo2(130);
//将两个物块合在一起
    shengjiang(90);//夹子向下一点
    jiazi(135);//夹子打开一点
    
    shengjiang(130);//夹子完全下降
    jiazi(90);//夹子关紧  
    left_20();

//************************回到中心位置************************
   sj_xunji_houtui(600);
   houtui_hhd_xunji();  
   sj_ht_xunji2(55); //回到中心sj_xunji_houtui(50); 
   houtui_hhd_xunji(); 
   sj_ht_xunji2(40);
//***********************颜色判断根据任务一******************************
if (k0==1)
 {
     right_135();//到绿色区域
   
     sj_xunji(670);
     shengjiang(60); 
        
      qhd_hxunji();
      sj_txunji(50);//速度慢点，往前走
      shengjiang(90); //夹子下降一点
      
       jiazi(135);
       shengjiang(160);
       jiazi(90);
        houtui_qhd_xunji();     
         
       jiazi(160);   //打开夹子  

  sj_xunji_houtui(700);
  houtui_hhd_xunji();  
  sj_ht_xunji2(50); //回到中心
  houtui_hhd_xunji(); 
  
  sj_ht_xunji2(45);
  left_45();            //朝向F区域
 }

else if(k0==2)
{
      left_180();

      sj_xunji(680);
      //打开夹子上升一定高度
      shengjiang(60); 
        
      qhd_hxunji();
      sj_txunji(50);
      shengjiang(85); //夹子下降一点
      
       jiazi(135);//夹子打开一点
       shengjiang(160);
       jiazi(90);
        houtui_qhd_xunji();     
         
       jiazi(160);   //打开夹子     

      sj_xunji_houtui(700);
      houtui_hhd_xunji();  
      sj_ht_xunji2(50);   //回到中心
      houtui_hhd_xunji(); 
      sj_ht_xunji2(40);
      
      left_90();
}

else if(k0==3)
{
  left_135();

  sj_xunji(670);   
  shengjiang(60);  //夹子上升一点

  qhd_hxunji();     
  sj_txunji(50);  
  shengjiang(90); //夹子下降一点
           
  jiazi(135);//夹子打开一点  
  shengjiang(160);   //夹子下降到底
  jiazi(90);//夹子夹紧
  houtui_qhd_xunji();//后退到黑线停止     


  jiazi(160);         //夹子打开   

  sj_xunji_houtui(720);
  houtui_hhd_xunji();  
  sj_ht_xunji2(50);   //回到中心
  houtui_hhd_xunji();
  sj_ht_xunji2(40);
  
   left_135();//去向E区
}

else if(k0==4)
{
  left_90();

       sj_xunji(680);   
       shengjiang(60);//夹子上升一点
       
       
       qhd_hxunji();      



      qhd_hxunji();     
      sj_txunji(50);  
      shengjiang(90); //夹子下降一点
           
     jiazi(135);//夹子打开一点  
     shengjiang(160);   //夹子下降到底
     jiazi(90);//夹子夹紧
     houtui_qhd_xunji();//后退到黑线停止     
 
     jiazi(160);         //夹子打开   
      //jiazi(160);   //打开夹子     

      sj_xunji_houtui(700);
      houtui_hhd_xunji();  
      sj_ht_xunji2(50);  //回到中心
      houtui_hhd_xunji(); 

      left_180();
}

else if(k0==5)
{
  left_45();

  sj_xunji(670);   
  shengjiang(60);  //夹子上升一点

  qhd_hxunji();     
  sj_txunji(50); 
  shengjiang(90); //夹子下降一点
           
  jiazi(135);   //夹子打开一点 
  shengjiang(160);   //夹子下降到底
  jiazi(90);//夹子夹紧一点
  houtui_qhd_xunji();
  //back_time(1500);   //后退一点
 

  //jiazi(35);         //夹子夹紧
  //sj_xunji_houtui(60);
  jiazi(160);         //夹子打开   

  sj_xunji_houtui(600);
  houtui_hhd_xunji();  
  sj_ht_xunji2(50);  //回到中心
  houtui_hhd_xunji();
     sj_ht_xunji2(50);
      
   right_135();//朝向F区
}
//******************************到达F区域夹E*******************************
     sj_xunji(550);
     qhd_hxunji();
     sj_js_xunji(150);
     right_15();

     
      gouzi_servo2(123);//钩子勾到物块上方
     
      gouzi_servo1(120); 
     // tingzhi(100);
      //js_back_time(10000);//往后退一点再钩物块
      gouzi_servo2(40);
      gouzi_servo1(11);
      gouzi_servo2(130);
      jiazi(90);  
      left_16();// 回到黑线
 //*****************************回到中心*******************************
    sj_xunji_houtui(700);
    houtui_hhd_xunji();  
    sj_ht_xunji2(50);  //回到中心
    houtui_hhd_xunji();
    sj_ht_xunji2(60);
//**************************到达G区勾取物块***************************
  left_90();
  
     gouzi_servo1(50);
     sj_xunji(540);//从中点到达F区外圈停止
     shengjiang(60);
     qhd_hxunji();
     sj_js_xunji(210);
    // right_17();
     //sj_js_xunji(100);

     
//勾取物块
     gouzi_servo2(135);
     gouzi_servo1(120);
     //gouzi_servo2(140);
     //js_back_time(7800);
     tingzhi(100);
     gouzi_servo2(40);
     gouzi_servo1(60);
     gouzi_servo2(130);
//再将物块往里推推
     gouzi_servo1(111);
     gouzi_servo2(45);
     gouzi_servo2(130);
//将两个物块合在一起
    shengjiang(90);//夹子向下一点
    jiazi(135);//夹子打开一点
    
    shengjiang(130);//夹子完全下降
    jiazi(90);//夹子关紧  
  
//************************后退到中心*******************************//
    sj_xunji_houtui(700);
    houtui_hhd_xunji();  
    sj_ht_xunji2(50);  //回到中心
    houtui_hhd_xunji();
    sj_ht_xunji2(45);
//***********************根据任务一判别颜色*******************//
if (k0==1)
 {
     right_135();//到绿色区域
   
     sj_xunji(670);
     shengjiang(60); 
        
      qhd_hxunji();
      sj_txunji(50);//速度慢点，往前走
      shengjiang(90); //夹子下降一点
      
       jiazi(135);
       shengjiang(160);
       jiazi(90);
        houtui_qhd_xunji();     
         
       jiazi(160);   //打开夹子  

  sj_xunji_houtui(700);
  houtui_hhd_xunji();  
  sj_ht_xunji2(50); //回到中心
  houtui_hhd_xunji(); 
 sj_ht_xunji2(45);
  left_45();            //朝向F区域
 }

else if(k0==2)
{
      left_180();

      sj_xunji(680);
      //打开夹子上升一定高度
      shengjiang(60); 
        
      qhd_hxunji();
      sj_txunji(50);
      shengjiang(85); //夹子下降一点
      
       jiazi(135);//夹子打开一点
       shengjiang(160);
       jiazi(90);
        houtui_qhd_xunji();     
         
       jiazi(160);   //打开夹子     

      sj_xunji_houtui(700);
      houtui_hhd_xunji();  
      sj_ht_xunji2(50);   //回到中心
      houtui_hhd_xunji(); 

      left_90();
}

else if(k0==3)
{
  left_135();

  sj_xunji(670);   
  shengjiang(60);  //夹子上升一点

  qhd_hxunji();     
  sj_txunji(50);  
  shengjiang(90); //夹子下降一点
           
  jiazi(135);//夹子打开一点  
  shengjiang(160);   //夹子下降到底
  jiazi(90);//夹子夹紧
  houtui_qhd_xunji();//后退到黑线停止     
 // back_time(1500);   //后退一点


 // jiazi(35);         //夹子夹紧
  //sj_xunji_houtui(60);
  jiazi(160);         //夹子打开   

  sj_xunji_houtui(720);
  houtui_hhd_xunji();  
  sj_ht_xunji2(50);   //回到中心
  houtui_hhd_xunji();

   left_135();//去向E区
}

else if(k0==4)
{
  left_90();

       sj_xunji(670);   
       shengjiang(60);//夹子上升一点
       
       
       qhd_hxunji();      



      qhd_hxunji();     
      sj_txunji(50);  
      shengjiang(90); //夹子下降一点
           
     jiazi(135);//夹子打开一点  
     shengjiang(160);   //夹子下降到底
     jiazi(90);//夹子夹紧
     houtui_qhd_xunji();//后退到黑线停止     
 
     jiazi(160);         //夹子打开   
      //jiazi(160);   //打开夹子     

      sj_xunji_houtui(700);
      houtui_hhd_xunji();  
      sj_ht_xunji2(50);  //回到中心
      houtui_hhd_xunji(); 

      left_180();
}

else if(k0==5)
{
  left_45();

  sj_xunji(670);   
  shengjiang(60);  //夹子上升一点

  qhd_hxunji();     
  sj_txunji(50); 
  shengjiang(90); //夹子下降一点
           
  jiazi(135);   //夹子打开一点 
  shengjiang(160);   //夹子下降到底
  jiazi(90);//夹子夹紧一点
  houtui_qhd_xunji();
  //back_time(1500);   //后退一点
 

  //jiazi(35);         //夹子夹紧
  //sj_xunji_houtui(60);
  jiazi(160);         //夹子打开   

  sj_xunji_houtui(700);
  houtui_hhd_xunji();  
  sj_ht_xunji2(50);  //回到中心
  houtui_hhd_xunji();

   right_135();//朝向F区
}
//*******************************到F区勾取物块D*****************************//
      sj_xunji(580);//从中点到达F区外圈停止

     qhd_hxunji();
     sj_xunji(320);
      jiazi(90);
//***************************回到中心****************************//
      js_back_time(12000);
      sj_xunji_houtui(900);
      houtui_hhd_xunji();  
      sj_ht_xunji2(50);   //回到中心
      houtui_hhd_xunji();
      sj_ht_xunji2(50);   //回到中心
      houtui_hhd_xunji();
//*************************************到G区勾取物块D**************************//
      left_90();
       sj_xunji(580);//从中点到达F区外圈停止

     qhd_hxunji();
     sj_xunji(320);
      jiazi(90);
//***************************回到中心****************************
      js_back_time(12000);
      sj_xunji_houtui(900);
      houtui_hhd_xunji();  
      sj_ht_xunji2(50);   //回到中心
      houtui_hhd_xunji();
      sj_ht_xunji2(50);   //回到中心
      houtui_hhd_xunji();
//*****************************颜色识别B***************************************//
     yanse2();
//####################################任务2结束###########################//
//*********************************回到起点*********************************//
 left_45();
 sj_xunji(1100);
 tingzhi(30000);    
  //**************************比赛结束*******************************//
} 
