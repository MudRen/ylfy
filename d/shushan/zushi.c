//shushan2 by yushu@SHXY 2000.12
inherit ROOM;
void create ()
{
  set ("short","��ʦ��");
  set ("long", @LONG

��ɽ�ɵ���ʦ����湩������ɽ����ʦ���������ʯ��
��˵��������Ŀǰ���������������˾ƽ��ɺ���ɽ��ʥ֮��
��û�˼�������
LONG);
   set("exits", ([      
       "north" : __DIR__"shangqing",
       "south" : __DIR__"fangning",
  ]));
   set("objects", ([ 
      __DIR__"npc/jiujianxian" : 1,
      __DIR__"npc/jiantong" : 1,
       ]));

  setup();
}









