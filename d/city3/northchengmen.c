//by enter xiaoya

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "������");
        set("long",
"���Ǳ����ţ���Ϊ��"HIM"�ɶ�"NOR"������֮һ������޽����ر�\n"
"��ΰ,���ҳɶ���һ������֮��,�ΰ�����,����֮ǰ��ÿ�\n"
"����ֽ���ֵ�"HIW"�ٸ���ʾ"NOR"(gaoshi)���������Ǵ��ɽ�ˣ�һ��\n"
"��᫵�Сɽ·��ɽ�����Ѷ��ϡ�\n"
        );

        set("exits", ([
                "north" : __DIR__"dadao5",
                "south" : __DIR__"beijie1",
			//"east" : __DIR__"work2",
		   // "west" : __DIR__"work6",
        ]));
        set("item_desc",([
            "gaoshi" : "���������ط�,��ô���ڳɶ������ĺ����,\n
�����㽫�ܵ������Ĵ���----����ʮ��������\n
��! �ɶ�����ʹ--Ҷ�ࡣ\n)",
             ]));
        set("objects", ([
                "/d/city/npc/wujiang" : 2,
                "/d/city/npc/bing" : 3,
        ]));


        set("outdoors", "chengdu");
        setup();
        replace_program(ROOM);
}


