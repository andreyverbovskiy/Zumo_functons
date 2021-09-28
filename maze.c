//maze 
    //IR receiverm - how to wait for IR remote commands
    // turn to left 90%
void go_forward(uint8 speed, int delay)
{
    MotorDirLeft_Write(0);      
    MotorDirRight_Write(0);    
    PWM_WriteCompare1(speed); 
    PWM_WriteCompare2(speed-7); 
    vTaskDelay(delay);
}

    void tankturn_left(uint8 speed_left, uint8 speed_right, int delay)
{
    MotorDirLeft_Write(1);      
    MotorDirRight_Write(0);    
    PWM_WriteCompare1(speed_left); 
    PWM_WriteCompare2(speed_right); 
    vTaskDelay(delay);
}

// turn to right 90%
void tankturn_right(uint8 speed_left, uint8 speed_right, int delay)
{
    MotorDirLeft_Write(0);      
    MotorDirRight_Write(1);    
    PWM_WriteCompare1(speed_left); 
    PWM_WriteCompare2(speed_right); 
    vTaskDelay(delay);
}
//short 
void go_forward(uint8 speed, int delay);    
void tankturn_right(uint8 speed_left, uint8 speed_right, int delay);    
void tankturn_left(uint8 speed_left, uint8 speed_right, int delay);

            
        
    
    
void zmain(void)
{
    //IR receiverm - how to wait for IR remote commands
void zmain(void);

    Ultra_Start();

    uint8_t button_;
    printf("\nStart\n");
    
    while(true){
        button_ = SW1_Read();
        if(button_==0){
            IR_Start();
            printf("\n\nIR test\n");
            struct sensors_ ref;
            struct sensors_ dig;
            bool led = false,loop = true, startline= true;
           //if u use count add int count=0!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
            motor_start();              // enable motor controller 
            IR_flush(); // clear IR receive buffer
            printf("Buffer cleared\n");
            
            reflectance_start();
            reflectance_set_threshold(9000, 9000, 11000, 11000, 9000, 9000); // set center sensor threshold to 11000 and others to 9000
            vTaskDelay(200);
            
                while(startline){
                    // read raw sensor values
                    reflectance_read(&ref);
                    reflectance_digital(&dig); 
                    if(dig.l3 != 1 && dig.r3 != 1){
                        motor_turn(50,50,0);       // motor forward
                        Beep(60,80);
                         print_mqtt("Zumo006/ready", "zumo");
                    }
                    
                    else{
                        motor_forward(0,0);       // Stop motors
                        startline = false;
                    }
                }
            IR_wait();  // wait for IR command
            led = !led;
            BatteryLed_Write(led);
            
            
            

    

            
            // Toggle led when IR signal is received
            while(loop)
            {   
                if(led){
                    // read raw sensor values
                   reflectance_read(&ref);
                    reflectance_digital(&dig); 
                    
                    if(dig.l3 == 1 && dig.r3 == 1){
                         motor_turn(65,50,50);       // motor forward
	                        vTaskDelay(50);
                        
                    }
           else if (Ultra_GetDistance() < 10) {   //measures the distance
           tankturn_left(50,50,50);  //makes a turn
           go_forward(50,0);  //goes forward
        }
             //sensor movements: 
            if (dig.l1==1 && dig.r1==1 && dig.r3==1 && dig.l3==1){
                motor_turn(40,40,50);
                
                printf("%5d %5d %5d %5d", ref.l1, ref.r1, ref.l3, ref.r3);
            }
            
            if (dig.l1==1 && dig.r1==1 && dig.r3==0 && dig.l3==0){
            motor_turn(55,50,50);
            printf("%5d %5d %5d %5d", ref.l1, ref.r1, ref.l3, ref.r3);
            }
            
            }
                    else if(dig.l1==1 && dig.r1==0){
                        motor_turn(50,65,0);
                        printf("%5d %5d", ref.l1, ref.r1);
                    }
                    else if(dig.l1==0 && dig.r1==1){
                        motor_turn(65,50,0);
                        printf("%5d %5d", ref.l1, ref.r1);
                    }
                    
                    else if (dig.l1 == 1 && dig.r1 == 1 && dig.l3 == 1 && dig.r3 == 0){
                        tankturn_left(120,120,100); //turns left if right sensor is 0
                        printf("%5d %5d %5d %5d", ref.l1, ref.r1, ref.l3, ref.r3);
                    }
                    
                    else if (dig.l1 == 1 && dig.r1 == 1 && dig.l3 == 0 && dig.r3 == 1){
                        tankturn_right(120,120,100); //turns left if right sensor is 0
                        printf("%5d %5d %5d %5d", ref.l1, ref.r1, ref.l3, ref.r3);
                    }
                    
                    else if (dig.l1 == 1 && dig.r1 == 1 && dig.l3 == 0 && dig.r3 == 0){
                        motor_turn(55,50,0);   //goes forward 
                        printf("%5d %5d %5d %5d", ref.l1, ref.r1, ref.l3, ref.r3);
                    }
                    else if (dig.l3 ==1 && dig.r3 ==0 && dig.l1==1 && dig.r1==1){
                       tankturn_left(120,120,100);     //turns left 
                       printf("%5d %5d %5d %5d", ref.l3, ref.r3, ref.l1, ref.r1);
                    }
                      
                        
                   
                        }
                    }
                }
                
               
            }
