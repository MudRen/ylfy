// a skeleton for user rooms
inherit ROOM;
void create()
{
set("short", "�������");
set("long", @LONG
�����ǰ������´���������һ��Ƥ��ߴ��ι������������֮��Ҳ�ǰ�������Ȩ�����������߸�����һ������������

LONG
);
        set("exits", ([
"south" : "/d/party/music/dating.c",
]));
set("objects", ([
        "/clone/room/npc/tong-ren" : 1,
       ]) );
        set("owner", "bigtie7001");
        set("banghui", "music");

setup();
}

