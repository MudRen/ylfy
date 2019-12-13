
inherit ROOM;
string* npcs = ({
    "/d/shenlong/npc/boy",
    "/d/shenlong/npc/boy2",
    "/d/shenlong/npc/boy3",
    "/d/shenlong/npc/boy4",
    "/d/shenlong/npc/girl",
    "/d/shenlong/npc/boy",
    "/d/shenlong/npc/boy2",
    "/d/shenlong/npc/boy3",
    "/d/shenlong/npc/boy4",
    "/d/shenlong/npc/girl",
    "/d/shenlong/npc/girl",
});
void create()
{
    set("short", "���䳡");
    set("long", @LONG
����һ���������䳡���м�����ִ�̽���������Ů������������
�Ա�վ�ż���,������Ů,��������ʮ����,�ϵ���������ʮ��,����
ȴ��������.����һ��ɽ·ֱ��ɽ��.
LONG
    );
    set("exits", ([
        "east" : __DIR__"wuchang2",
        "west" : __DIR__"road",
        "north" : __DIR__"road2",
    ]));
    set("objects", ([
        npcs[random(sizeof(npcs))] : 1,
        npcs[random(sizeof(npcs))] : 1,
        npcs[random(sizeof(npcs))] : 1,
        npcs[random(sizeof(npcs))] : 1,
        npcs[random(sizeof(npcs))] : 1,
                "/d/shenlong/npc/old": 2+random(3),
    ]));
        setup();
    replace_program(ROOM);
}
