//bye enter

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short",HIY "����·" NOR);
        set("long", 
""HIW"������һ�����ֵĴ���ϣ�������Ⱥ�����������ɵõ�\n"
"��С͵Ŷ�����Ϸ�������ʯ�"NOR"\n"

    );

        set("outdoors", "/d/chengdu");

        set("exits", ([
                "south" : __DIR__"chunxilu3",
                "north" : __DIR__"chunxilu1",
                "southwest" :__DIR__"qingshixiang1",
            ]));

        setup();
        replace_program(ROOM);       
}



