
inherit ROOM;
#include <ansi.h>
void create()
{
     set("short",HIC"����"NOR);
     set("long", @LONG
һƬ����������ɢ�����Ų���̯λ�������Ƶĵ���������Ҳ�д���Զ�Ĵ�
����Ū���ĸ�����Ʒ��̯����æ��ߺ�ȶ��ۡ�
LONG        );

     set("outdoors","��Ĺ");

     set("exits", ([
         "northwest" : __DIR__"gchang",
     ]));

        setup();
}

