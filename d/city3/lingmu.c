//by enter xiaoya

inherit ROOM;

void create()
{
        set("short", "��Ĺ");
        set("long", @LONG
������һ���ܴ����Ĺ�����ߵ�����о��ֵֹģ���
֪����ʲô�ط����ԣ�Ҳ�������������ʹ����Щѹ�ְɣ�
�и�ɨĹ�������ﲻͣ�ذ���̾����
LONG
        );

        set("exits", ([
                "east" : __DIR__"wuhou",
        ]));
        set("objects",([
                 "/d/city3/npc/saomuren" : 1,
        ]));

        set("outdoors", "chengdu");
        setup();
        replace_program(ROOM);
}

 
