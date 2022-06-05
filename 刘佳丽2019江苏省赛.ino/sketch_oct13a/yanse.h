 void yanse()
{
  g_flag = 0;
   //每获得一次被测物体RGB颜色值需时2s
   delay(4000);
   //打印出被测物体RGB颜色值
   for(int i=0; i<3; i++)
      Serial.println(int(g_array[i] * g_SF[i]));
     if (   ( (g_array[0] * g_SF[0])>170)  && ( (g_array[1] * g_SF[1])>170) && ((g_array[2] * g_SF[2])>150 ) ) //白色
     {
       k0=2;
      Serial.print("yanse=");
      Serial.println("bai");
     
      }
    else  if ( ( (g_array[0] * g_SF[0])>(g_array[1] * g_SF[1]) ) && ( (g_array[0] * g_SF[0]) > (g_array[2] * g_SF[2]) ) && (g_array[0] * g_SF[0]) >100)//红色 
     {
       k0=3;
      Serial.print("yanse=");
      Serial.println("hong");

      }
    else  if (((g_array[2] * g_SF[2])>(g_array[1] * g_SF[1]))  && ( (g_array[1] * g_SF[1])>(g_array[0] * g_SF[0]) ) ) //蓝色
     {     
      k0=5;
      Serial.print("yanse=");
      Serial.println("lan");

      
       }
     else  if (((g_array[0] * g_SF[0])<70)  && ((g_array[1] * g_SF[1])<70) && ((g_array[2] * g_SF[2])<70)) //黑色
       {
       k0=4;
      Serial.print("yanse=");
      Serial.println("hei");
     

       }       
       
      else  if ( ((g_array[2] * g_SF[2])<(g_array[1] * g_SF[1]))&&( ( (g_array[1] * g_SF[1])> (g_array[0] * g_SF[0])  ) ) &&( (g_array[1] * g_SF[1]) >65 && (g_array[1] * g_SF[1])<210 )) //绿色
       {
       k0=1;
      Serial.print("yanse=");
      Serial.println("lv");
      }
      
      else
      {
        Serial.println("No");
      
      }
       
  }



//***********************************在A处判断颜色（做任务一）*************************//
  void yanseA()
  {
     g_flag = 0;
    //每获得一次被测物体RGB颜色值需时2s
    delay(4000);
    //打印出被测物体RGB颜色值
   for(int i=0; i<3; i++)
      Serial.println(int(g_array[i] * g_SF[i]));
       if (   ( (g_array[0] * g_SF[0])>170)  && ( (g_array[1] * g_SF[1])>170) && ((g_array[2] * g_SF[2])>170) ) //白色
     {
       k0=2;
      Serial.print("yanse=");
      Serial.println("bai");
      Serial.print(k0);

      right_45();//朝向白色区域

      sj_xunji(760);//向前走
      qhd_hxunji();

      jiazi(160);//打开夹子将物块放白色区域

     sj_xunji_houtui(800);
     houtui_hhd_xunji();//到达中心位置
     sj_ht_xunji2(50);
     houtui_hhd_xunji();//试试可能，加上去的
     //sj_ht_xunji2(20);
     
      }
   else  if ( ( (g_array[0] * g_SF[0])>(g_array[1] * g_SF[1]) ) && ( (g_array[0] * g_SF[0]) > (g_array[2] * g_SF[2]) ) && (g_array[0] * g_SF[0]) >120)//红色 
     {
       k0=3;
      Serial.print("yanse=");
      Serial.println("hong");

      right_90(); //朝向红色区域

      sj_xunji(760);//向前走
      qhd_hxunji();//到达终点停止

      jiazi(160);//打开夹子


      sj_xunji_houtui(800);
      houtui_hhd_xunji();//到达中心位置
      sj_ht_xunji2(40);
      houtui_hhd_xunji();//试试可能，加上去的
      //sj_ht_xunji2(20);
  }
else  if (((g_array[2] * g_SF[2])>(g_array[1] * g_SF[1]))  && ( (g_array[1] * g_SF[1])>(g_array[0] * g_SF[0]) ) )//蓝色
     {     
      k0=5;
      Serial.print("yanse=");
      Serial.println("lan");
     
     left_180();   //朝向蓝色区域
     
     
     sj_xunji(300);//到达E点
     qhd_xunji();
     //勾取前方物块
     gouzi_servo2(87); //前方有障碍物，钩子下舵机87度角度偏置较好,角度越小钩子往桶偏
     gouzi_servo1(125);//钩子向下勾取物块
     gouzi_servo2(170);//勾子下的舵机
     gouzi_servo1(125);
     
     
     sj_xunji(200);
     qhd_xunji();//到达蓝色区域

     jiazi(160);//打开夹子，放下物块

    
     sj_xunji_houtui(260);
     tingzhi(100);
     
     gouzi_servo2(40);//下面的舵机转换方向
     gouzi_servo1(10);//舵机回到初始位置
     gouzi_servo2(130);

     jiazi(85);//夹取物块

      sj_xunji_houtui(100);
      houtui_hhd_xunji();
      sj_ht_xunji2(50);
      houtui_hhd_xunji();
      sj_ht_xunji2(40);
      houtui_hhd_xunji();
      //sj_ht_xunji2(40);
     }
    else  if (((g_array[0] * g_SF[0])<70)  && ((g_array[1] * g_SF[1])<70) && ((g_array[2] * g_SF[2])<70))//黑色
       {
       k0=4;
      Serial.print("yanse=");
      Serial.println("hei");

      right_135();//朝向黑色区域

      sj_xunji(730);//朝黑色区域走
      qhd_hxunji();//前面的灰度传感器遇黑线停止
 
      jiazi(160);//打开夹子

      sj_xunji_houtui(740);
      houtui_hhd_xunji();
      sj_ht_xunji2(50);
      houtui_hhd_xunji(); //试试可能，加上去的
      //sj_ht_xunji2(40);
       }
    else  if ( ((g_array[2] * g_SF[2])<(g_array[1] * g_SF[1]))&&( ( (g_array[1] * g_SF[1])> (g_array[0] * g_SF[0])  ) ) &&( (g_array[1] * g_SF[1]) >65 && (g_array[1] * g_SF[1])<210 )) //绿色
       {
       k0=1;
       Serial.print("yanse=");
       Serial.println("lv");
       
       sj_xunji(760);
       qhd_xunji();

       jiazi(160);//打开夹子

       sj_xunji_houtui(750);
       houtui_hhd_xunji();
       sj_ht_xunji2(50);
       houtui_hhd_xunji();//试试可能，加上去的
        //sj_ht_xunji2(40);
        
  }
       
  }
  //****************************在A0处识别颜色（就是当C处的颜色为绿色的时候）**********************
void yanseA0()
{
   g_flag = 0;
   //每获得一次被测物体RGB颜色值需时2s
   delay(4000);
   //打印出被测物体RGB颜色值
   for(int i=0; i<3; i++)
      Serial.println(int(g_array[i] * g_SF[i]));
      if (   ( (g_array[0] * g_SF[0])>170)  && ( (g_array[1] * g_SF[1])>170) && ((g_array[2] * g_SF[2])>150 ) ) //白色
     {
       k0=2;
      Serial.print("yanse=");
      Serial.println("bai");
     
     right_45();//朝白色区域走

     sj_xunji(780);
     qhd_hxunji();

     jiazi(160);//打开夹子，放物块

     
      sj_xunji_houtui(750);
      houtui_hhd_xunji();
      sj_ht_xunji2(50);
      houtui_hhd_xunji();//试试可能，加上去的
      sj_ht_xunji2(50);
     }
    else  if ( ( (g_array[0] * g_SF[0])>(g_array[1] * g_SF[1]) ) && ( (g_array[0] * g_SF[0]) > (g_array[2] * g_SF[2]) ) && (g_array[0] * g_SF[0]) >100)//红色 
     {
       k0=3;
      Serial.print("yanse=");
      Serial.println("hong");

      right_90();  //朝向红色区域

      sj_xunji(780);
      qhd_xunji();


      jiazi(165);//放下物块

      sj_xunji_houtui(700);
      houtui_hhd_xunji();
      sj_ht_xunji2(50);
      houtui_hhd_xunji(); //试试可能，加上去的
      js_back_time(4000);
}
     else  if (((g_array[2] * g_SF[2])>(g_array[1] * g_SF[1]))  && ( (g_array[1] * g_SF[1])>(g_array[0] * g_SF[0]) ) )//蓝色
     {     
      k0=5;
      Serial.print("yanse=");
      Serial.println("lan");

      left_180();//朝蓝色区域
      
      
      sj_xunji(150);
      qhd_xunji();//到达E点
      
       //勾取前方物块
     gouzi_servo2(87); //前方有障碍物，钩子下舵机87度角度偏置较好,角度越小钩子往桶偏
     gouzi_servo1(125);//钩子向下勾取物块
     gouzi_servo2(170);//勾子下的舵机
     gouzi_servo1(125);
     

     sj_xunji(120);//到达蓝色区域
     qhd_xunji();

     jiazi(160);//将物块放入颜色区域

     sj_xunji_houtui(260);
    // houtui_hhd_xunji();//物块到E处放物块

     gouzi_servo2(40);//下面的舵机转换方向
     gouzi_servo1(10);//舵机回到初始位置
     gouzi_servo2(130);

     jiazi(90);//夹取到物块

     sj_xunji_houtui(100);
     houtui_hhd_xunji();
     sj_ht_xunji2(50);
     houtui_hhd_xunji();
     js_back_time(4000);
      houtui_hhd_xunji();
     js_back_time(4000);
     }
   else  if (((g_array[0] * g_SF[0])<70)  && ((g_array[1] * g_SF[1])<70) && ((g_array[2] * g_SF[2])<70))//黑色
       {
       k0=4;
      Serial.print("yanse=");
      Serial.println("hei");

      right_135();// 朝向黑色区域

      sj_xunji(720);
      qhd_hxunji() ;

      jiazi(165);//打开夹子，放下物块

      sj_xunji_houtui(760);
      houtui_hhd_xunji();
      sj_ht_xunji2(50);
      houtui_hhd_xunji();
         sj_ht_xunji2(50);
       }
      else  if ( ((g_array[2] * g_SF[2])<(g_array[1] * g_SF[1]))&&( ( (g_array[1] * g_SF[1])> (g_array[0] * g_SF[0])  ) ) &&( (g_array[1] * g_SF[1]) >65 && (g_array[1] * g_SF[1])<210 )) //绿色
       {
       k0=1;
      Serial.print("yanse=");
      Serial.println("lv");
       
       sj_xunji(780);
       qhd_xunji();

       jiazi(160);//打开夹子

       sj_xunji_houtui(750);
       houtui_hhd_xunji();
       sj_ht_xunji2(50);
       houtui_hhd_xunji();//试试可能，加上去的
        sj_ht_xunji2(40);
       }
}
//**************************在C处判断颜色********************************//
void yanseC()
{
  g_flag = 0;
   //每获得一次被测物体RGB颜色值需时2s
   delay(4000);
   //打印出被测物体RGB颜色值
   for(int i=0; i<3; i++)
   Serial.println(int(g_array[i] * g_SF[i]));
    
      if (   ( (g_array[0] * g_SF[0])>170)  && ( (g_array[1] * g_SF[1])>170) && ((g_array[2] * g_SF[2])>150 ) ) //白色
     {
      k1=2;
     Serial.print("yanse=");
     Serial.println("bai");
     
     left_45();//朝向白色区域

     sj_xunji(760);
   
      qhd_hxunji();
      tingzhi(50);
        jiazi(120);
        tingzhi(50);
         jiazi(160);
     sj_xunji_houtui(780);
     houtui_hhd_xunji();
     sj_ht_xunji2(50);
     houtui_hhd_xunji();//试试可能，加上去的js_ht_xunji(5500);
     sj_ht_xunji2(50);
     tingzhi(80);
    sj_ht_xunji2(50);
    tingzhi(80);
     //js_back_time(5200);
     }

     
else  if ( ( (g_array[0] * g_SF[0])>(g_array[1] * g_SF[1]) ) && ( (g_array[0] * g_SF[0]) > (g_array[2] * g_SF[2]) ) && (g_array[0] * g_SF[0]) >120)//红色 
     {
      k1=3;
     Serial.print("yanse=");
     Serial.println("hong");
     
     sj_xunji(780);
     qhd_xunji();

     jiazi(160);//打开夹子

     
     sj_xunji_houtui(750);
     houtui_hhd_xunji();
      sj_ht_xunji2(50);
     houtui_hhd_xunji(); //试试可能，加上去的js_ht_xunji(5500);
      sj_ht_xunji2(50);
      tingzhi(50);
     // js_back_time(5000);
     }
       else  if (((g_array[2] * g_SF[2])>(g_array[1] * g_SF[1]))  && ( (g_array[1] * g_SF[1])>(g_array[0] * g_SF[0]) ) ) //蓝色
     {   
        k1=5;
      Serial.print("yanse=");
      Serial.println("lan");
       
       right_90();

       sj_xunji(150);
       qhd_xunji();//前灰度传感器感受到黑线
       
        //勾取前方物块
     gouzi_servo2(87); //前方有障碍物，钩子下舵机87度角度偏置较好,角度越小钩子往桶偏
     gouzi_servo1(125);//钩子向下勾取物块
     gouzi_servo2(170);//勾子下的舵机
     gouzi_servo1(130);
     
       
       sj_xunji(120);
       qhd_xunji();//到达颜色区域

       jiazi(160);//打开夹子放下物块

       sj_xunji_houtui(260);
       //houtui_hhd_xunji();//在外圈的弧上停止
       tingzhi(100);
       
       gouzi_servo2(40);//下面的舵机转换方向
       gouzi_servo1(10);//舵机回到初始位置
       gouzi_servo2(130);
 
       jiazi(90);//物块放入桶中
       
       
       sj_xunji_houtui(120);//回到中心
       houtui_hhd_xunji();
       sj_ht_xunji2(50);
       houtui_hhd_xunji();     //试试可能，加上去的 js_ht_xunji(5500);
       js_back_time(4000); 
       
       }
     else  if (((g_array[0] * g_SF[0])<70)  && ((g_array[1] * g_SF[1])<70) && ((g_array[2] * g_SF[2])<70))//黑色
     
       {
          k1=4;
    Serial.print("yanse=");
    Serial.println("hei");

    right_45();//朝向黑色区域
    
    
    sj_xunji(720);
   qhd_hxunji() ;

    jiazi(160);//打开夹子，放下物块

    sj_xunji_houtui(720);//回到中心
    houtui_hhd_xunji();// 想到的另一种办法houtui_hhd_xunji();
     sj_ht_xunji2(50);
    houtui_hhd_xunji();//试试可能，加上去的
     js_back_time(4000);

       }

     else  if ( ((g_array[2] * g_SF[2])<(g_array[1] * g_SF[1]))&&( ( (g_array[1] * g_SF[1])> (g_array[0] * g_SF[0])  ) ) &&( (g_array[1] * g_SF[1]) >65 && (g_array[1] * g_SF[1])<210 )) //绿色
       {
        k1=1;
      Serial.print("yanse=");
      Serial.println("lv");

        k1=1;
      Serial.print("yanse=");
      Serial.println("lv");
       
       left_90();//朝向绿色区域

       sj_xunji(120);//到达A点
       qhd_xunji();

       gouzi_servo2(87);  //勾取A处物块
       gouzi_servo1(125);
       gouzi_servo2(170); 
       gouzi_servo1(130); 
        
        sj_xunji(80);//到达绿色区域
        
        qhd_xunji();

        jiazi(160);//打开夹子

        sj_xunji_houtui(260);
        //houtui_hhd_xunji();// 想到的另一种办法houtui_hhd_xunji();

        gouzi_servo2(40);//下面的舵机转换方向
        gouzi_servo1(10);//舵机回到初始位置
        gouzi_servo2(130);

        jiazi(90);

        sj_xunji_houtui(120);//回到中心
        houtui_hhd_xunji();
        sj_ht_xunji2(50);
        houtui_hhd_xunji();
           sj_ht_xunji2(40);   
       }
}
   //*********************在E处判断颜色***********************
    void yanseE()
{
  g_flag = 0;
   //每获得一次被测物体RGB颜色值需时2s
   delay(4000);
   //打印出被测物体RGB颜色值
   for(int i=0; i<3; i++)
      Serial.println(int(g_array[i] * g_SF[i]));
     if (   ( (g_array[0] * g_SF[0])>170)  && ( (g_array[1] * g_SF[1])>170) && ((g_array[2] * g_SF[2])>150 ) ) //白色
     {
      k2=2;
      Serial.print("yanse=");
      Serial.println("bai");
      
      left_135();//朝向白色区域

      sj_xunji(730);
       qhd_hxunji();

      jiazi(160);//打开夹子，放下白色物块

       sj_xunji_houtui(800);//回到中心
       houtui_hhd_xunji();// 想到的另一种办法houtui_hhd_xunji();
       sj_ht_xunji2(50);
       houtui_hhd_xunji();//试试可能，加上去的
       js_back_time(4000);
        }

 else  if ( ( (g_array[0] * g_SF[0])>(g_array[1] * g_SF[1]) ) && ( (g_array[0] * g_SF[0]) > (g_array[2] * g_SF[2]) ) && (g_array[0] * g_SF[0]) >120)//红色 
     {
      k2=3;
      Serial.print("yanse=");
      Serial.println("hong");
      
      left_90();//朝向红色区域

      sj_xunji(760);
      qhd_xunji();

      jiazi(165);  //打开夹子，放下物块

      sj_xunji_houtui(800);//回到中心
      houtui_hhd_xunji();// 想到的另一种办法houtui_hhd_xunji();
      sj_ht_xunji2(50);
      houtui_hhd_xunji();//试试可能，加上去的
       js_back_time(4000);
      }
       else  if (((g_array[2] * g_SF[2])>(g_array[1] * g_SF[1]))  && ( (g_array[1] * g_SF[1])>(g_array[0] * g_SF[0]) ) ) //蓝色
     {     
      k2=5;
      Serial.print("yanse=");
      Serial.println("lan");
      
      sj_xunji(780);
      qhd_xunji();

      jiazi(165);//放下物块

      sj_xunji_houtui(800);//回到中心
      houtui_hhd_xunji();// 想到的另一种办法houtui_hhd_xunji();
      sj_ht_xunji2(50);
      houtui_hhd_xunji();//试试可能，加上去的
       sj_ht_xunji2(40);
      }
   else  if (((g_array[0] * g_SF[0])<70)  && ((g_array[1] * g_SF[1])<70) && ((g_array[2] * g_SF[2])<70)) //黑色
       {
         k2=4;
      Serial.print("yanse=");
      Serial.println("hei");

       left_45();//朝向黑色区域

      sj_xunji(720);
     qhd_hxunji() ;

      jiazi(165);  //打开夹子，放下物块

      sj_xunji_houtui(800);//回到中心
      houtui_hhd_xunji();// 想到的另一种办法houtui_hhd_xunji();
       sj_ht_xunji2(50);
      houtui_hhd_xunji();//试试可能，加上去的
      sj_ht_xunji2(40);
}
  else  if ( ((g_array[2] * g_SF[2])<(g_array[1] * g_SF[1]))&&( ( (g_array[1] * g_SF[1])> (g_array[0] * g_SF[0])  ) ) &&( (g_array[1] * g_SF[1]) >65 && (g_array[1] * g_SF[1])<210 )) //绿色
       {
     
      k2=1;
      Serial.print("yanse=");
      Serial.println("lv");

      left_180();//朝向绿色区域

      sj_xunji(150);   //到达A点
      qhd_xunji();

      gouzi_servo2(90);  //勾取A处物块
      gouzi_servo1(125);
      gouzi_servo2(170); 
      gouzi_servo1(130);
      gouzi_servo1(125);

      
      sj_xunji(150);   //到达颜色区域
      qhd_xunji(); 
             
      jiazi(165);//打开夹子

      sj_xunji_houtui(260);
      tingzhi(100);
     // houtui_hhd_xunji();// 想到的另一种办法houtui_hhd_xunji();

      gouzi_servo2(40);//下面的舵机转换方向
      gouzi_servo1(10);//舵机回到初始位置
      gouzi_servo2(130);

      jiazi(90);

       sj_xunji_houtui(120);//回到中心
       houtui_hhd_xunji();
       sj_ht_xunji2(50);
       houtui_hhd_xunji();
       js_back_time(4000);   
      } 
}
 //*********************在E0处判断颜色********************
void yanseE0()
{
  g_flag = 0;
   //每获得一次被测物体RGB颜色值需时2s
   delay(4000);
   //打印出被测物体RGB颜色值
   for(int i=0; i<3; i++)
      Serial.println(int(g_array[i] * g_SF[i]));
      if (   ( (g_array[0] * g_SF[0])>170)  && ( (g_array[1] * g_SF[1])>170) && ((g_array[2] * g_SF[2])>120 ) ) //白色
     {
      k2=2;
      Serial.print("yanse=");
      Serial.println("bai");

      left_135();//朝向白色区域

      sj_xunji(740);
      qhd_hxunji();

      jiazi(165);//打开夹子，放物块

      sj_xunji_houtui(800);//回到中心
      houtui_hhd_xunji();// 想到的另一种办法houtui_hhd_xunji();
      sj_ht_xunji2(50);
      houtui_hhd_xunji();//试试可能，加上去的
     sj_ht_xunji2(40);
      }
   else  if ( ( (g_array[0] * g_SF[0])>(g_array[1] * g_SF[1]) ) && ( (g_array[0] * g_SF[0]) > (g_array[2] * g_SF[2]) ) && (g_array[0] * g_SF[0]) >120)//红色 
     {
     k2=3;
      Serial.print("yanse=");
      Serial.println("hong");
     
      left_90();   //朝向红色区域

      sj_xunji(750);
      qhd_xunji();//到达外圈

      jiazi(165);

      sj_xunji_houtui(720);//回到中心
      houtui_hhd_xunji();// 想到的另一种办法houtui_hhd_xunji();
      sj_ht_xunji2(50);
      houtui_hhd_xunji();//试试可能，加上去的
       sj_ht_xunji2(40);
    
      }
     else  if (((g_array[2] * g_SF[2])>(g_array[1] * g_SF[1]))  && ( (g_array[1] * g_SF[1])>(g_array[0] * g_SF[0]) ) ) //蓝色
     {     
      k2=5;
      Serial.print("yanse=");
      Serial.println("lan");
      
      sj_xunji(750);
      qhd_xunji();

      jiazi(165);//放下物块

      sj_xunji_houtui(800);//回到中心
      houtui_hhd_xunji();// 想到的另一种办法houtui_hhd_xunji();
       sj_ht_xunji2(50);
      houtui_hhd_xunji();//试试可能，加上去的
     sj_ht_xunji2(40);
      }
    else  if (((g_array[0] * g_SF[0])<70)  && ((g_array[1] * g_SF[1])<70) && ((g_array[2] * g_SF[2])<70))//黑色
      {
         k2=4;
      Serial.print("yanse=");
      Serial.println("hei");

      left_45();   //朝向黑色区域

      sj_xunji(750);
      qhd_hxunji();

      jiazi(165);  //打开夹子，放下物块

      sj_xunji_houtui(800);//回到中心
      houtui_hhd_xunji();// 想到的另一种办法houtui_hhd_xunji();
      sj_ht_xunji2(50);
      houtui_hhd_xunji();//试试可能，加上去的
       sj_ht_xunji2(40);
      }
      else  if ( ((g_array[2] * g_SF[2])<(g_array[1] * g_SF[1]))&&( ( (g_array[1] * g_SF[1])> (g_array[0] * g_SF[0])  ) ) &&( (g_array[1] * g_SF[1]) >65 && (g_array[1] * g_SF[1])<210 )) //绿色
       {
     
      k2=1;
      Serial.print("yanse=");
      Serial.println("lv");

      left_180();   //朝向绿色区域


      sj_xunji(750);
      qhd_xunji();

      jiazi(165);//打开夹子，放下物块

      sj_xunji_houtui(800);//回到中心
      houtui_hhd_xunji();// 想到的另一种办法houtui_hhd_xunji();
      sj_ht_xunji2(50);
      houtui_hhd_xunji();//试试可能，加上去的 
   sj_ht_xunji2(40);
      }

      
}


//###################################任务二##################################//


void yanse2()
{
   g_flag = 0;

   //每获得一次被测物体RGB颜色值需时4s
   delay(4000);
   //打印出被测物体RGB颜色值
   for(int i=0; i<3; i++)
      Serial.println(int(g_array[i] * g_SF[i]));
    if (   ( (g_array[0] * g_SF[0])>170)  && ( (g_array[1] * g_SF[1])>170) && ((g_array[2] * g_SF[2])>150 ) ) //白色
     {
     k=2;
       Serial.print("yanse=");
       Serial.println("bai");

        if(k==k0 || k==k1 || k==k2)
      {
   left_180();      
   sj_xunji(700);   
   shengjiang(100);  //夹子上升一点

  qhd_hxunji();     
  sj_xunji(50); 
  shengjiang(120); //夹子下降一点
           
  jiazi(100);         //夹子打开一点
  //houtui_qhd_xunji();  //后退一点,到黑线停止
  shengjiang(160);   //夹子下降到底

  jiazi(90);         //夹子夹紧
  houtui_qhd_xunji();
  jiazi(160);         //夹子打开   

      sj_xunji_houtui(800);
      houtui_hhd_xunji();  
      sj_ht_xunji2(50); //颜色区域回到中心
      houtui_hhd_xunji(); 
  
      }
    
      else
      { 
         left_180();
         sj_xunji(700);   //到达颜色区域
         qhd_hxunji();     
               
         jiazi(160);         //夹子打开    
    
          sj_xunji_houtui(760);
          houtui_hhd_xunji();  
          sj_ht_xunji2(50);   //颜色区域回到中心
          houtui_hhd_xunji();  

      }
   }
      else  if ( ( (g_array[0] * g_SF[0])>(g_array[1] * g_SF[1]) ) && ( (g_array[0] * g_SF[0]) > (g_array[2] * g_SF[2]) ) && (g_array[0] * g_SF[0]) >120)  //红色 
     {
      k=3;
      Serial.print("yanse=");
      Serial.println("hong");
       if(k==k0 || k==k1 || k==k2)
      {
           left_135();
           sj_xunji(680);   
           shengjiang(60);  //夹子上升一点
    
           qhd_xunji();     
           sj_xunji(55); 
           shengjiang(110); //夹子下降一点
               
           jiazi(110);         //夹子打开一点
        
          shengjiang(160);   //夹子下降到底
    
          jiazi(90);         //夹子夹紧
          houtui_qhd_xunji();
          jiazi(160);         //夹子打开
         
         sj_xunji_houtui(760);
         houtui_hhd_xunji();  
         sj_ht_xunji2(50);   //颜色区域回到中心
         houtui_hhd_xunji(); 
  sj_ht_xunji2(50);  
      }
      
      else
      {
        left_135();
        sj_xunji(700);   //到达颜色区域
        qhd_xunji();     
           
        jiazi(160);         //夹子打开   
      
        sj_xunji_houtui(760);
        houtui_hhd_xunji();  
        sj_ht_xunji2(50);     //颜色区域回到中心
        houtui_hhd_xunji(); 
  sj_ht_xunji2(40);

      }
     }
      else  if (((g_array[2] * g_SF[2])>(g_array[1] * g_SF[1]))  && ( (g_array[1] * g_SF[1])>(g_array[0] * g_SF[0]) ) ) //蓝色
     {     
        k=5;
      Serial.print("yanse=");
      Serial.println("lan");
     if(k==k0 || k==k1 || k==k2)
      {
            left_45();      
            sj_xunji(700);   
            shengjiang(70);  //夹子上升一点
          
            qhd_hxunji();     
            sj_xunji(55); 
            shengjiang(110); //夹子下降一点
                     
            jiazi(100);         //夹子打开一点
            //back_time(1500);//后退一点
            
            shengjiang(160);   //夹子下降到底

            jiazi(90);//夹子夹紧
             houtui_qhd_xunji();
           // sj_xunji_houtui(60);
            jiazi(160);         //夹子打开 
              
             sj_xunji_houtui(780);
             houtui_hhd_xunji();  
             sj_ht_xunji2(50);   //颜色区域回到中心
             houtui_hhd_xunji();  
             sj_ht_xunji2(50);  
      }
      else 
      {
            left_45();
            sj_xunji(700);   //到达颜色区域
            qhd_xunji();     
                     
            jiazi(160);         //夹子打开   
          
             sj_xunji_houtui(780);
             houtui_hhd_xunji();  
             sj_ht_xunji2(50);     //颜色区域回到中心
             houtui_hhd_xunji(); 
             sj_ht_xunji2(50); 
       }
   }     
      
      
      else  if (((g_array[0] * g_SF[0])<70)  && ((g_array[1] * g_SF[1])<70) && ((g_array[2] * g_SF[2])<70))//黑色
       {
              k=4;
            Serial.print("yanse=");
            Serial.println("hei");
            
            if(k==k0 || k==k1 || k==k2)
            {
        left_90(); 
        sj_xunji(700);   
        shengjiang(100);  //夹子上升一点
      
        qhd_hxunji();     
        sj_xunji(50); 
        shengjiang(140); //夹子下降一点
                 
        jiazi(100);         //夹子打开一点
        //back_time(1500);   //后退一点
        shengjiang(160);   //夹子下降到底
      
        jiazi(90);         //夹子夹紧
         houtui_qhd_xunji();
        jiazi(160);         //夹子打开   
      
        sj_xunji_houtui(780);
        houtui_hhd_xunji();  
        sj_ht_xunji2(50);   //颜色区域回到中心
        houtui_hhd_xunji(); 
         sj_ht_xunji2(50);  
      }
      else
      {
        left_90(); 
        
        sj_xunji(700);   //到达颜色区域
        qhd_xunji();     
                 
        jiazi(160);         //夹子打开   

      sj_xunji_houtui(740);
      houtui_hhd_xunji();  
       sj_ht_xunji2(50); //颜色区域回到中心
      houtui_hhd_xunji();  
      sj_ht_xunji2(50);
     }
 }
       
        else  if ( ((g_array[2] * g_SF[2])<(g_array[1] * g_SF[1]))&&( ( (g_array[1] * g_SF[1])> (g_array[0] * g_SF[0])  ) ) &&( (g_array[1] * g_SF[1]) >65 && (g_array[1] * g_SF[1])<210 )) //绿色
       {
        k=1;
      Serial.print("yanse=");
      Serial.println("lv");

       if(k==k0 || k==k1 || k==k2)
      {
            right_135();
            sj_xunji(700);   
           shengjiang(100);  //夹子上升一点
        
           
            qhd_hxunji();     
            sj_xunji(50); 
            shengjiang(140); //夹子下降一点
            jiazi(100);         //夹子打开一点
          shengjiang(160);   //夹子下降到底
        
          jiazi(90);         //夹子夹紧
           houtui_qhd_xunji();
          jiazi(160);         //夹子打开   
 

        sj_xunji_houtui(700);
        houtui_hhd_xunji();  
         sj_ht_xunji2(50);   //颜色区域回到中心
        houtui_hhd_xunji(); 
        sj_ht_xunji2(50); 
      }
      else
      {
       right_135();
      
      sj_xunji(700);   //到达颜色区域
      qhd_hxunji();     
           
       jiazi(160);         //夹子打开   

        sj_xunji_houtui(720);
        houtui_hhd_xunji();  
        sj_ht_xunji2(50);    //颜色区域回到中心
        houtui_hhd_xunji(); 
        sj_ht_xunji2(40); 
       }
  }
   
}

