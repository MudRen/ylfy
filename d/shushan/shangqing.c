//shushan2 by yushu@SHXY 2000.12
inherit ROOM;
void create ()
{
  set ("short","���幬");
  set ("long", @LONG

������ɽ��ʥ�����ĵط���������һ����¯������������
�������䡣
LONG);
   set("exits", ([      
       "south" : __DIR__"zushi",
  ]));
   set("objects", ([ 
      __DIR__"npc/jiansheng" : 1,
      __DIR__"npc/jiantong" : 2,
       ]));
  setup();
}









