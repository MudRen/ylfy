// By zjb@ty 2002-5-15

#include <ansi.h>
inherit ROOM; 
int do_dan(object me,object obj);
int do_yao(object me,object obj);
void create()
{
        set("short", HIY"������"NOR);
        set("long", @LONG
�����ǻ�٢��������,�����������һ������¯,
����ǿ��������Լ��ھ����Ĳ�ҩ�����Լ�����ĵ���ҩ!
LONG
        );
        set("exits", ([
			"south" : __DIR__"yaopuls",
			//"north" : __DIR__"danfang2",
        ]));
        set("no_fight",1);
        set("no_beg",1);
        set("no_steal",1);
        setup();
}

#include "danfang.h"