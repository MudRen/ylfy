
#include <ansi.h>;
#include <room.h>;
inherit ROOM;

void create()
{
     set("short", HIC"ǰ��"NOR);
     set("long", @LONG
������Ĺ�ĵ�һ��ʯ�ң��ıھ��Ǽ�Ӳ����ʯ����Ĺ�ڹ���ʮ����������
����Ϊ���ˣ�������������֮������ɪɪ��������ǰ����ʯ���Ͽ��Ų�����
�֣�zi��,�˰�ʦ�ض�������ͨ�������ң����������д��ҡ�
LONG        );

     set("exits", ([
         "north" : __DIR__"gmlw",
         "south" : __DIR__"gmqc",
         "east" : __DIR__"gmzt", 
         "out" : __DIR__"rukou",   
      ]));    

     set("item_desc", ([
         "zi" : HIR"\t\t\1.���ɵ��Ӳ�����ɱ�޹���\n"NOR
                HIR"     \t\t\2.��ʦ�󲻵������뿪��Ĺ��\n"NOR
                HIR"     \t\t\3.Ҫ���������ϳ��书�����ͬ�š�\n"NOR
      ]));
     
     setup();
}

