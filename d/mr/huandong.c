#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short","������");
         set ("long",@long
������٢��ɽׯ����书�ؼ��ĵط���һ�������������İڷ��Ÿ����鼮��
long);
         set("no_fight", 1);
         set("exits",([
             "north" : __DIR__"ytyuan",
]));
         setup();
         replace_program(ROOM);
}