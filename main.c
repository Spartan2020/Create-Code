#include <kipr/wombat.h>

int main()
{
    int stop = 0;
    int x;
    int y;
    int distance = 10500;
    
    wait_for_light(0);
    shut_down_in(119);
    
    cmpc(0);
    
    
    create_connect();
    create_drive_direct(200,200);
    msleep(2400);
    create_disconnect();
    
    if (camera_open() == 1)
    {
        create_connect();
        printf("camera open successful.\n");
        msleep(3000);
        camera_update();
        
        if (get_object_count(0) == 0)
        {
          create_drive_direct(-40, 40);
          msleep(1000);
          camera_update();
            
          x = get_object_center_x(0,0);
          y = get_object_center_y(0,0);
          printf("The center of the object is (%d,%d).\n",x,y);
        }
        else
        {
            stop = 1;
            printf("did not find object.\n");
        }
        while (stop == 0)
        {
          camera_update();
          msleep(10);
           if(get_object_count(0) > 0)
            {
               if(get_object_center_x(0,0) < 75)
                {
                  create_drive_direct(-40,40);
                }
                else if (get_object_center_x(0,0) > 85)
                {
                  create_drive_direct(40,-40);
                }
                else
                {
                    stop = 1;
                    ao();
                    create_disconnect();
                    if(get_object_count(0) > 0)
                    {
                        x = get_object_center_x(0,0);
                        y = get_object_center_y(0,0);
                        printf("The center of the object is (%d,%d).\n",x,y);
                    }
                } 
             }
            }
            camera_close();
        }
    
        else
        {
            printf("camera open not successful/n");
        }
    
    create_connect();
    create_drive_direct(100,100);
    msleep(1700);
    create_disconnect();
    
    while (gmpc(0) < distance)
    {
        motor(0, 80);
    }
    ao();
    
    create_connect();
    create_drive_direct(0,180);
    msleep(1300);
    create_disconnect();
    
    while (gmpc(0) > 0)
    {
        motor(0, -80);
    }
    
    create_connect();
    create_drive_direct(0,100);
    msleep(1000);
    
    create_drive_direct(100,100);
    msleep(2000);
    
    create_drive_direct(0,100);
    msleep(4000);
    
    create_drive_direct(100,20);
    msleep(2000);
    
    create_drive_direct(20,100);
    msleep(2000);
    
    create_drive_direct(100,100);
    msleep(3000);
    
    create_disconnect();
    
    ao();
   
    return 0;
}
