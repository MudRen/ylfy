//room: 
inherit ROOM;
void create()
{
  set("short","����");
  set("long",
      "�����Ƿǳ����ɵĳ��ȡ�����վ����ʮ��������,����ɭ��,͸������ɱ��.\n"
 
     );
  set("exits",([
      "north" : __DIR__"dating3",
      "south" : __DIR__"chlang2",
     ]));
  set("objects",([
     __DIR__"npc/jiaotu"   :1,
	]));
 setup();
 replace_program(ROOM);
}
