//bye enter

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "���Ϻ���");
        set("long",
""HIW"���Ų������˸��Ϻ��ϣ�������Ǳ���Ϊ�ɶ�ĸ�׺ӵ�"HIC"���Ϻ�"NOR"\n"
""HIW"���������������Ʈ�����̲����𣬲ʵ��׷ɡ���ˮ�峺���ף���\n"
"��������ȥ���ӵĶ԰���Ⱥϴ�¸��ˣ�һ�����ڵ�������һ�ߴ���\n"
"�����죬����Ц���ںӵ���߶�����������Զ�����и������̶���\n"
"���������������Ҳ�·��뻭�ˡ�"NOR"\n"
        );

        set("outdoors", "/d/chengdu");

        set("exits", ([
                "southeast" : __DIR__"funanhe2",
                "northwest" : __DIR__"chunxilu3",
            ]));
        setup();
        replace_program(ROOM);       
}


