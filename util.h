#include <kipr/wombat.h>

static int m_liftMotorPort = 3;
static int m_closeMotorPort = 0;

static int m_liftMotorPower = -500;
static int m_closeMotorPower = -750;

static int m_closeTime = 900;
static int m_liftTime = 2900;

void rlt(int right, int left, int time) {
	create_drive_direct(-right, -left);
    msleep(time);
    create_drive_direct(0,0);
}

void lift() {
	mav(m_liftMotorPort, m_liftMotorPower);
    msleep(m_liftTime);
    off(m_liftMotorPort);
}

void closeClaw() {
	mav(m_closeMotorPort, m_closeMotorPower);
    msleep(m_closeTime);
    off(m_closeMotorPort);
}

//Testing
void resetClaw() {
	mav(m_closeMotorPort, -m_closeMotorPower);
    msleep(m_closeTime);
    off(m_closeMotorPort);
    
	mav(m_liftMotorPort, -m_liftMotorPower);
    msleep(m_liftTime);
    off(m_liftMotorPort);

}

void runTo(int distance, int forward) {
	set_create_distance(0);
    if (forward > 0) {
    	while (abs(get_create_distance())<distance) {
    		create_drive_direct(150, 150);
        	msleep(10);
    	}
    }
    else {
    	while (abs(get_create_distance())<distance) {
    		create_drive_direct(-150, -150);
        	msleep(10);
    	}
    }
}

void turnTo(int angle, int right) {
    set_create_total_angle(0);
	if (right > 0) {	
    	while (abs(get_create_total_angle())<angle) {
    		create_drive_direct(150, -150);
        	msleep(10);
    	}
    }
    else {	
    	while (abs(get_create_total_angle())<angle) {
    		create_drive_direct(-150, 150);
        	msleep(10);
    	}
    }
}
