//ROM
inherit ROOM;
void create()
{
        set("short", "ɽ��");
        set("long",
             "������һ��ɽ�ȣ�������ֲ�Ų�ƺ�������ǡ�������̡���\n"
             "�����á����Ϸ���һ��С�ţ���˵��ͨ�����ϵıؾ�֮·\n"
        
        );
        set("outdoors", "heimuya");
        set("exits", ([
                "east" : __DIR__"linjxd1",
              "southwest" : "/d/heimuya/zhaoze/room1",
              "southup" : __DIR__"dating3",
                
        ]));
        set("objects",([
                __DIR__"npc/kid" : 2,
        ]));
        setup();
        replace_program(ROOM);
}
