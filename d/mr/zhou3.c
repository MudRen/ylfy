#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "С��");
        set("long", @LONG
һҶС�ۣ����Ҳ�������ߡ��˸��ˡ�һ����ʮ������������ֳֳ���
�ݣ����ڴ�β�����س��Ŵ���
LONG
        );
        set("exits",([
                "out"  :  __DIR__"anbian2",
        ]));
        setup();
}
void init()
{
       object me,room;
       me=this_player();
       room=this_object();
       message_vision(
               YEL "\n�����С�ۿ��ڰ��ߣ����´��ɡ�\n\n"NOR,me);
}
