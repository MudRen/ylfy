
inherit ROOM;
string look_gaoshi();

void create()
{
	set("short", "������");
	set("long", @LONG
�������Ÿ����ɣ���Լ�������࣬�����ĳ�����������ȭͷ���С��
�������Ŷ���Լ���ɣ���Լÿ������ʱ���ͻ��ٱ����ء���������������׽
��֮��Ĺٸ�ͨ��(gaoshi)��
LONG
	);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 1 */
     "east" : __DIR__"xidajie2",
	  //"north" : __DIR__"work5",
	 // "south" : __DIR__"work1",
      "northeast" : "/d/huanhua/podi",        	
      "westup" : "d/sdxl/outsroad1",  	
]));

        set("item_desc", ([
                "gaoshi" : (: look_gaoshi :),
        ]));

        set("objects", ([
                __DIR__"npc/wujiang" : 1,
                __DIR__"npc/bing" : 2,
        ]));
	setup();
}

string look_gaoshi()
{
        return FINGER_D->get_killer() + "\n����֪��\n������\n";
}

