
inherit ROOM;
string* npcs = ({
    "/d/shenlong/npc/boy",
    "/d/shenlong/npc/boy2",
    "/d/shenlong/npc/boy3",
    "/d/shenlong/npc/boy4",
    "/d/shenlong/npc/girl",
});
void create()
{
    set("short", "�����̴���");
    set("long", @LONG
����һ������,��ǰͻȻ�ֳ�һ������.����˶������,�����ǧ��
֮��.ֻ��һȺȺ������Ů�·���ɫ,��վ�����λ.�ࡢ�ס��ڡ���
��ɫ�Ķ�������,�����ȴ����Ů,���ϸ����̽�,ÿһ��Լ�а���.
LONG
    );
    set("exits", ([
        "south" : __DIR__"damen",
    ]));
    set("objects", ([
        npcs[random(sizeof(npcs))] : 1,
        npcs[random(sizeof(npcs))] : 1,
        "/d/city2/npc/dizi": 1,
                "/d/shenlong/npc/old": 1+random(2),
        "/d/shenlong/npc/hong": 1,
        "/d/shenlong/npc/zhang": 1,
        "/d/shenlong/npc/wugen": 1,
    ]));
    setup();
}
