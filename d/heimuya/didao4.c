//room: didao4.c
inherit ROOM;
void create()
{
  set("short","�ص���ͷ");
  set("long",
	"\n"
        "�����ǰ����һ���⣬���Ǳ��ж��죬ǰ��������еط���\n"
        
     );
  set("exits",([
      "east"   :__DIR__"didao1",
       "west"  :__DIR__"didao3",
      "south" : __DIR__"didao4",
      "southup" : __DIR__"didao6",
     ]));
   
 setup();
 replace_program(ROOM);
}
