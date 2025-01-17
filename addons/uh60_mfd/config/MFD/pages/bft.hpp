#define ICON_SCALE 1
#define BFT_ICON_W 1
#define BFT_ICON_H (BFT_ICON_W * 0.75)

#define BACKGROUND_RECTANGLE \
    class BlackOverlay { \
        color[] = {0.05,0.05,0.05,0.5}; \
		alpha = 0.9; \
        class BlackPoly \
        { \
            type = "polygon"; \
            width = 2; \
            points[] = { \
                { \
                    {{1.2*BFT_ICON_W*-0.02, 1.2*BFT_ICON_H*0.02}, 1}, \
                    {{1.2*BFT_ICON_W*0.02,  1.2*BFT_ICON_H*0.02}, 1}, \
                    {{1.2*BFT_ICON_W*0.02,  1.2*BFT_ICON_H*-0.02}, 1}, \
                    {{1.2*BFT_ICON_W*-0.02, 1.2*BFT_ICON_H*-0.02}, 1} \
                } \
            }; \
        };



#define BOX_CONTENT_START(COLOR) \
    class Blue { \
        color[] = COLOR; \
		alpha = 1; \
        class Line \
        { \
            type = "line"; \
            width = 2; \
            points[] = { \
				{{1.0*BFT_ICON_W*-0.02, 1.0*BFT_ICON_H*0.02}, 1}, \
				{{1.0*BFT_ICON_W*0.02,  1.0*BFT_ICON_H*0.02}, 1}, \
				{{1.0*BFT_ICON_W*0.02,  1.0*BFT_ICON_H*-0.02}, 1}, \
				{{1.0*BFT_ICON_W*-0.02, 1.0*BFT_ICON_H*-0.02}, 1}, \
				{{1.0*BFT_ICON_W*-0.02, 1.0*BFT_ICON_H*0.02}, 1},{},

#define BOX_CONTENT_END \
            }; \
        }; \
	};

#define AIRCAFT(COLOR) \
	BACKGROUND_RECTANGLE \
		BOX_CONTENT_START(COLOR) \
			AIRCRAFT_POINTS \
		BOX_CONTENT_END \
	};

#define UNKNOWN(COLOR) \
	BACKGROUND_RECTANGLE \
		BOX_CONTENT_START(COLOR) \
		BOX_CONTENT_END \
	};

#define RECTANGLE_POINTS \
	{{BFT_ICON_W*-0.02, BFT_ICON_H*0.02}, 1}, \
	{{BFT_ICON_W*0.02,  BFT_ICON_H*0.02}, 1}, \
	{{BFT_ICON_W*0.02,  BFT_ICON_H*-0.02}, 1}, \
	{{BFT_ICON_W*-0.02, BFT_ICON_H*-0.02}, 1} \

#define AIRCRAFT_POINTS \
	{{0.6*BFT_ICON_W*-0.02, 0.6*BFT_ICON_H*-0.02}, 1}, \
	{{0.6*BFT_ICON_W* 0.02, 0.6*BFT_ICON_H* 0.02}, 1}, \
	{{0.6*BFT_ICON_W* 0.02, 0.6*BFT_ICON_H*-0.02}, 1}, \
	{{0.6*BFT_ICON_W*-0.02, 0.6*BFT_ICON_H* 0.02}, 1}, \
	{{0.6*BFT_ICON_W*-0.02, 0.6*BFT_ICON_H*-0.02}, 1}


#define ANGLEX(DEG,RADIUS) (sin DEG * (BFT_ICON_W*RADIUS))
#define ANGLEY(DEG,RADIUS) (cos DEG * (BFT_ICON_H*RADIUS))
#define ANGLE(DEG,RADIUS) {ANGLEX(DEG,RADIUS), ANGLEY(DEG,RADIUS)}

#define AMORED_POINTS \
   {ANGLE(0,0.013), 1}, \
  {ANGLE(30,0.013), 1}, \
  {ANGLE(60,0.013), 1}, \
  {ANGLE(90,0.013), 1}, \
 {ANGLE(120,0.013), 1}, \
 {ANGLE(150,0.013), 1}, \
 {ANGLE(180,0.013), 1}, \
 {ANGLE(210,0.013), 1}, \
 {ANGLE(240,0.013), 1}, \
 {ANGLE(270,0.013), 1}, \
 {ANGLE(300,0.013), 1}, \
 {ANGLE(330,0.013), 1}, \
   {ANGLE(0,0.013), 1}

#define ARMORED(COLOR) \
	BACKGROUND_RECTANGLE \
		BOX_CONTENT_START(COLOR) \
			AMORED_POINTS \
		BOX_CONTENT_END \
	};

class BFT
{
    type = sensor;
    //pos[] = {"BFT_POS", {0.5,0.5},1};
    //down[] = {"BFT_DOWN", {0.5,0.5},1};
	#ifdef SENSOR_SIZE
		#undef SENSOR_SIZE
	#endif
    #define SENSOR_SIZE(numb)\
        pos[]	= {"BFT_POS", 1, BFT_CENTER,{(0+numb), 0+numb}, 1};\
        down[]	= {"BFT_DOWN", 1, BFT_CENTER,{(0-numb), 0-numb}, 1};
    SENSOR_SIZE(-0.01)

    showTargetTypes = 1+2+4+8+16+32+64+128+256+512+1024;    // RWR only
    width = 1; // default width of lines can by different in case of class XXXX used instead of arrays
    range=4000;
    sensorLineType = 3; // same as "lineType"
    sensorLineWidth = 0;
	class MissileThreat {};
	class lockingThreat {}; // locking, you're in for a bad time
	class markingThreat {}; // radar is tracking you actively
	class rwrFriendly {};
	class rwrEnemy {};
	class rwrGroup {};
	class rwrDestroyed {};
	class markedTarget {};
	class assignedTarget {};
	class target {};
	class targetFriendly {};
	class targetEnemy {};
	class targetGroup {};
	class targetDestroyed {};
	class targetGround { ARMORED(common_white) };
	class targetGroundFriendly { ARMORED(common_blue) };
	class targetGroundEnemy { ARMORED(common_red) };
	class targetGroundGroup {};
	class targetGroundDestroyed {};
	class targetGroundRemote { ARMORED(common_white) };
	class targetGroundRemoteFriendly { ARMORED(common_blue) };
	class targetGroundRemoteEnemy { ARMORED(common_red) };
	class targetGroundRemoteGroup {};
	class targetGroundRemoteDestroyed {};
	class targetLaser {};
	class targetLaserFriendly {};
	class targetLaserEnemy {};
	class targetLaserGroup {};
	class targetNVG {};
	class targetNVGFriendly {};
	class targetNVGEnemy {};
	class targetNVGGroup {};
	class targetMan {};
	class targetManFriendly {};
	class targetManEnemy {};
	class targetManGroup {};
	class targetManRemote {};
	class targetManRemoteFriendly {};
	class targetManRemoteEnemy {};
	class targetManRemoteGroup {};
	class targetAir { AIRCAFT(common_white) };
	class targetAirFriendly { AIRCAFT(common_blue) };
	class targetAirEnemy { AIRCAFT(common_red) };
	class targetAirGroup {};
	class targetAirDestroyed {};
	class targetAirRemote { AIRCAFT(common_white) };
	class targetAirRemoteFriendly { AIRCAFT(common_blue) };
	class targetAirRemoteEnemy { AIRCAFT(common_red) };
	class targetAirRemoteGroup {};
	class targetAirRemoteDestroyed {};
};
