//room: /d/btshan/restroom.c
//restroom
inherit ROOM;
void create()
{
  set("short","��Ϣ��");
  set("long",
      "�����Ǽ���Ϣ�ң��������Ŵ󴲡�������˯���ǳ������û����\n"
  "���š����������ɵĳ��ȡ�\n"
     );
  set("exits",([
      "east" : __DIR__"huoting",
     ]));
  set("sleep_room", 1);
  set("no_fight",1);
// cset("objects", ([	
//              __DIR__"npc/dongfang" : 1,	
//c           ])); // wpk�޸���2003/7/4	
  set("no_steal",1);
 setup();
 replace_program(ROOM);
}

