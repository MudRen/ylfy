// marry 8,14
inherit ROOM;
#include <ansi.h>


void create()
{
    set("short",HIC"��Ϣ��"NOR);
    set("long", 
"����ר��������Ϣ�Ĵ��ݡ��������һ���Ŵ���������ռ�������ӵ�һ���\n"
"�ط����ݽǺ�����ط���һЩ�ճ������þߡ�������ż������ӣ���������齫\n"
"��Χ�幩���������֡�\n\n"
);
set("exits", ([
    "north"  : __DIR__"dayuan",
]));
    
       set("sleep_room","1") ;
        set("no_fight", "1");
        set("no_steal", "1");
    setup();
    replace_program(ROOM);
}
