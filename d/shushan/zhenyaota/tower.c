//Cracked by Roath
//【蜀山剑派】dhxy-evil 2000.7.5

#include <ansi.h>
inherit ROOM;                                                        
void create ()                                                       
{                                                                    
  set ("short", HIG"镇妖塔"NOR);                                   
  set ("long", @LONG                                                 
 高耸入云的铁塔，听说里面装着无数妖怪，旁边有一石碑(stone)。                                           
LONG);                                                          
        set("item_desc", ([
                "stone": 
HIR"镇妖塔，内囚妖魔无数，闲人勿近！\n"NOR ]) );
                                                                     
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
