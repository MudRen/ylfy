// a skeleton for user rooms
inherit ROOM;
void create()
{
set("short", "����ӵ��");
set("long", @LONG
����Զ�Ŷ�������������������ª��  ������һ�ɵ����Ľ���ζ��  �����Ϸ������ĸ���׭  ����ӵ��  ������Ȼ���Ź����Ŀռ� С�� ��ˮ ���� ʯ��  ������Ȼ�ڲ�ס���޵ļ�į�¶�

LONG
);
        set("exits", ([
"west" : "/d/party/ldgf/beidajie3.c",
]));
set("objects", ([
        "/d/new/npc/tong-ren" : 1,
       ]) );
        set("owner", "bigtie7001");
        set("banghui", "ldgf");

setup();
}

