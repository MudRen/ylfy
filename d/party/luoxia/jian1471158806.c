// a skeleton for user rooms
inherit ROOM;
void create()
{
set("short", "У��");
set("long", @LONG
��������ϼ��У������������һЩ���ڵĵĵ��������������м��Ǹ����ƽ̨���������Ϧ�����ڳ������Ե��ر�����ƽ̨��Χ���Ÿ����滨��ݶ����ǰ��ڵ����ɵ���

LONG
);
        set("exits", ([
"east" : "/d/party/luoxia/beidajie4.c",
]));
set("objects", ([
        "/clone/room/npc/tong-ren" : 1,
       ]) );
        set("owner", "bigtie7001");
        set("banghui", "luoxia");

setup();
}

