// ROOM : linjxd4.c
inherit ROOM;
void create()
{
  set("short","�ּ�С��");
  set("long",
      "������һ���������ּ�С���ϣ���������ɭɭ�����֡�һ����紵��\n"
      "����, ����ɳɳ������, ���㲻������. \n"
     );
  set("exits",([
      "south" : __DIR__"linjxd6",
      "north" : __DIR__"linjxd1",     
      "east"  : __DIR__"linjxd2",
      "west"  : __DIR__"linjxd5",
     ]));
 setup();
 replace_program(ROOM);
}
