
inherit ROOM;
#include <ansi.h>
void create()
{
     set("short",HIC"������"NOR);
     set("long", @LONG
��������ȫ���Ϊ������ʿ�ͽ������׼����ˮ����ʳ�ĵط����ɹ���ɽ
�����������˸��ڱ��γ��꣬���ڽ���ȫ��Ķ�ʢ���������һ�£���
��һ���߲ʽ�����׿Ȼ���ԡ�
LONG        );

     set("outdoors","��Ĺ");

     set("exits", ([
         "northup" : __DIR__"ztm",
         "southup" : __DIR__"ryy",
     ]));

        setup();
}

