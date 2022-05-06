#include <kipr/wombat.h>
#include <util.h>

int main()
{
 // wait_for_light(0);//turn on
    shut_down_in(45);
    create_connect();
    enable_servos();
    //msleep(2000);//LEGO
    rlt(100,100, 100);
    closeClaw();
    lift();
    msleep(2000);
    runTo(400, 1);
    turnTo(1000, 0);
    resetClaw();
    
    msleep(4000); //wait for lego bot to move
    runTo(400, 0);
    turnTo(1000, 0);
    msleep(1000);
   create_drive_direct(200,200);//drive forward
    msleep(2200);
    create_drive_direct(200,-200);//turn 90
    msleep(900);
    create_drive_direct(200,200);//exit starting box
    msleep(500);
    create_drive_direct(200,200);//push poms
    msleep(800);
    create_drive_direct(200,200);//push poms
    msleep(2300);
    create_drive_direct(0,0);//stop
    msleep(1500);
    create_drive_direct(200,200);//push poms
    msleep(2000);
    create_drive_direct(200,200);//push poms
    msleep(1800);
    create_drive_direct(200,-200);//turn 180
    msleep(1900);
    create_drive_direct(200,200);//push poms
    msleep(8500);
    create_drive_direct(200,-200);//turn 90
    msleep(900);
    create_drive_direct(-200,-200);//drive backwards
    msleep(2000);
    create_stop();
    printf("25\n");
    create_disconnect();
    return 0;
}
