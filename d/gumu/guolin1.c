// guolin1.c By csy 98/12
#include <ansi.h>
inherit ROOM;

void create()
{
       set("short",HIG"����"NOR);
       set("long",@LONG
ת��ɽ��������һ��Ƭ���֡������ߴ�ïʢ��֦Ҷ���ܣ������ʹ�������
���ˡ�����Ҷ��ɳɳ���죬������Ⱥ�������ҡ���裬����������㡣����
��������ž��������䡣
LONG );

       set("outdoors","��Ĺ");

       set("objects", ([
               "/d/wudang/npc/yetu" : 1,
       ]));

       set("exits" ,([
             "east" : __FILE__,
             "west" : __DIR__"guolin2",
             "north" : __FILE__,
             "south" : __DIR__"guoyuan",
       ]));

       setup();
}

