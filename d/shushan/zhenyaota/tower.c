//Cracked by Roath
//����ɽ���ɡ�dhxy-evil 2000.7.5

#include <ansi.h>
inherit ROOM;                                                        
void create ()                                                       
{                                                                    
  set ("short", HIG"������"NOR);                                   
  set ("long", @LONG                                                 
 �������Ƶ���������˵����װ���������֣��Ա���һʯ��(stone)��                                           
LONG);                                                          
        set("item_desc", ([
                "stone": 
HIR"��������������ħ���������������\n"NOR ]) );
                                                                     
    set("exits", ([ /* sizeof() == 1 */                              
  "enter" : __DIR__"entrance",                                                                              
    "west" : "/d/shushan/jindi",
                                     
]));
set("objects",([
        __DIR__"npc/lxy" : 1,
    ]));                                                                 
 
  set("outdoors", "shushan");                                                                  
  setup();                                                           
}
