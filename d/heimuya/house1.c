//room: 
inherit ROOM;
void create()
{
  set("short","����");
  set("long",@LONG
����һ�����ŵ�С��,һ���ű���ŵ�һ��Ũ���Ļ���.���й���һ����Ů���ͼ,
ͼ�л��������װ��Ů,��Ŀ����,��������.���ﻹ��һ�Ų輸,��������,������
�����廨���棬������һ�ȶ�����ͨ�����.
LONG 
     );
  set("exits",([
      "west"      : __DIR__"huoting",
      ]));
  
 set("objects", ([
		__DIR__"npc/xifang" : 1,
           ]));                                                    
// set("no_magic", 1);	
 setup();
}
void init ()
{
    if (userp(this_player()))
     this_player()->set("startroom","/d/city/wumiao");
}
