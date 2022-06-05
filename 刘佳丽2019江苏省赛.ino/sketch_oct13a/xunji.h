/*小车向前直行，在向前循迹中调用*/
void go()
{
  digitalWrite(lzzCW, HIGH); //转向控制
  digitalWrite(lzyCW, LOW);

  for (long i = 0; i <100; i++)
  {
    digitalWrite(lzzEN, LOW);
    dianji1();
    digitalWrite(lzyEN, LOW);
    dianji2();
  }
}
/*小车向后移动，在后退循迹中调用*/
void back()
{
  digitalWrite(lzzCW, LOW); //转向控制
  digitalWrite(lzyCW, HIGH);

  for (long i = 0; i <100; i++)
  {
    digitalWrite(lzzEN, LOW);
    dianji1();
    digitalWrite(lzyEN, LOW);
    dianji2();

  }
}
/*循迹减速中的向前直行（速度120）*/
void go1()
{
  digitalWrite(lzzCW, HIGH); //转向控制
  digitalWrite(lzyCW, LOW);

  for (long i = 0; i <100 ; i++)
  {
    digitalWrite(lzzEN, LOW);
    dianji5();
    digitalWrite(lzyEN, LOW);
    dianji6();

  }
}


/*可以安排多少时间直行*/
void go_time(long n)
{
  digitalWrite(lzzCW, HIGH); //转向控制
  digitalWrite(lzyCW, LOW);

  for (long i = 0; i < n; i++)
  {
    digitalWrite(lzzEN, LOW);
    dianji1();
    digitalWrite(lzyEN, LOW);
    dianji2();

  }
}
/*减速时间直行*/
void js_go_time(long n)
{
  digitalWrite(lzzCW, HIGH); //转向控制
  digitalWrite(lzyCW, LOW);

  for (long i = 0; i < n; i++)
  {
    digitalWrite(lzzEN, LOW);
    dianji5();
    digitalWrite(lzyEN, LOW);
    dianji6();

  }
}
/*时间后退*/
void back_time(long n)
{
  digitalWrite(lzzCW, LOW); //转向控制
  digitalWrite(lzyCW, HIGH);

  for (long i = 0; i < n; i++)
  {
    digitalWrite(lzzEN, LOW);
    dianji1();
    digitalWrite(lzyEN, LOW);
    dianji2();

  }
}
//减速时间后退
void js_back_time(long n)
{
  digitalWrite(lzzCW, LOW); //转向控制
  digitalWrite(lzyCW, HIGH);

  for (long i = 0; i < n; i++)
  {
    digitalWrite(lzzEN, LOW);
    dianji5();
    digitalWrite(lzyEN, LOW);
    dianji6();
}
  
}
//************************左拐弯********************
void left_16()
 {
  digitalWrite(lzzCW, HIGH); //转向控制
  digitalWrite(lzyCW, HIGH);

  for (long i = 0; i <9881; i++)//18400
  {
    digitalWrite(lzzEN, LOW);
    dianji7();
    digitalWrite(lzyEN, LOW);
    dianji8();
  }  
}

void left_20()
 {
  digitalWrite(lzzCW, HIGH); //转向控制
  digitalWrite(lzyCW, HIGH);

  for (long i = 0; i <12355; i++)//18400,25500
  {
    digitalWrite(lzzEN, LOW);
    dianji7();
    digitalWrite(lzyEN, LOW);
    dianji8();
  }  
 }

 
void left_24()
 {
  digitalWrite(lzzCW, HIGH); //转向控制
  digitalWrite(lzyCW, HIGH);

  for (long i = 0; i <14822; i++)//18400,25500
  {
    digitalWrite(lzzEN, LOW);
    dianji7();
    digitalWrite(lzyEN, LOW);
    dianji8();
  }  
 }

 
 void left_27()
 {
  digitalWrite(lzzCW, HIGH); //转向控制
  digitalWrite(lzyCW, HIGH);

  for (long i = 0; i <16675; i++)//18400,25500
  {
    digitalWrite(lzzEN, LOW);
    dianji7();
    digitalWrite(lzyEN, LOW);
    dianji8();
  }  
 }

 
void left_30()
 {
  digitalWrite(lzzCW, HIGH); //转向控制
  digitalWrite(lzyCW, HIGH);

  for (long i = 0; i <18533; i++)//18400,25500
  {
    digitalWrite(lzzEN, LOW);
    dianji5();
    digitalWrite(lzyEN, LOW);
    dianji6();
  }  
 }


void left_45()
{
  digitalWrite(lzzCW, HIGH); //转向控制
  digitalWrite(lzyCW, HIGH);

  for (long i = 0; i <27700; i++)
  {
    digitalWrite(lzzEN, LOW);
    dianji5();
    digitalWrite(lzyEN, LOW);
    dianji6();
  }  
}


void left_90()
{
  digitalWrite(lzzCW, HIGH); //转向控制
  digitalWrite(lzyCW,HIGH);

  for (long i = 0; i <48000; i++)  //55300,56800，54300减两度+2
  {
    digitalWrite(lzzEN, LOW);
    dianji5();
    digitalWrite(lzyEN, LOW);
    dianji6();
  } 
}


void left_135()
{
  digitalWrite(lzzCW,HIGH); //转向控制
  digitalWrite(lzyCW, HIGH);

  for (long i = 0; i <74800; i++)//80200+10
  {
    digitalWrite(lzzEN, LOW);
    dianji5();
    digitalWrite(lzyEN, LOW);
    dianji6();
  }  
}


void left_180()
{
  digitalWrite(lzzCW, HIGH); //转向控制
  digitalWrite(lzyCW, HIGH);

  for (long i = 0; i <101500; i++)//107200+5
  {
    digitalWrite(lzzEN, LOW);
    dianji5();
    digitalWrite(lzyEN, LOW);
    dianji6();
  }  

}

//************************右转弯**************************
void right_15()
 {
  digitalWrite(lzzCW, LOW); //转向控制
  digitalWrite(lzyCW, LOW);

  for (long i = 0; i <9264; i++)//18400
  {
    digitalWrite(lzzEN, LOW);
    dianji7();
    digitalWrite(lzyEN, LOW);
    dianji8();
  }  
}

void right_17()
 {
  digitalWrite(lzzCW, LOW); //转向控制
  digitalWrite(lzyCW, LOW);

  for (long i = 0; i <10499; i++)//18400
  {
    digitalWrite(lzzEN, LOW);
    dianji7();
    digitalWrite(lzyEN, LOW);
    dianji8();
  }  
}

void right_20()
 {
  digitalWrite(lzzCW, LOW); //转向控制
  digitalWrite(lzyCW, LOW);

  for (long i = 0; i <12355; i++)//18400
  {
    digitalWrite(lzzEN, LOW);
    dianji5();
    digitalWrite(lzyEN, LOW);
    dianji6();
  }  
}

void right_24()
 {
  digitalWrite(lzzCW, LOW); //转向控制
  digitalWrite(lzyCW, LOW);

  for (long i = 0; i <14822; i++)//18400
  {
    digitalWrite(lzzEN, LOW);
    dianji7();
    digitalWrite(lzyEN, LOW);
    dianji8();
  }  
}

void right_27()
{
   digitalWrite(lzzCW, LOW); //转向控制
   digitalWrite(lzyCW, LOW);

   for (long i = 0; i <16675; i++)//18400,25500
  {
    digitalWrite(lzzEN, LOW);
    dianji7();
    digitalWrite(lzyEN, LOW);
    dianji8();
}
}

void right_30()
 {
  digitalWrite(lzzCW, LOW); //转向控制
  digitalWrite(lzyCW, LOW);

  for (long i = 0; i <18533; i++)//18400
  {
    digitalWrite(lzzEN, LOW);
    dianji7();
    digitalWrite(lzyEN, LOW);
    dianji8();
  }  
}

void right_45()
{
  digitalWrite(lzzCW, LOW); //转向控制
  digitalWrite(lzyCW, LOW);

  for (long i = 0; i <24000; i++)//27600,28000,27680
  {
    digitalWrite(lzzEN, LOW);
    dianji5();
    digitalWrite(lzyEN, LOW);
    dianji6();
  }
}


void right_90()
{
  digitalWrite(lzzCW, LOW); //转向控制
  digitalWrite(lzyCW, LOW);

  for (long i = 0; i <52000; i++)//52200,58900+5
  {
    
    digitalWrite(lzzEN, LOW);
    dianji5();
    digitalWrite(lzyEN, LOW);
    dianji6();
  }

  
}


void right_135()
{
  digitalWrite(lzzCW, LOW); //转向控制
  digitalWrite(lzyCW, LOW);

  for (long i = 0; i <69500; i++)//80200,80090，82060-5
  {
    digitalWrite(lzzEN, LOW);
    dianji5();
    digitalWrite(lzyEN, LOW);
    dianji6();
  }
  
}


//*********************车辆停止***********************
void tingzhi(int t)
{
  //停止
  digitalWrite(lzzEN, HIGH);
  digitalWrite(lzyEN, HIGH);
  delay(t);
}


//****************************时间向前循迹************************
void sj_xunji(long n)
{
for(long i=0;i<n;i++) 
{
    //读取数字口高低电平信号至变量HD
     HD1 = digitalRead(14);   
     HD2 = digitalRead(15);   
     HD3 = digitalRead(16);   
     HD4 = digitalRead(17);   
     HD5 = digitalRead(18);   
     HD6 = digitalRead(19); 
     
     //中间在黑线
       if (HD1==0 && HD2 == 0 && HD3 ==1 && HD4 ==0 && HD5 ==0 && HD6 ==0)
    {
      v1=104;
      v2=104+a;
      go();
  

    }

  
     else if ( HD1==0 && HD2 == 0 && HD3 ==0 && HD4==1 && HD5 ==0 && HD6 ==0)
    {
      v1=104+a;
      v2=104;
      go();

    }

     else if ( HD1==0 && HD2 == 1 && HD3 ==0 && HD4==0 && HD5 ==0 && HD6 ==0)
    {
      v1=104;
      v2=104+b;
      go();

    }

     else if (  HD1==0 && HD2 == 0 && HD3 ==0 && HD4==0 && HD5 ==1 && HD6 ==0)
    {
      v1=104+b;
      v2=104;
      go();
    }

     else if ( HD1==1 && HD2 ==0 && HD3 ==0 && HD4==0 && HD5 ==0 && HD6 ==0)
    {
      v1=104;
      v2=104+c;
      go();

    }

     else if (  HD1==0 && HD2 == 0 && HD3 ==0 && HD4==0 && HD5 ==0 && HD6 ==1)
    {
      v1=104+c;
      v2=104;
      go();
    }
      
    else
    {
      v1 =104;
      v2 =104;
      go();
    }
  }
}

//****************************时间向前循迹2************************
void sj_txunji(long n)
{
for(long i=0;i<n;i++) 
{
    //读取数字口高低电平信号至变量HD
     HD1 = digitalRead(14);   
     HD2 = digitalRead(15);   
     HD3 = digitalRead(16);   
     HD4 = digitalRead(17);   
     HD5 = digitalRead(18);   
     HD6 = digitalRead(19); 
     
     //中间在黑线
       if (HD1==0 && HD2 == 0 && HD3 ==1 && HD4 ==0 && HD5 ==0 && HD6 ==0)
    {
      v1=120;
      v2=120+a;
      go();
  

    }

  
     else if ( HD1==0 && HD2 == 0 && HD3 ==0 && HD4==1 && HD5 ==0 && HD6 ==0)
    {
      v1=120+a;
      v2=120;
      go();

    }

     else if ( HD1==0 && HD2 == 1 && HD3 ==0 && HD4==0 && HD5 ==0 && HD6 ==0)
    {
      v1=120;
      v2=120+b;
      go();

    }

     else if (  HD1==0 && HD2 == 0 && HD3 ==0 && HD4==0 && HD5 ==1 && HD6 ==0)
    {
      v1=120+b;
      v2=120;
      go();
    }

     else if ( HD1==1 && HD2 ==0 && HD3 ==0 && HD4==0 && HD5 ==0 && HD6 ==0)
    {
      v1=120;
      v2=120+c;
      go();

    }

     else if (  HD1==0 && HD2 == 0 && HD3 ==0 && HD4==0 && HD5 ==0 && HD6 ==1)
    {
      v1=120+c;
      v2=120;
      go();
    }
      
    else
    {
      v1 =120;
      v2 =120;
      go();
    }
  }
}
//*******************时间后退循迹***********************
void sj_xunji_houtui(long n)
{
for(long i=0;i<n;i++) 
{
    //读取数字口高低电平信号至变量HD 
     HD7 = digitalRead(23);   //后右内
     HD8 = digitalRead(24);   //后左内
     HD9 = digitalRead(46);   //尾左
     HD10= digitalRead(48);   //尾右
   if(HD7==0&&HD8==1&&HD9==0&&HD10==0)//HD8是右
   {
       v1=105+d;
       v2=105;
       back();
   }
   else if(HD7==1&&HD8==0&&HD9==0&&HD10==0)//HD7是左
   {
      v1=105;
      v2=105+d;
      back();
   }
   else if(HD7==0&&HD8==0&&HD9==0&&HD10==1)//HD10是右
   {
      v1=105+f;
      v2=105;
      back();
   }
   else if(HD7==0&&HD8==0&&HD9==1&&HD10==0)
   {
      v1=105;
      v2=105+f;
      back();
   }
   else
   {
      v1=105;
      v2=105;
      back();
   }
   }
}
//********************时间前进减速循迹**********************
void sj_js_xunji(long n)
{
for(long i=0;i<n;i++) 
{
    //读取数字口高低电平信号至变量HD
     HD1 = digitalRead(14);   
     HD2 = digitalRead(15);   
     HD3 = digitalRead(16);   
     HD4 = digitalRead(17);   
     HD5 = digitalRead(18);   
     HD6 = digitalRead(19); 

     HHDZ = digitalRead(26);
     HHDY = digitalRead(27);
      if(HHDZ==1 &&HHDY==1)
     {
      break;
     }
     //中间在黑线
       if (HD1==0 && HD2 == 0 && HD3 ==1 && HD4 ==0 && HD5 ==0 && HD6 ==0)
    {
      v5=150;
      v6=150+a;
      go1();

    }

  
     else if ( HD1==0 && HD2 == 0 && HD3 ==0 && HD4==1 && HD5 ==0 && HD6 ==0)
    {
      v5=150+a;
      v6=150;
      go1();

    }

     else if ( HD1==0 && HD2 == 1 && HD3 ==0 && HD4==0 && HD5 ==0 && HD6 ==0)
    {
      v5=150;
      v6=150+b;
      go1();

    }

     else if (  HD1==0 && HD2 == 0 && HD3 ==0 && HD4==0 && HD5 ==1 && HD6 ==0)
    {
      v5=150+b;
      v6=150;
      go1();
    }

     else if ( HD1==1 && HD2 ==0 && HD3 ==0 && HD4==0 && HD5 ==0 && HD6 ==0)
    {
      v5=150;
      v6=150+c;
      go1();

    }

     else if (  HD1==0 && HD2 == 0 && HD3 ==0 && HD4==0&& HD5 ==0 && HD6 ==1)
    {
      v5=150+c;
      v6=150;
      go1();
    }
      
    else
    {
      v5 = 150;
      v6 = 150;
      go1();
    }
  }
}


//**********************时间后退循迹2**********************
void sj_ht_xunji2(long n)
{
  for(long i=0;i<n;i++) 
  {
     HD7 = digitalRead(23);   //后右内
     HD8 = digitalRead(24);   //后左内
     HD9 = digitalRead(46);   //尾左
     HD10= digitalRead(48);   //尾右

   
  

   if (HD7==0 && HD8==1 && HD9 ==0 && HD10==0)//左偏
     {
      v1=125+c;
      v2=125;
      back();
      }
     else if (HD7==1 && HD8==0 && HD9 ==0 &&HD10 ==0)//右偏
     {
      v1=125;
      v2=125+c;
      back();
      }
     else if(HD7==0 && HD8==0 && HD9 ==0 && HD10 ==1)
     {
       v1=125+f;
       v2=125;
       back();
     }
     else if(HD7==0 && HD8==0&& HD9==1 &&HD10==0)
     {
       v1=125;
       v2=125+f;
       back();
     }
     else
     {
      v1=125;
      v2=125;
      back();
      }
  }
  
}

//**********************前两个灰度传感器遇黑线停止结束循迹*********************
void qhd_xunji()  
{
while(1)  //无限循环循迹程序
{
    //读取数字口高低电平信号至变量HD
     HD1 = digitalRead(14);   
     HD2 = digitalRead(15);   
     HD3 = digitalRead(16);   
     HD4 = digitalRead(17);   
     HD5 = digitalRead(18);   
     HD6 = digitalRead(19); 
     
     QHDZ = digitalRead(28);
     QHDY = digitalRead(29);

      if(QHDZ==1 || QHDY==1)
     {
      break;
     }


    //中间在黑线
       if (HD1==0 && HD2 == 0 && HD3 ==1 && HD4 ==0 && HD5 ==0 && HD6 ==0)
    {
      v5=145;
      v6=145+a;
      go1();

    }

  
     else if ( HD1==0 && HD2 == 0 && HD3 ==0 && HD4==1 && HD5 ==0 && HD6 ==0)
    {
      v5=145+a;
      v6=145;
      go1();

    }

     else if ( HD1==0 && HD2 == 1 && HD3 ==0 && HD4==0 && HD5 ==0 && HD6 ==0)
    {
      v5=145;
      v6=145+b;
      go1();

    }

     else if (  HD1==0 && HD2 == 0 && HD3 ==0 && HD4==0 && HD5 ==1 && HD6 ==0)
    {
      v5=145+b;
      v6=145;
      go1();
    }

     else if ( HD1==1 && HD2 ==0 && HD3 ==0 && HD4==0 && HD5 ==0 && HD6 ==0)
    {
      v5=145;
      v6=145+c;
      go1();

    }

     else if (  HD1==0 && HD2 == 0 && HD3 ==0 && HD4==0 && HD5 ==0 && HD6 ==1)
    {
      v5=145+c;
      v6=145;
      go1();
    }
      
    else
    {
      v5 = 145;
      v6 = 145;
      go1();
    }
  }
}

//**********************前两个灰度传感器遇黑线停止结束循迹(到区域黑色)*********************//
void qhd_hxunji()  
{
while(1)  //无限循环循迹程序
{
    //读取数字口高低电平信号至变量HD
     HD1 = digitalRead(14);   
     HD2 = digitalRead(15);   
     HD3 = digitalRead(16);   
     HD4 = digitalRead(17);   
     HD5 = digitalRead(18);   
     HD6 = digitalRead(19); 
     
     QHDZ = digitalRead(28);
     QHDY = digitalRead(29);

      if(QHDZ==1 || QHDY==1)
     {
      break;
     }


    //中间在黑线
       if (HD1==0 && HD2 == 0 && HD3 ==1 && HD4 ==0 && HD5 ==0 && HD6 ==0)
    {
      v5=148;
      v6=148+a;
      go1();

    }

  
     else if ( HD1==0 && HD2 == 0 && HD3 ==0 && HD4==1 && HD5 ==0 && HD6 ==0)
    {
      v5=148+a;
      v6=148;
      go1();

    }

     else if ( HD1==0 && HD2 == 1 && HD3 ==0 && HD4==0 && HD5 ==0 && HD6 ==0)
    {
      v5=148;
      v6=148+b;
      go1();

    }

     else if (  HD1==0 && HD2 == 0 && HD3 ==0 && HD4==0 && HD5 ==1 && HD6 ==0)
    {
      v5=148+b;
      v6=148;
      go1();
    }

     else if ( HD1==1 && HD2 ==0 && HD3 ==0 && HD4==0 && HD5 ==0 && HD6 ==0)
    {
      v5=148;
      v6=148+c;
      go1();

    }

     else if (  HD1==0 && HD2 == 0 && HD3 ==0 && HD4==0 && HD5 ==0 && HD6 ==1)
    {
      v5=148+c;
      v6=148;
      go1();
    }
      
    else
    {
      v5 = 148;
      v6 = 148;
      go1();
    }
  }
}
//***************************后面两个灰度传感器遇黑线结束循迹（一般中点会用到这个）********************
void hhd_xunji()  //速度100
{
while(1)  //无限循环循迹程序
{
      //读取数字口高低电平信号至变量HD
    //读取数字口高低电平信号至变量HD
     HD1 = digitalRead(14);   
     HD2 = digitalRead(15);   
     HD3 = digitalRead(16);   
     HD4 = digitalRead(17);   
     HD5 = digitalRead(18);   
     HD6 = digitalRead(19);
      
     HHDZ = digitalRead(26);
     HHDY = digitalRead(27);


 if(HHDZ==1 && HHDY==1)
     {
      break;
     }
   
    //中间在黑线
       if (HD1==0 && HD2 == 0 && HD3 ==1 && HD4 ==0 && HD5 ==0 && HD6 ==0)
    {
      v5=150;
      v6=150+a;
      go1();

    }

  
     else if ( HD1==0 && HD2 == 0 && HD3 ==0 && HD4==1 && HD5 ==0&& HD6 ==0)
    {
      v5=150+a;
      v6=150;
      go1();

    }

     else if ( HD1==0 && HD2 == 1 && HD3 ==0 && HD4==0 && HD5 ==0 && HD6 ==0)
    {
      v5=150;
      v6=150+b;
      go1();

    }

     else if (  HD1==0 && HD2 == 0 && HD3 ==0 && HD4==0 && HD5 ==1 && HD6 ==0)
    {
      v5=150+b;
      v6=150;
      go1();
    }

     else if ( HD1==1 && HD2 ==0 && HD3 ==0 && HD4==0 && HD5 ==0 && HD6 ==0)
    {
      v5=150;
      v6=150+c;
      go1();

    }

     else if (  HD1==0 && HD2 == 0 && HD3 ==0 && HD4==0 && HD5 ==0&& HD6 ==1)
    {
      v5=150+c;
      v6=150;
      go1();
    }
      
    else
    {
      v5 = 150;
      v6 = 150;
      go1();
    }
  }
}
//************ 后退 后两个灰度传感器遇黑线结束循迹****************
void houtui_hhd_xunji()  //速度88
{
while(1)  //无限循环循迹程序
{
    //读取数字口高低电平信号至变量HD 
     HD7 = digitalRead(23);   //后右内
     HD8 = digitalRead(24);   //后左内
     HD9 =  digitalRead(46);
     HD10=  digitalRead(47);

               
     HHDZ = digitalRead(26);
     HHDY = digitalRead(27);

    if(HHDZ==1 && HHDY==1)
     {
      break;
     }
  
    if (HD7==0 && HD8==1 && HD9 ==0 && HD10==0)//左偏
     {
      v1=120+c;
      v2=120;
      back();
      }
     else if (HD7==1 && HD8==0 && HD9 ==0 &&HD10 ==0)//右偏
     {
      v1=120;
      v2=120+c;
      back();
      }
     else if(HD7==0 && HD8==0 && HD9 ==0 && HD10 ==1)
     {
       v1=120+f;
       v2=120;
       back();
     }
     else if(HD7==0 && HD8==0&& HD9==1 &&HD10==0)
     {
       v1=120;
       v2=120+f;
       back();
     }
     else
     {
      v1=120;
      v2=120;
      back();
      }
   }
}
//**********************************后退（前面两个灰度传感器）停止循迹******************************
void houtui_qhd_xunji()  //速度88
{
while(1)  //无限循环循迹程序
{
    //读取数字口高低电平信号至变量HD 
     HD7 = digitalRead(23);   //后右内
     HD8 = digitalRead(24);   //后左内
     HD9 =  digitalRead(46);
     HD10=  digitalRead(47);

               
     QHDZ = digitalRead(28);
     QHDY = digitalRead(29);

     if(QHDZ==1 || QHDY==1)
     {
      break;
     }


  
    if (HD7==0 && HD8==1 && HD9 ==0 && HD10==0)//左偏
     {
      v1=123+c;
      v2=123;
      back();
      }
     else if (HD7==1 && HD8==0 && HD9 ==0 &&HD10 ==0)//右偏
     {
      v1=123;
      v2=123+c;
      back();
      }
     else if(HD7==0 && HD8==0 && HD9 ==0 && HD10 ==1)
     {
       v1=123+f;
       v2=123;
       back();
     }
     else if(HD7==0 && HD8==0&& HD9==1 &&HD10==0)
     {
       v1=123;
       v2=123+f;
       back();
     }
     else
     {
      v1=123;
      v2=123;
      back();
      }
   }
}
