#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short","Сʯ��");
         set("long",@long
����һ��СС�İ�ʯ���š����±��̵ĺ�ˮ������΢����Զ���ĺ�����
���������������Զ����ֻԧ����һ��Ϸˮ�����ߵ��������ź����ϴ�
����΢��ʱ��ʱ��ҡ���š�
long);
// will add a npc to ask chuan
          set("outdoors","mr");
          set("exits", ([
           "south" : __DIR__"testmatou1",
             "northwest" : __DIR__"hubian1",
]));
          replace_program(ROOM);
          setup();
}
