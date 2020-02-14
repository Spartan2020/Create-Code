#include <kipr/wombat.h>

int main()
{
    int distance = 11500;
    cmpc(0);
    
    create_connect();
    create_drive_direct(150,200);
    msleep(3000);
    create_drive_direct(0,50);
    msleep(500);
    create_stop();
        
   
    while (gmpc(0) < distance)
    {
        motor(0, 80);
    }
    ao();
    
    create_drive_direct(0,150);
    msleep(2500);
    create_stop();
    
    while (gmpc(0) > 0)
    {
        motor(0, -80);
    }
    
    ao();
    
    create_drive_direct(50, 120);
    msleep(1500);
    create_drive_direct(20,80);
    msleep(4000);
    create_drive_direct(5, 70);
    msleep(5000);
    create_drive_direct(50,100);
    msleep(3000);
                       
    return 0;
}
